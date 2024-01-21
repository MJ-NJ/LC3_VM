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
    Fl_NEG = 1 << 2, // N -> 4 bit
};