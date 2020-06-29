#include <stdlib.h>

#include <stdio.h>
int my_strlen (char *str) {
    int len = 0;
    while (*str != '\0') {
        str++;
        len++;
    }
    return len;
}


// A function to perform division of large numbers
char* longDivision(char* number, int divisor)
{
    // As result can be very large store it in string
    char* ans = malloc(sizeof(char) * my_strlen(number));
    for(int i=0; i < my_strlen(number); i++){
        ans[i] = '\0';
    }
    int len_str= 0;

    // Find prefix of number that is larger
    // than divisor.
    int idx = 0;
    int temp = number[idx] - '0';
    while (temp < divisor)
       temp = temp * 10 + (number[++idx] - '0');

    // Repeatedly divide divisor with temp. After
    // every division, update temp to include one
    // more digit.
    while (my_strlen(number) > idx)
    {
        // Store result in answer i.e. temp / divisor
        ans[len_str] = (temp / divisor) + '0';
        len_str++;

        // Take next digit of number
        temp = (temp % divisor) * 10 + number[++idx] - '0';
    }

    // If divisor is greater than number
    if (my_strlen(ans) == 0)
        return "0";

    // else return ans
    return ans;
}

// Driver program to test longDivison()
int main()
{
    char* number = "590";
    int divisor = 5;
    char* result = longDivision(number, divisor);
    int len = my_strlen(result);
   for(int i=0; i < len; i++){
           printf("%c", result[i]);
   }


    return 0;
}
