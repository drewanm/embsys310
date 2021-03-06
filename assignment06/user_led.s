/*******************************************************************************
File name       : user_led.s
Description     : Assembly language function for controlling the user LED
*******************************************************************************/   

    EXTERN delay                    // delay() is defined outside this file

    PUBLIC control_user_led1        // Exports symbols to other modules

// Code is split into logical sections using the SECTION directive.
// Source: http://ftp.iar.se/WWWfiles/arm/webic/doc/EWARM_AssemblerReference.ENU.pdf
// SECTION  section  :type [:flag] [(align)]
//      The data section is used for declaring initialized data or constants. This data does not change at runtime
//      The bss section is used for declaring variables. The syntax for declaring bss section is -
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
Function Name   : control_user_led1
Description     : - Uses Peripheral registers at base 0x4800.0000
                    to set GPIOA Output Data Register.
                  - Calls another assembly function delay to insert
                    delay loop

C Prototype     : void control_user_led(uint8_t state, uint32_t duration)
                : Where state indicates if LED should be on or off.
Parameters      : R0: uint8_t state
                : R1: uint32_t duration
Return value    : None
*******************************************************************************/  

GPIOA_BASE  EQU 0x48000000
GPIOA_ODR   EQU 0x14
GPIOA_BIT_5 EQU 0x20

control_user_led1
    // <TODO> Implement function in assembly
    MOV R2, #0x48000000 // put gpioa_base into r2
    ADD R2, R2, #0x14 // calculate addr of ODR for gpioa using base+offs
    LDR R3, [R2] // load GPIOA_ODR from memory into r3
    
    MVN R12, #0x20 // = ~GPIOA_BIT_5 for AND operation to turn off led
    
    CMP R0, #0 // compare r0 to 0 (off). if 0, then off. else, on
    ITE EQ // if equal, then ORREQ, else ANDNE
    ANDEQ R3, R3, R12 // clear bit -- GPIOA_ODR &= ~GPIOA_BIT_5
    ORRNE R3, R3, #0x20 // set bit -- GPIOA_ODR |= GPIOA_BIT_5
    
    STR R3, [R2] // store modified value to memory
    
    MOV R0, R1 // move r1 to r0 for delay input arg
    PUSH {LR} // store lr to stack
    BL delay // delay function
    POP {LR} // restore link register
    
    BX LR // return
    END
