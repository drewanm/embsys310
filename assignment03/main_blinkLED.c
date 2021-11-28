// main.c file for blinking LED1 (PA5).

// RCC definitions
#define RCC_BASE 0x40021000
#define RCC_AHB2ENR (*((unsigned int*)(RCC_BASE + 0x4C)))
#define RCC_GPIOAEN_MASK 0x1 /* bit 0 of RCC_AHB2ENR set to 1 enables GPIOA */

// GPIOA definitions
#define GPIOA_BASE 0x48000000
#define GPIOA_MODER (*((unsigned int*)(GPIOA_BASE + 0x00)))
#define GPIOA_ODR   (*((unsigned int*)(GPIOA_BASE + 0x14)))

void delay(void)
{
    volatile unsigned int i = 0;
    while (i < 100000)
    {
        i++;
    }
}

int main(void)
{
    // enable IO port clock A
    RCC_AHB2ENR |= RCC_GPIOAEN_MASK;
    
    // configure GPIO pin PA5 to output mode
    // set bit[11:10] to 0b01 for pin 5, port A
    GPIOA_MODER = GPIOA_MODER & ~(1 << 11) | (1 << 10);
    
    while (1)
    {
        /* ----- Problem 1 start ----- */
/*
        // turn on LED
        // set GPIOA_ODR[pin#] to 1 (output data register)
        GPIOA_ODR |= (1 << 5);
        
        // delay
        delay();
        
        // turn off LED
        // set GPIOX_ODR[pin#] to 1 (output data register)
        GPIOA_ODR &= ~(1 << 5);
        
        // delay
        delay();
*/
        /* ----- Problem 1 end----- */
        
        /* ----- Problem 2 start ----- */

        // 0 XOR 0 = 0
        // 1 XOR 0 = 1 -- XOR with 0 will not toggle the bit
        // 0 XOR 1 = 1
        // 1 XOR 1 = 0 -- XOR with 1 will toggle the bit
        // toggle GPIOX_ODR[pin#]
        GPIOA_ODR ^= (1 << 5);
        
        // delay
        delay();

        /* ----- Problem 2 end ----- */
    }
    
    return 0;
}