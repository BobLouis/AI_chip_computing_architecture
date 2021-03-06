#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n"
#define BYTE_TO_BINARY(byte)         \
    (byte & 0x8000 ? '1' : '0'),     \
        (byte & 0x4000 ? '1' : '0'), \
        (byte & 0x2000 ? '1' : '0'), \
        (byte & 0x1000 ? '1' : '0'), \
        (byte & 0x0800 ? '1' : '0'), \
        (byte & 0x0400 ? '1' : '0'), \
        (byte & 0x0200 ? '1' : '0'), \
        (byte & 0x0100 ? '1' : '0'), \
        (byte & 0x80 ? '1' : '0'),   \
        (byte & 0x40 ? '1' : '0'),   \
        (byte & 0x20 ? '1' : '0'),   \
        (byte & 0x10 ? '1' : '0'),   \
        (byte & 0x08 ? '1' : '0'),   \
        (byte & 0x04 ? '1' : '0'),   \
        (byte & 0x02 ? '1' : '0'),   \
        (byte & 0x01 ? '1' : '0')
void lfsr_calculate(uint16_t *reg)
{

    /* YOUR CODE HERE */
    // *reg = (*reg >> 1);
    *reg = (*reg >> 1) | (((*reg & 1) ^ ((*reg >> 1) & 1) ^ ((*reg >> 3) & 1) ^ ((*reg >> 12) & 1)) << 15);
}

int main()
{
    uint16_t reg = 0x1;
    for (int i = 0; i < 256; ++i)
    {
        printf(BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(reg));
        lfsr_calculate(&reg);
    }
}