#include <stdlib.h>
#include <stdio.h>
char s[100],intreg[100], real[100];
int main()
{
    scanf("%s", &s);
    printf("%s", s);
    int i = 0;
    while (s[i]!='.')
    {
        intreg[i]=s[i];
        i++;
    }

    printf("\n%s", intreg);
    printf("\n%s", real);
return 0;
}
