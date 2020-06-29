/*Program de verificare dacă un tablou n x n este un pătrat latin (are aceleași
sume pe linii, coloane, diagonale)
A program which checks whether an array of size n x n is a latin square
(contains the same sum among its lines, columns, diagonals)*/
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int SumRow (int *A, int N)
{
    int sum=0;
    for (int j = 0; j < N; j++)
    sum+=A[j];
    return sum;
}

int SumCol (int **A, int N, int j)
{
    int sum=0;
    for (int i = 0; i < N; i++)
    sum+=A[i][j];
    return sum;
}

int main()
{
    int N, sum1;
    bool k=true;
    printf("introduceti dimensiunea matricii N=");
    scanf("%d", &N);

    int **A = (int **) malloc(N * sizeof(int *)); ;
    for (int i = 0; i < N; i++)
         A[i]=(int *) malloc(N * sizeof(int));

    printf("Enter %d", N*N);
    printf(" integer elements:\n");
    for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
        scanf("%d", &A[i][j]);

    for (int i = 0; i < N; i++){ // цикл вывода инф. сообщений (можно убрать)
    printf("row ");
    printf("%d", i+1);
    printf(": sum = %d", SumRow(A[i],N));
    printf("\n");
    }

    for (int j = 0; j < N; j++){ // цикл вывода инф. сообщений (можно убрать)
        printf("col %d", j+1 );
        printf(": sum = %d", SumCol(A,N,j));
        printf("\n");
    }

    sum1=SumRow(A[0],N);
    for (int i = 1; i < N; i++)
    if (SumRow(A[i],N)!=sum1) {k=false;break;}

    if(k)
    for (int j = 0; j < N; j++)
    if (SumCol(A,N,j)!=sum1) {k=false;break;}

    if (k) printf("YES\n");
    else printf("NO\n");


return 0;
}
