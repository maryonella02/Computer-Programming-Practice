//
//  main_30.c


#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int my_strlen (char *str) {
    int len = 0;
    while (*str != '\0') {
        str++;
        len++;
    }
    return len;
}

void swapArray( char **a, char **b )
{
    char *tmp = *a;
    *a = *b;
    *b = tmp;
}

void rvereseArray(char str[])
{
    char c;
    char *p, *q;

    p = str;
    if (!p)
        return;

    q = p + 1;
    if (*q == '\0')
        return;

    c = *p;
    rvereseArray(q);

    while (*q != '\0') {
        *p = *q;
        p++;
        q++;
    }
    *p = c;

    return;
}


// Returns true if str1 is smaller than str2.
bool isSmaller(char* str1, char* str2)
{
    // Calculate lengths of both string
    int n1 = my_strlen(str1), n2 = my_strlen(str2);

    if (n1 < n2)
    return true;
    if (n2 < n1)
    return false;

    for (int i=0; i<n1; i++)
    if (str1[i] < str2[i])
        return true;
    else if (str1[i] > str2[i])
        return false;

    return false;
}

// Function for find difference of larger numbers
char* findDiff(char* str1, char* str2)
{
    // Before proceeding further, make sure str1
    // is not smaller
    char *pa = str1;
    char *pb = str2;
    if (isSmaller(str1, str2))
        swapArray(&pa, &pb);

    // Take an empty string for storing result
    char *str = malloc( sizeof(char) * 11);
    int len_str=0;

    // Calculate length of both string
    int n1 = my_strlen(pa), n2 = my_strlen(pb);

    // Reverse both of strings
    rvereseArray(pa);
    rvereseArray(pb);

    int carry = 0;

    // Run loop till small string length
    // and subtract digit of str1 to str2
    for (int i=0; i<n2; i++)
    {
        // Do school mathematics, compute difference of
        // current digits

        int sub = ((pa[i]-'0')-(pb[i]-'0')-carry);

        // If subtraction is less then zero
        // we add then we add 10 into sub and
        // take carry as 1 for calculating next step
        if (sub < 0)
        {
            sub = sub + 10;
            carry = 1;
        }
        else
            carry = 0;

       str[len_str]=sub + '0';
        len_str++;
    }

    // subtract remaining digits of larger number
    for (int i=n2; i<n1; i++)
    {
        int sub = ((pa[i]-'0') - carry);

        // if the sub value is -ve, then make it positive
        if (sub < 0)
        {
            sub = sub + 10;
            carry = 1;
        }
        else
            carry = 0;

        str[len_str]=sub + '0';
        len_str++;
    }

    // reverse resultant string
   rvereseArray(str);

    return str;
}

// Driver code
int main()
{
    char* str1;
    char* str2;
    int n;

    printf("Dati dimensiunea la numar \n");
    scanf("%d", &n);
    str1 = malloc( sizeof(char) * n);
    printf("Dati numarul");
    scanf("%s", str1);

    printf("Dati dimensiunea la numar \n");
    scanf("%d", &n);
    str2 = malloc( sizeof(char) * n);
    printf("Dati numarul");
    scanf("%s", str2);


    char* result = findDiff(str1, str2);

    int len = my_strlen(result);


    for(int i=0; i < len; i++){
            printf("%c", result[i]);
    }

    return 0;
}

