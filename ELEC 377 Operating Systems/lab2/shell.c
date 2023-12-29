#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <pwd.h>
#include <ctype.h>
#include <sys/wait.h>
#include <sys/stat.h>

//+
// File:	shell.c
//
// Pupose:	This program implements a simple shell program. It does not start
//		processes at this point in time. However, it will change directory
//		and list the contents of the current directory.
//
//		The commands are:
//		   cd name -> change to directory name, print an error if the directory doesn't exist.
//		              If there is no parameter, then change to the home directory.
//		   ls -> list the entries in the current directory.
//			      If no arguments, then ignores entries starting with .
//			      If -a then all entries
//		   pwd -> print the current directory.
//		   exit -> exit the shell (default exit value 0)
//				any argument must be numeric and is the exit value
//
//		if the command is not recognized an error is printed.
//-

#define CMD_BUFFSIZE 1024
#define MAXARGS 10

int splitCommandLine(char * commandBuffer, char* args[], int maxargs);
int doInternalCommand(char * args[], int nargs);
int doProgram(char * args[], int nargs);

//+
// Function:	main
//
// Purpose:	The main function. Contains the read
//		eval print loop for the shell.
//
// Parameters:	(none)
//
// Returns:	integer (exit status of shell)
//-

int main() {

    char commandBuffer[CMD_BUFFSIZE];
    // note the plus one, allows for an extra null
    char *args[MAXARGS+1];

    // print prompt.. fflush is needed because
    // stdout is line buffered, and won't
    // write to terminal until newline
    printf("%%> ");
    fflush(stdout);

    while(fgets(commandBuffer,CMD_BUFFSIZE,stdin) != NULL){
        //printf("%s",commandBuffer);

	// remove newline at end of buffer
	int cmdLen = strlen(commandBuffer);
	if (commandBuffer[cmdLen-1] == '\n'){
	    commandBuffer[cmdLen-1] = '\0';
	    cmdLen--;
            //printf("<%s>\n",commandBuffer);
	}

	// split command line into words.(Step 2)

<<<<<<< HEAD
	int numargs = splitCommandLine(commandBuffer, args, MAXARGS);

	// add a null to end of array (Step 2)

	args[numargs] = NULL;
=======
	int nargs = splitCommandLine(commandBuffer, args, MAXARGS);

	// add a null to end of array (Step 2)

	args[nargs] = NULL;
>>>>>>> c6064e136c6e80991ca60568441582575ba835cf

	// debugging
	//printf("%d\n", nargs);
	//int i;
	//for (i = 0; i < nargs; i++){
	//   printf("%d: %s\n",i,args[i]);
	//}
	// element just past nargs
	//printf("%d: %x\n",i, args[i]);

        // check if 1 or more args (Step 3)
        if (nargs >= 1) {
            int output = doInternalCommand(args, nargs);
            if (output != 1) {
                int outputProg = doProgram(args, nargs);
                if (outputProg != 1) {
                    printf("Error: Command '%s' not found \n", args[0]);
                }
            }
        }
        
        // TODO: if one or more args, call doInternalCommand  (Step 3)
        
        // TODO: if doInternalCommand returns 0, call doProgram  (Step 4)
        
        // TODO: if doProgram returns 0, print error message (Step 3 & 4)
        // that the command was not found.

	// print prompt
	printf("%%> ");
	fflush(stdout);
    }
    return 0;
}

////////////////////////////// String Handling (Step 1) ///////////////////////////////////

//+
// Function:	skipChar
//
// Purpose:	This function skips over a given char in a string
//		For security, will not skip null chars.
//
// Parameters:
//    charPtr	Pointer to string
//    skip	character to skip
//
// Returns:	Pointer to first character after skipped chars
//		ID function if the string doesn't start with skip,
//		or skip is the null character
//-

