/*Scrieti un program pentru scaderea a 2 numere reale. Numarul de cifre -
pana la 1000 de ambele parti ale virgulei
Write a program for the division of 2 real numbers. Number of digits -
up to 1000 on both sides of the comma*/

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
char* multiply(char* num1, char* num2)
{
    int len1 = my_strlen(num1);
    int len2 = my_strlen(num2);
    if (len1 == 0 || len2 == 0)
    return "0";

    // will keep the result number in vector
    // in reverse order
    char* result = malloc(sizeof(char) * (len1 + len2));
    for(int i=0; i < len1 + len2; i++)
        result[i] = '0';



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
            int sum = n1*n2 + atoi(&result[i_n1 + i_n2]) + carry;

            // Carry for next iteration
            carry = sum/10;

            // Store result
            char c =(sum % 10) + '0';
            result[i_n1 + i_n2] = c ;

            i_n2++;
        }

        // store carry in next cell
        if (carry > 0){
            int temp = atoi(&result[i_n1 + i_n2]);
            temp = temp + carry;
            result[i_n1 + i_n2] = temp + '0';
        }

        // To shift position to left after every
        // multiplication of a digit in num1.
        i_n1++;
    }

    // ignore '0's from the right
    int i = my_strlen(result) - 1;
    while (i>=0 && atoi(&result[i]) == 0)
    i--;

    // If all were '0's - means either both or
    // one of num1 or num2 were '0'
    if (i == -1)
    return "0";

    // generate the result string
    char* s = malloc(sizeof(char) * len1 + len1);
    int len_str = 0;


    while (i >= 0){
        s[len_str] = result[i--];
        len_str++;
    }

    return s;
}

int main()
{

    char* str1;
    char* str2;
    int n;

    char c;
    int first_comma_position;
    int second_comma_position;
    int final_comma;


    printf("Dati dimeanisunea la numar \n");
    scanf("%d", &n);

    str1 = malloc( sizeof(char) * n);
    for(int i=0; i < n; i++){
        scanf(" %c", &c);
        if(c == '.'){
            first_comma_position = i;
            scanf(" %c", &c);
        }
        str1[i] = c;
    }

     first_comma_position = n - first_comma_position;

    printf("Dati dimeanisunea la numar \n");
    scanf("%d", &n);
    str2 = malloc( sizeof(char) * n);
    printf("Dati numarul\n");
     for(int i=0; i < n; i++){
             scanf(" %c", &c);
           if(c == '.'){
               second_comma_position = i;
                 scanf(" %c", &c);
           }
           str2[i] = c;
       }

       second_comma_position = n - second_comma_position;

    final_comma = first_comma_position + second_comma_position;

    char *result = multiply(str1, str2);

    int len = my_strlen(result);

    final_comma = len - final_comma;


    for(int i=0; i < len; i++){
        if( i == final_comma){
            printf(".");
        }
            printf("%c", result[i]);
    }
    return 0;
}
