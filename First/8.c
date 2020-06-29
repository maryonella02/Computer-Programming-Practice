#include <stdlib.h>
#include <stdio.h>
int n, b, rest, rs, A[100], i ,k;
long power(int a, int b)  // a la puterea b
{
   int pow=1;
   while (b>0)   ///while(b)
   {
            pow = pow * a;   // pow*=a;
            b--;
   }
   return pow;
}
int main(){
     printf("n = "); scanf("%d", &n);
    printf("b = "); scanf("%d", &b);
    while (n)
    {
            rest = n % 10;
            n = n / 10;
            A[i] = rest;
            i++;
            k++;
    }
    for ( i = 0; i < k; i++)
    {
    rs = rs + (A[i] * power(b,i));
    }
    printf("Raspuns = %d", rs);
}