char * skipChar(char * charPtr, char skip){
    // TODO: contents of function
    // TODO: replace null with proper value
    if(skip=='\0'){
        return charPtr;
    }

<<<<<<< HEAD
    while(skip==*charPtr){
=======
    while(*charPtr == skip){
>>>>>>> c6064e136c6e80991ca60568441582575ba835cf
        charPtr++;
        if(skip==NULL){
            return charPtr;
        }
    }
    return charPtr;
}

//+
// Funtion:	splitCommandLine
//
// Purpose:	This function splits a string into an array of strings, which is passed
//          as an argument. The space characters are replaced with null characters 
//          to ensure the strings terminate. 
//
// Parameters:
//    commandBuffer string from command line that will be split
//    args list with each argument
//    marargs maximum number of arguments 
//
// Returns:	Number of arguments (< maxargs).
//
//-

int splitCommandLine(char * commandBuffer, char* args[], int maxargs){
   // TODO: Contents of function
    int numargs = 0;
    char * currentpos;
    currentpos = skipChar(commandBuffer, ' ');
    while (*currentpos != '\0'){
        currentpos = skipChar(currentpos, ' ');
        if(numargs!=maxargs){
            args[numargs] = currentpos;
            numargs++;
            currentpos = strchr(currentpos, ' ');
        }else{
            fprintf(stderr, "Error: Max Arguements Exceeded");
            return numargs;
        }
        if (currentpos==NULL){return numargs;}
        *currentpos = '\0';
        currentpos++;
    }
   // TODO: return proper value
return numargs;
}

////////////////////////////// External Program  (Note this is step 4, complete doeInternalCommand first!!) ///////////////////////////////////

// list of directorys to check for command.
// terminated by null value
char * path[] = {
    ".",
    "/usr/bin",
    NULL
};

//+
// Funtion:	doProgram
//
// Purpose:	TODO: add description of funciton
//
// Parameters:
//    args	
//    nargs	
//
// Returns	int
//		1 = found and executed the file
//		0 = could not find and execute the file
//-

int doProgram(char * args[], int nargs){
  // find the executable
  // TODO: add body.
  // Note this is step 4, complete doInternalCommand first!!!
  for (int i = 0; i < sizeof(path)/sizeof(path[0]); i++) {
    int size = sizeof(path[i]);
    int lenCurrent = strlen(args[0]);
    char spacePath = malloc(lenCurrent + size + 2); 

    sprintf(spacePath, "%s/%s\0", path[i], args[0]);

    struct stat *headerStat;
    if (stat(spacePath, headerStat) == 0); {
        if (S_ISREG(headerStat -> st_mode)) {

        }
        if (headerStat -> st_mode & S_IXUSR) {
            break; 
        }
    }

    if (spacePath == NULL) {
        return 0; 
    }
    else {
        if (fork()>0) {
            execve(spacePath, args, NULL); 
            free(spacePath);
            wait(NULL); 
        }
        else {
            execve(spacePath, args, NULL);
            free(spacePath); 
        }
    }
  }
  //struct stat the_stats;
  return 1;

}

////////////////////////////// Internal Command Handling (Step 3) ///////////////////////////////////

// define command handling function pointer type
typedef void(*commandFunc)(char * args[], int nargs);

// associate a command name with a command handling function
struct cmdStruct{
   char 	* cmdName;
   commandFunc 	cmdFunc;
};

// prototypes for command handling functions
// TODO: add prototype for each comamand function

void exitFunc(char * args[], int nargs);
void lsFunc(char * args[], int nargs);
void cdFunc(char * args[], int nargs);
void pwdFunc(char * args[], int nargs);

// list commands and functions
// must be terminated by {NULL, NULL} 
// in a real shell, this would be a hashtable.
struct cmdStruct commands[] = {
   // TODO: add entry for each command
   {"exit", exitFunc},
   {"ls", lsFunc},
   {"cd", cdFunc},
   {"pwd", pwdFunc},
   { NULL, NULL}		// terminator
};

//+
// Function:	doInternalCommand
//
// Purpose:	TODO: add description
//
// Parameters:
//    args	list with each argument 
//    nargs size of args
//
// Returns	int
//		1 = args[0] is an internal command
//		0 = args[0] is not an internal command
//-

int doInternalCommand(char * args[], int nargs){
    // TODO: function contents (step 3)
    for (int i = 0; commands[i].cmdName != NULL; i++){
        if (strcmp(commands[i].cmdName, args[0])==0){
            commands[i].cmdFunc(args, nargs);
<<<<<<< HEAD
            return 1
=======
            return 1;
>>>>>>> c6064e136c6e80991ca60568441582575ba835cf
        }
    }
    return 0;
}

///////////////////////////////
// comand Handling Functions //
///////////////////////////////

// TODO: a function for each command handling function
// goes here. Also make sure a comment block prefaces
// each of the command handling functions.

<<<<<<< HEAD
//Exits
void exitFunc(char * args[], int numargs){
    exit(0);
}

//EXPLAIN
void pwdFunc(char * args[], int numargs){
=======

//+
// Function:	exitFunc
//
// Purpose:	This function exits the shell when called
//
// Parameters:
//    args	list with each argument 
//    nargs size of args
//
// Returns: Nothing
//-

//The "exit" command. Exits the shell
void exitFunc(char * args[], int nargs){
    exit(0);
}

//+
// Function:	pwdFunc
//
// Purpose:	This function returns the current working directory when called
//
// Parameters:
//    args	list with each argument 
//    nargs size of args
//
// Returns: Nothing
//-

//The "pwd" command. Returns the current working directory
void pwdFunc(char * args[], int nargs){
>>>>>>> c6064e136c6e80991ca60568441582575ba835cf
    char * cwd = getcwd(NULL, 0);
    if (cwd == NULL){
        printf("Error in cwd");
        return;
    }
    printf("%s\n", cwd);
    free(cwd);
}

<<<<<<< HEAD
//COMMENT EXPLANATION HERE
void cdFunc(char * args[], int numargs) {
    char* newdirec;
    if (numargs == 1){
=======
//+
// Function:	cdFunc
//
// Purpose:	This function changes the working directory to a 
//          given agument or the home directory if no
//          argument is given
//
// Parameters:
//    args	list with each argument 
//    nargs size of args
//
// Returns: Nothing
//-

//The 'cd' command. Changes the working directory to given argument.
//If no target given, changes working directory to home directory
void cdFunc(char * args[], int nargs) {
    char* newdirec;
    if (nargs == 1){
>>>>>>> c6064e136c6e80991ca60568441582575ba835cf
        struct passwd *pw = getpwuid(getuid());
        if (pw == NULL){
            printf("Error: could not get name of the home directory");
            return;
        }
<<<<<<< HEAD
        newdirec = pw->pw_dir;
    } else {
        newdirec = args[1];
    }
    int outChdir = chdir(newdirec);
    if(outChdir != 0){
        printf("Error: couldn't change to target directory"):
    }

    //something
    int checkDot(const struct dirent * d){
=======
        else {
        newdirec = chdir(pw->pw_dir);
        }
    } else if (nargs ==2) {
        newdirec = chdir(args[1]);
    }
    int outChdir = chdir(newdirec);
    if(outChdir != 0){
        printf("Error: couldn't change to target directory");
    }
}

//+
// Function:	checkDot
//
// Purpose:	used later for lsfunc to see if a file name has 
//          a dot or not
//
// Parameters:
//    dirent
//
// Returns: Nothing
//-

int checkDot(const struct dirent * d){
>>>>>>> c6064e136c6e80991ca60568441582575ba835cf
        if (d->d_name[0] == '.'){
            return 0;
        }
        return 1;
    }

<<<<<<< HEAD
    //something
    void lsFunc(char * args[], int numargs){
        if(numargs == 2 && strcmp(args[1], "-a") == 0){
            struct dirent ** namelist;
            int numEnts = scandir(".",&namelist,NULL,NULL);
            for(int i = 0; i < numEnts; i++){
                
            }
        }
    }

}

=======
//+
// Function:	lsFunc
//
// Purpose:	This function lists the files in the current directory 
//
// Parameters:
//    args	list with each argument 
//    nargs size of args
//
// Returns: Nothing
//-

//The ls command. Lists files in current directory
void lsFunc(char * args[], int nargs){
        if(nargs == 2 && strcmp(args[1], "-a") == 0){
            struct dirent ** namelist;
            int numEnts = scandir(".",&namelist,NULL,NULL);
            for(int i = 0; i < numEnts; i++){
                char* names = namelist[i] -> d_name; 
                printf("%s \n", names);
            }
        }
        else if (nargs == 1) {
            struct dirent ** namelist;
            int numEnts = scandir(".",&namelist,checkDot,NULL);
            for(int j = 0; j < numEnts; j++){
                char* names = namelist[j] -> d_name; 
                printf("%s \n", names);
            }
        }
        else {
            fprintf(stderr, "Not valid, too many arguments for ls \n");
        }
}
>>>>>>> c6064e136c6e80991ca60568441582575ba835cf
