/* 
   This program checks if a string is a palindrome.
   A palindrome is a word or sentence that reads the same
   from left to right and from right to left, 
   ignoring spaces (but not ignoring uppercase/lowercase).
   The user types a string, and the program prints:
   1 if it's a palindrome, or 0 if it's not.
*/

#include <stdio.h>    /* for input and output functions */
#include <string.h>   /* for string functions like strlen and strcspn */
#include <ctype.h>    /* for checking spaces with isspace */

int palindrome(char s[]) {
    int i = 0, j = strlen(s) - 1;

    /* Check if the string is a palindrome, ignoring spaces */
    while (i < j) {
        while (i < j && isspace(s[i]))  /* Skip space from the left */
            i++;
        while (i < j && isspace(s[j]))  /* Skip space from the right */
            j--;
        if (s[i] != s[j])  /* If letters are not the same, not a palindrome */
            return 0;
        i++;
        j--;
    }

    return 1;  /* The string is a palindrome */
}

int main(void) {
    char input[1000];  /* A string to hold the user's input */
    int result;        /* To store the result from the palindrome check */

    /* Ask the user to type a string */
    printf("Hello! Please enter a string to check if it's a palindrome:\n");

    /* Read the input from the user */
    if (fgets(input, sizeof(input), stdin) != NULL) {
        /* Remove the newline character from the end of the string */
        input[strcspn(input, "\n")] = '\0';

        /* Show the user what they typed */
        printf("The entered string is: \"%s\"\n", input);

        /* Check if the string is a palindrome and print the result */
        result = palindrome(input);
        printf("%d\n", result);  /* 1 if palindrome, 0 if not */

        return result;  /* Return 1 if palindrome, 0 if not */
    } else {
        /* If reading input failed, print an error */
        printf("Error reading input.\n");
    }

    return 0;  /* In case of error */
}
