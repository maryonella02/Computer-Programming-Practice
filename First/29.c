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


char* findSum(char str1[], char str2[])
{
    // Before proceeding further, make sure length
    // of str2 is larger.

    char *pa = str1;
    char *pb = str2;

    int str1_len = (int)my_strlen(str1);
    int str2_len = (int)my_strlen(str2);


    if(str1_len > str2_len)
        swapArray(&pa, &pb);


    printf("%s", pa);
    printf("%s", pb);



    char *str = malloc( sizeof(char) * 11);
    int len_str=0;


    // Calculate length of both string
    int n1 = my_strlen(pa), n2 = my_strlen(pb);

    // Reverse both of strings
    rvereseArray(pa);
    rvereseArray(pb);

    int carry = 0;
    for (int i=0; i<n1; i++)
    {
        // Do school mathematics, compute sum of
        // current digits and carry
        int sum = ((pa[i]-'0')+(pb[i]-'0')+carry);
        str[len_str]=sum%10 + '0';
        len_str++;

        // Calculate carry for next step
        carry = sum/10;
    }

    // Add remaining digits of larger number
    for (int i=n1; i<n2; i++)
    {
        int sum = ((pb[i]-'0')+carry);
        str[len_str]=sum%10 + '0';
        len_str++;
        carry = sum/10;
    }

    // Add remaining carry
    if (carry){
        str[len_str]= carry+'0';
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

    printf("Dati dimeanisunea la numar \n");
    scanf("%d", &n);
    str1 = malloc( sizeof(char) * n);
    printf("Dati numarul");
    scanf("%s", str1);

    printf("Dati dimeanisunea la numar \n");
    scanf("%d", &n);
    str2 = malloc( sizeof(char) * n);
    printf("Dati numarul");
    scanf("%s", str2);




    char *result = findSum(str1, str2);

    int len = my_strlen(result);


    for(int i=0; i < len; i++){
            printf("%c", result[i]);
    }


    return 0;
}
