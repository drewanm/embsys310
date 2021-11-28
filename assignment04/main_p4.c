#include <stdint.h>
#include <stdio.h>

int endianness(void);

int main(void)
{
    int result = endianness();
    
    if (1 == result)
    {
        printf("Big Endian!\n");
    }
    else if (0 == result)
    {
        printf("Little Endian!\n");
    }
    else if (-1 == result)
    {
        printf("Error...\n");
    }
    return 0;
}

// function to return endianness of a system.
// 1 = big endian, 0 = little endian, -1 = error
int endianness(void)
{
    // a value of 0xABCD will be stored in memory (increasing address) as:
    // big endian: ABCD
    // little endian: CDAB
    
    // store a 2 byte unsigned int 0xABCD
    uint16_t val = 0xABCD;
    uint16_t* ptr = &val;
    
    // typecast the ptr to 1 byte and check the value
    if ((*(uint8_t*)(ptr)) == 0xAB)
    {
        // big endian
        return 1;
    }
    else if ((*(uint8_t*)(ptr)) == 0xCD)
    {
        // little endian
        return 0;
    }
    else
    {
        // error
        return -1;
    }
}