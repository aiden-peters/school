#!/bin/bash

# ELEC377 - Operating System
# Lab 4 - Shell Scripting, ps.sh
# Program Description: Display a list of running processes with specified options.

# Initialize variables
showRSS="no"
showComm="no"
showCommand="no"
showGroup="no"

# Parse command line arguments
while [[ $# -gt 0 ]]; do
    case $1 in
        -rss)
            showRSS="yes"
            shift
            ;;
        -comm)
            showComm="yes"
            shift
            ;;
        -command)
            showCommand="yes"
            shift
            ;;
        -group)
            showGroup="yes"
            shift
            ;;
        *)
            echo "Error: Unknown option '$1'"
            exit 1
            ;;
    esac
done

# Check for conflicting options
if [[ "$showComm" == "yes" && "$showCommand" == "yes" ]]; then
    echo "Error: Cannot use both -comm and -command options"
    exit 1
fi

# Function to get username from UID
get_username() {
    grep -E "^$1:" /etc/passwd | cut -d: -f1
}

# Function to get group name from GID
get_groupname() {
    grep -E "^$1:" /etc/group | cut -d: -f1
}

# Process each running process
for process_dir in /proc/[0-9]*; do
    if [[ -d "$process_dir" ]]; then
        # Extract process information
        pid=$(grep '^Pid' "$process_dir/status" | sed -e 's/[^0-9]*//g')
        cmdline=$(tr -d '\0' < "$process_dir/cmdline")
        rss=$(grep '^VmRSS' "$process_dir/status" | sed -e 's/[^0-9]*//g')
        uid=$(grep '^Uid' "$process_dir/status" | sed -e 's/^Uid:\s*\([0-9]*\).*/\1/')
        gid=$(grep '^Gid' "$process_dir/status" | awk '{print $2}')
        comm=$(grep '^Name' "$process_dir/status" | cut -d: -f2 | tr -d '[:space:]')

        # Handle empty cmdline for kernel processes
        if [ -z "$cmdline" ]; then
            cmdline=$comm
            rss=0
        fi

        # Get username and groupname
        username=$(cut -d : -f 1,3 /etc/passwd | grep -w "$uid" | cut -d : -f 1)
        groupname=$(cut -d : -f 1,3 /etc/group | grep -w "$gid" | cut -d : -f 1)

        # Output format using printf
        printf "%-5s %-15s" "$pid" "$username"

        # Print optional columns
        if [[ "$showGroup" == "yes" ]]; then
            printf "%-17s" "$groupname" 
        fi

        if [[ "$showRSS" == "yes" ]]; then
            printf "%-10s" "$rss"
        fi

        if [[ "$showComm" == "yes" ]]; then
            printf "%-15s" "$comm"
        fi

        if [[ "$showCommand" == "yes" ]]; then
            printf "%s" "$cmdline"
        fi

        # Newline for the next process
        printf "\n"
    fi
done > "/tmp/tmpPs$$.txt"

# Print headers
printf "%-5s %-15s" "PID" "USER"

if [[ "$showGroup" == "yes" ]]; then
    printf "%-10s" "GROUP"
fi

if [[ "$showRSS" == "yes" ]]; then
    printf "%-10s" "RSS"
fi

if [[ "$showComm" == "yes" ]]; then
    printf "%-15s" "COMM"
fi

if [[ "$showCommand" == "yes" ]]; then
    printf "%s" "COMMAND"
fi

printf "\n"

# Sort and display the results
sort -n "/tmp/tmpPs$$.txt"
rm "/tmp/tmpPs$$.txt"
