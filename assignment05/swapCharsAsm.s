/*******************************************************************************
File name       : swapCharsAsm.s
Description     : Assembly language function for swapping two chars
*******************************************************************************/   

    EXTERN PrintString  // PrintString is defined outside this file.
    EXTERN myCstr       // myCstr defined outside this file.
    
    PUBLIC swapCharsAsm // Exports symbols to other modules
                        // Making swapCharsAsm available to other modules.
    
// Code is split into logical sections using the SECTION directive.
// Source: http://ftp.iar.se/WWWfiles/arm/webic/doc/EWARM_AssemblerReference.ENU.pdf
// SECTION  section  :type [:flag] [(align)]
//      The data section is used for declaring initialized data or constants. This data does not change at runtime
//      The bss section is used for declaring variables.
//      The text section is used for keeping the actual code.

// CODE: Interprets subsequent instructions as Arm or Thumb instructions, 
// depending on the setting of related assembler options.

// NOREORDER (the default mode) starts a new fragment in the section
// with the given name, or a new section if no such section exists.

// REORDER starts a new section with the given name.

// NOROOT means that the section fragment is discarded by the linker if
// no symbols in this section fragment are referred to. Normally, all
// section fragments except startup code and interrupt vectors should
// set this flag.

// The (2) is for the (align)
// The power of two to which the address should be aligned.
// The permitted range is 0 to 8. 
// Code aligned at 4 Bytes.

    SECTION .text:CODE:REORDER:NOROOT(2)
    
    THUMB               // Indicates THUMB code is used
                        // Subsequent instructions are assembled as THUMB instructions
    
/*******************************************************************************
Function Name   : swapCharsAsm
Description     : Calls C code to print a string; 
                  computes the division by 2 of its input argument
C Prototype     : int swapCharsAsm(*char1, *char2)
                : Where *char1 and *char2 are the characters to swap (pointers)
Parameters      : R0: *char1; R1: *char2
Return value    : R0: 0 (identical) or 1 (not identical), R1 (char1), R2 (char2)
*******************************************************************************/  
  
swapCharsAsm
    PUSH {R0,LR}        // save the input argument1 and return address
    PUSH {R1}		// save the input argument2
    LDR R0,=myCstr      // load (global) address of address of string into R0
    LDR R0,[R0]         // load address of string into R0
    BL  PrintString     // call PrintString to print the string
    POP {R1}            // restore R1
    POP {R0,LR}         // Restore R0 and LR
    LDRB R2, [R0]        // R2 = char1
    LDRB R3, [R1]        // R3 = char2
    STRB R2, [R1]        // store R2 (char1) in memory addr of char2
    STRB R3, [R0]        // store R3 (char2) in memory addr of char1
    CMP R2, R3          // compare char1 with char2, set alu status flags
    ITE EQ              // if equal (Z flag) is set in ALU, then do MOVEQ, else do MOVNE
    MOVEQ R0, #0        // store 0 in R0 if chars are equal
    MOVNE R0, #1        // else store 1 in R0
    
    BX LR               // return (with function result in R0)

    END
