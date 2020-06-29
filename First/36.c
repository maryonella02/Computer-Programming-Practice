/*Write a program for the integer division of 2 real numbers. Number of
digits - the first number - up to 1000, the second one - up to 9 digits on
both sides of the comma.*/

#import <stddef.h>

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
    int n;
    int divisor;
    char* str1;
    char* str2;

    char c;

    int first_comma_position;
    int second_comma_position;
    int final_comma;

    printf("Dati dimeanisunea la numar \n");
    scanf("%d", &n);

    str1 = malloc( sizeof(char) * n);

  printf("Dati numarul \n");
   for(int i=0; i < n; i++){
         scanf(" %c", &c);
         if(c == '.'){
             first_comma_position = i;
             scanf(" %c", &c);
         }
         str1[i] = c;
     }
    printf("dati lungimea impartitorului \n");
    scanf("%d", &n);

    printf("Dati numarul \n");
    str2 = malloc( sizeof(char) * n);
    for(int i=0; i < n; i++){
          scanf(" %c", &c);
          if(c == '.'){
              second_comma_position = i;
              scanf(" %c", &c);
          }
          str2[i] = c;
      }

    if( first_comma_position > second_comma_position){
        final_comma = first_comma_position - second_comma_position;

    } else {
        final_comma = second_comma_position - first_comma_position;
    }

    divisor = (int) strtol(str2, (char **)NULL, 10);

    char* result = longDivision(str1, divisor);

    int len = my_strlen(result);
    for(int i=0; i < len; i++){
        if(final_comma == i){
            printf(".");
        }
           printf("%c", result[i]);
    }


    return 0;
}
