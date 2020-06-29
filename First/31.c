// program to multiply two numbers represented
// as strings.

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


// Multiplies str1 and str2, and prints result.
char* multiply(char num1[], char num2[])
{
    int len1 = my_strlen(num1);
    int len2 = my_strlen(num2);
    if (len1 == 0 || len2 == 0)
    return "0";

    // will keep the result number in vector
    // in reverse order
    int* result = malloc(sizeof(int) * (len1 + len2));
    for(int i=0; i < len1 + len2; i++)
        result[i] = 0;



    // Below two indexes are used to find positions
    // in result.
    int i_n1 = 0;
    int i_n2 = 0;

    // Go from right to left in num1
    for (int i=len1-1; i>=0; i--)
    {
        int carry = 0;
        int n1 = num1[i] - '0';

        // To shift position to left after every
        // multiplication of a digit in num2
        i_n2 = 0;

        // Go from right to left in num2
        for (int j=len2-1; j>=0; j--)
        {
            // Take current digit of second number
            int n2 = num2[j] - '0';

            // Multiply with current digit of first number
            // and add result to previously stored result
            // at current position.
            int sum = n1*n2 + result[i_n1 + i_n2] + carry;

            // Carry for next iteration
            carry = sum/10;

            // Store result

            result[i_n1 + i_n2] = sum % 10 ;

            i_n2++;
        }

        // store carry in next cell
        if (carry > 0){
            result[i_n1 + i_n2] += carry;

        }

        // To shift position to left after every
        // multiplication of a digit in num1.
        i_n1++;
    }

    // ignore '0's from the right
    int i = len1 + len2 - 1;
    while (i>=0 && result[i] == 0)
    i--;

    // If all were '0's - means either both or
    // one of num1 or num2 were '0'
    if (i == -1)
    return "0";

    // generate the result string
    char* s = malloc(sizeof(char) * (len1 + len1));
    int len_str = 0;


    while (i >= 0){
        s[len_str] = result[i--] + '0';

        len_str++;
    }

    return s;
}

// Driver code
int main()
{

    char* str1;
    char* str2;
    int n;



    printf("Dati dimeanisunea la numar \n");
    scanf("%d", &n);

    str1 = malloc( sizeof(char) * n);

    printf("Dati numarul \n");
    scanf("%s", str1);


    printf("Dati dimeanisunea la numar \n");
    scanf("%d", &n);
    str2 = malloc( sizeof(char) * n);
    printf("Dati numarul\n");
    scanf("%s", str2);

    char *result = multiply(str1, str2);

    int len = my_strlen(result);



    for(int i=0; i < len; i++){
            printf("%c", result[i]);
    }
    return 0;
}
