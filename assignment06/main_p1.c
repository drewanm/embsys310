#include "stm32l475xx.h"
#include "delay.h"

//void delay(unsigned int units);

int main()
{
    // enable IO port clock A
    RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN_Msk;
    
    // configure GPIO pin PA5 to output mode (LED1)
    // set bit[11:10] to 0b01 for pin 5, port A
    GPIOA->MODER &= ~GPIO_MODER_MODE5_1; // bit 11 (clear)
    GPIOA->MODER |= GPIO_MODER_MODE5_0; // bit 10 (set)
    
    while (1)
    {
        // turn on
        GPIOA->ODR |= GPIO_ODR_OD5;
        delay(100000);
        
        // turn off
        GPIOA->ODR &= ~GPIO_ODR_OD5;
        delay(100000);
    }
    return 0;
}
    
/*void delay(unsigned int units)
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
}*/
