/*
 * setbits
 *
 * Implements the setbits() function which returns a value whose n-bits within it,
 * starting at position p, have been set to the right most bits in another value.
 */

// Includes

#include <stdbool.h>
#include <stdio.h>

/*
 * setbits(): set bits
 */

static unsigned setbits(unsigned x, unsigned p, unsigned n, unsigned y) {

    unsigned adjusted = (p + 1 - n);        // Adjusted position (accounting for size)
    unsigned mask = ~(~(unsigned)0 << n);;  // Mask [of sze n]
                                            //results in a 000...000xxxx 32-bit mask with n number of x

    return (x & ~(mask << adjusted)) | (y & mask) << adjusted;
}

/*
 * printBits(): Helper function to display the bits in an unsigned integer
 */

static void printbits(unsigned x) {

    unsigned i;

    printf("0b");

    for(i = (unsigned)(8 * sizeof(int)); i > 0; i--)
        (bool)(x & (1 << (i - 1))) ? putchar('1') : putchar('0');
}

/* Main */

int main(void) {

    printbits(setbits(0xFFFF, 7, 3, 0x0000));
    (void)putchar('\n');

    return 0;
}
