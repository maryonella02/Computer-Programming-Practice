#include <stdio.h>
#include <stdlib.h>
char *list;
const char *line = "--------+--------------------\n";
int len = 0;

int firstAttempt()
{

   int n[ 9 ]={1111,2222,3333,4444,5555,6666,7777,8888,9999};
int j;


   /* output each array element's value */
   for (j = 0; j < 9; j++ ) {
      printf("Element[%d] = %d\n", j, n[j] );
   }



    return 0;
}
char* get_digits(char *ret)
{

    printf("Enter secret number \n");
	scanf("%s", ret);

	return ret;
}


void Count(int *x, int *y, int n, int *bull, int *cow)
{
   int i, flag[10] = {0};
   *bull = *cow = 0;
   for (i = 0; i < n; i++)
      if (x[i] == y[i])
         (*bull)++;
      else
         flag[x[i]] = 1;
   for (i = 0; i < n; i++)
      if (flag[y[i]])
         (*cow)++;
}

int main()
{
  int n[ 9 ]={1111,2222,3333,4444,5555,6666,7777,8888,9999};
int j;


   /* output each array element's value */
   for (j = 0; j < 9; j++ ) {
      printf("Element[%d] = %d\n", j, n[j] );
   }

   int x[4] = {1,2,3,4},  y[4] = n[j];

   int bull, cow;
   Count(x, y, 4, &bull, &cow);
   printf("bull = %d cow = %d\n", bull, cow);
   return 0;
}
