/*
   This program asks the user to enter a positive integer number.
   Then it counts how many bits are 0 in the binary representation of that number.
   The result is printed to the screen.
   The input is assumed to be a valid unsigned int (positive number only).
*/

#include <stdio.h>

/* This function counts the number of 0 bits in the binary form of the number */
int count_zero_bits(unsigned int bits) {
    int count = 0;
    int num_of_bits = sizeof(bits) * 8;  /* Number of bits in the unsigned int type */

    /* Go over each bit and count if it's 0 */
    while (num_of_bits) {
        if ((bits & 1) == 0) {
            count++;
        }
        bits >>= 1;       /* Shift right to check the next bit */
        num_of_bits--;    /* One bit less to check */
    }

    return count;
}

int main(void) {
    unsigned int number;  /* The number entered by the user */
    
    /* Friendly message asking the user for input */
    printf("Please enter a positive whole number:\n");

    /* Read the input number */
    scanf("%u", &number);

    /* Call the function and print the result */
    printf("The number of 0 bits is: %d\n", count_zero_bits(number));

    return 0;
}
