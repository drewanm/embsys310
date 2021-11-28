// RCC definitions
#define RCC_BASE 0x40021000
#define RCC_AHB2ENR (*((unsigned int*)(RCC_BASE + 0x4C)))
#define RCC_GPIOAEN_MASK 0x1 /* bit 0 of RCC_AHB2ENR set to 1 enables GPIOA */

// GPIOA definitions
#define GPIOA_BASE 0x48000000
#define GPIOA_MODER (*((unsigned int*)(GPIOA_BASE + 0x00)))
#define GPIOA_ODR   (*((unsigned int*)(GPIOA_BASE + 0x14)))

// delay function
void delay(unsigned int units);

// problem 2 functions
void func1(int arg1, int arg2, int arg3, int arg4, int arg5);
void func2(void);

int main(void)
{
    // enable the RCC clock for port A using the bit-band region
    // bit_word_addr = bit_band_base + (byte_offset x 32) + (bit_number × 4) (p.87 of ref manual)
    // where:
    // - bit_band_base = 0x42000000
    // - byte_offset = byte in the bit-band region = RCC_AHB2ENR - 0x40000000 = 0x2104C
    // - bit_number = 0 to enable GPIOA RCC clock
    *((unsigned int*)(0x42000000 + (0x2104C * 32) + (0 * 4))) = 1;
    
    // configure GPIO pin PA5 to output mode (LED1)
    // set bit[11:10] to 0b01 for pin 5, port A
    GPIOA_MODER = GPIOA_MODER & ~(1 << 11) | (1 << 10);
    
    // blink LED
    while (1)
    {
        GPIOA_ODR ^= (1 << 5);
        delay(3);
    }
    
    return 0;
}

// delay function
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

// function 1 - problem 2
void func1(int arg1, int arg2, int arg3, int arg4, int arg5)
{
}

// function 2 - problem 2
void func2(void)
{
    func1(100,101,102,103,104);
}