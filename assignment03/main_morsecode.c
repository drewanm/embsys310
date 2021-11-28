// main.c file for Morse Code application.

// RCC definitions
#define RCC_BASE 0x40021000
#define RCC_AHB2ENR (*((unsigned int*)(RCC_BASE + 0x4C)))
#define RCC_GPIOAEN_MASK 0x1 /* bit 0 of RCC_AHB2ENR set to 1 enables GPIOA */

// GPIOA definitions
#define GPIOA_BASE 0x48000000
#define GPIOA_MODER (*((unsigned int*)(GPIOA_BASE + 0x00)))
#define GPIOA_ODR   (*((unsigned int*)(GPIOA_BASE + 0x14)))

// Morse code definitions
// dot = 1 unit of time, dash = 3 units of time
// space between parts of same letter = 1 unit of time
// space between letters = 3 units of time
// space between words = 7 units of time
// letters/numbers given as combination of dots (1) and dashes(3)
#define MRS_SP_IN_LETTER 1
#define MRS_SP_BTWN_LETTERS 3
#define MRS_SP_BTWN_WORDS 7
#define MRS_A 13
#define MRS_B 3111
#define MRS_C 3131
#define MRS_D 311
#define MRS_E 1
#define MRS_F 1131
#define MRS_G 331
#define MRS_H 1111
#define MRS_I 11
#define MRS_J 1333
#define MRS_K 313
#define MRS_L 1311
#define MRS_M 33
#define MRS_N 31
#define MRS_O 333
#define MRS_P 1331
#define MRS_Q 3313
#define MRS_R 131
#define MRS_S 111
#define MRS_T 3
#define MRS_U 113
#define MRS_V 1113
#define MRS_W 133
#define MRS_X 3113
#define MRS_Y 3133
#define MRS_Z 3311
#define MRS_1 13333
#define MRS_2 11333
#define MRS_3 11133
#define MRS_4 11113
#define MRS_5 11111
#define MRS_6 31111
#define MRS_7 33111
#define MRS_8 33311
#define MRS_9 33331
#define MRS_0 33333

void delay(unsigned int units)
{
    volatile unsigned int i = 0;
    for (int j = 0; j < units; j++)
    {
        i = 0;
        while (i < 100000)
        {
            i++;
        }
    }
}

void displayMorseLetter(unsigned int letter_code)
{
    for (unsigned int divisor = 10000; divisor > 0; divisor /= 10)
    {
        if (letter_code / divisor != 0)
        {
            // turn on LED
            GPIOA_ODR |= (1 << 5);
            
            // wait HIGH based on delay
            delay(letter_code / divisor);
            
            // turn off LED
            GPIOA_ODR &= ~(1 << 5);
            
            // if not last part of letter, delay space between part of same letter
            if(divisor != 1)
            {
               delay(MRS_SP_IN_LETTER);
               
               // modify letter_code tp get rid of most sig. digit
               letter_code %= divisor;
            }
        }
    }
}

int main(void)
{
    // enable IO port clock A
    RCC_AHB2ENR |= RCC_GPIOAEN_MASK;
    
    // configure GPIO pin PA5 to output mode (LED1)
    // set bit[11:10] to 0b01 for pin 5, port A
    GPIOA_MODER = GPIOA_MODER & ~(1 << 11) | (1 << 10);
    
    // make sure LED is off
    GPIOA_ODR &= ~(1 << 5);
    
    // display letters of name
    while (1)
    {
        // A
        displayMorseLetter(MRS_A);
        delay(MRS_SP_BTWN_LETTERS);
        
        // N
        displayMorseLetter(MRS_N);
        delay(MRS_SP_BTWN_LETTERS);
        
        // D
        displayMorseLetter(MRS_D);
        delay(MRS_SP_BTWN_LETTERS);
        
        // R
        displayMorseLetter(MRS_R);
        delay(MRS_SP_BTWN_LETTERS);
        
        // E
        displayMorseLetter(MRS_E);
        delay(MRS_SP_BTWN_LETTERS);
        
        // W
        displayMorseLetter(MRS_W);
        
        // repeat
        delay(MRS_SP_BTWN_WORDS);
    }
    
    
    return 0;
}