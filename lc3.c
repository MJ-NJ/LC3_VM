#include <stdio.h>
#include <stdint.h>
#include <signal.h>
#include <Windows.h>
#include <conio.h>  // _kbhit
 
#define MEMORY_MAX (1 << 16) //65536 --> 16 Bit --> 2^(16) Spaces
 
uint16_t memory[MEMORY_MAX]; // Memory Array 

// Registers --> all 16 Bits -> R0-R7 - General Purpose , PC - Program Counter , COND - Condition Flag
enum {
    R_R0 = 0,
    R_R1, 
    R_R2,
    R_R3,
    R_R4,
    R_R5,
    R_R6,
    R_R7,
    R_PC,
    R_COND,
    R_COUNT,
};

uint16_t reg[R_COUNT]; // Register Count

// OPCODES --> 16 Operation Codes for the available functions
enum{
    OP_BR = 0,  // Branch
    OP_ADD,     // Add
    OP_LD,      // Load
    OP_ST,      // Store
    OP_JSR,     // Jump Register
    OP_AND,     // Bitwise AND
    OP_LDR,     // Load Register
    OP_STR,     // Store Register
    OP_RTI,     // Unused
    OP_NOT,     // Bitwise Not
    OP_LDI,     // Load Indirect
    OP_STI,     // Store Indirect
    OP_JMP,     // Jump
    OP_RES,     // Reserve (unused)
    OP_LEA,     // Load Effective Address
    OP_TRAP,    // Execute Trap
};

// Condition Flags to execute calculations
enum{
    FL_POS = 1 << 0, // P -> 1 bit
    FL_ZRO = 1 << 1, // Z -> 2 bit
    FL_NEG = 1 << 2, // N -> 4 bit
};

int main(int argc, const char* argv[]){
    
    // @{Load Arguments}
    // Show usage string
    if(argc < 2){
        printf("lc3[image-file1]...\n");
        exit(2);
    }
    for(int j=1;j<argc;++j){
        if(!read_image(argv[j])){
            printf("failed to load image: %s\n",argv[j]);
            exit(1);
        }
    }

    // @{Setup}

    /* since exactly one condition flag should be set at any given time, set the Z flag */
    reg[R_COND] = FL_ZRO;

    /* set the PC to starting position */
    /* 0x3000 is the default */
    enum{ PC_START = 0x3000};
    reg[R_PC] = PC_START;

    int running = 1;
    while(running){

        // FETCH the values
        uint16_t instr = mem_read(reg[R_PC]++);
        uint16_t op = instr >> 12;

    // Make a switch case of all the possible operations
        switch(op){
            case OP_ADD:
                //@{ADD}
                break;
            case OP_AND:
                //@{AND}
                break;
            case OP_NOT:
                //@{NOT}
                break;
            case OP_BR:
                //@{BR}
                break;
            case OP_JMP:
                //@{JMP}
                break;
            case OP_JSR:
                //@{JSR}
                break;
            case OP_LD:
                //@{LD}
                break;
            case OP_LDI:
                //@{LDI}
                break;
            case OP_LDR:
                //@{LDR}
                break;
            case OP_LEA:
                //@{LEA}
                break;
            case OP_ST:
                //@{ST}
                break;
            case OP_STI:
                //@{STI}
                break;
            case OP_STR:
                //@{STR}
                break;
            case OP_TRAP:
                //@{TRAP}
                break;
            case OP_RES:
            case OP_RTI:
            default:
                //@{BAD OPCODE}
                break;
        }
    }
    // SHUTDOWN
}