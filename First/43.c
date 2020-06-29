//A program which rearranges the digits of a number in order to get the
//greatest possible number. Don’t use an array or char[] as input
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int my_strlen (char *str) {
    int len = 0;
    while (*str != '\0') {
        str++;
        len++;
    }
    return len;
}

// Function to print the maximum number
int printMaxNum(int num)
{
    // hashed array to store count of digits
    int count[10] = {0};

    // Converting given number to string

    char* str = malloc(sizeof(char)*(int)log10(num));
    sprintf(str, "%d", num);


    // Updating the count array
    for (int i=0; i<my_strlen(str); i++)
        count[str[i]-'0']++;

    // result is to store the final number
    int result = 0, multiplier = 1;

    // Traversing the count array
    // to calculate the maximum number
    for (int i = 0; i <= 9; i++)
    {
        while (count[i] > 0)
        {
            result = result + (i * multiplier);
            count[i]--;
            multiplier = multiplier * 10;
        }
    }

    // return the result
    return result;
}

// Driver program to test above function
int main()
{
    int num = 38293167;
    printf("%d", printMaxNum(num));
    return 0;
}
