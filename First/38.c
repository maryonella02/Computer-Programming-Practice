
#include <stdio.h>
int findTrailingZeros(int n)
{
    // Initialize result
    int count = 0;

    // Keep dividing n by powers of
    // 5 and update count
    for (int i = 5; n / i >= 1; i *= 5)
        count += n / i;

    return count;
}

// Driver Code
int main()
{
    int n;
    printf("dati numarul \n");
    scanf("%d", &n);
    printf("numarul de zerouri terminale sunt : %d", findTrailingZeros(n));
    return 0;
}
