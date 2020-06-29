#include <stdio.h>
#include <stdlib.h>


void Count(int *x, int *y, int n, int *bull, int *cow)
{
    //dupa indexul flagului care il setam ca 1 cand in numarul presupus coincide cifra in numarul secret, dar nu e pe pozitia corecta
    // iar in if-ul de cows verifica daca la un anumit index este 1-adica true, incrementeaza numarul vacilor
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

void ReverseArray(int arr[], int size)
{
    for (int i = 0; i < size/2; ++i)
    {
        int temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }
}

int * toArray(int number)
// intoarce array invers
{
    int n = log10(number) + 1;
    int i;
    int *numberArray = calloc(n, sizeof(int));
    for ( i = 0; i < n; ++i, number /= 10 )
    {
        numberArray[i] = number % 10;
    }
    ReverseArray(numberArray, n);
return numberArray;
}



int array_to_num(int arr[],int n){
    char str[6][3];
    int i;
    char number[13] = {'\n'};

    for(i=0;i<n;i++) sprintf(str[i],"%d",arr[i]);
    for(i=0;i<n;i++)strcat(number,str[i]);

    i = atoi(number);
    return i;
}






int main(int argc, const char * argv[]) {
    int bull, cow;
    int secret_number[4];
    int possible_number[4];
    int possible_number_counter = 0;
    int possible_combination[9];
    int temp;

    int *temp_array;

    int resheto[12];
//    bool resheto_bool[12];
    int resheto_counter=0;




    printf("Hello to Cows & bulls!\n");
    printf("Enter secret number  ");

    for (int i = 0; i < 4; ++i)
    {
        scanf("%d",  &secret_number[i]);
    }
    printf("\n");

    printf("Lets guess it \n");
    int start_number = 1111;

    for(int i =0; i < 9; i++){
        possible_combination[i] = start_number;
        start_number += 1111;
    }

    for(int i = 0; i < 9; i++){
            //aici oprim forul cu  veridicare la boi si cifre aflam cifree  posibile
       Count(toArray(possible_combination[i]), secret_number, 4, &bull, &cow);
        printf(" Trying number %d with %d bulls and %d cows \n",possible_combination[i], bull, cow );
        if(bull == 1){
            possible_number[possible_number_counter] = i + 1;
            possible_number_counter ++;
            if(possible_number_counter == 4){
                break;
            }
        }
    }

    for (int j = 1; j <= 4; j++) {
        for (int i = 0; i < 4-1; i++) {
            temp = possible_number[i];
            possible_number[i] = possible_number[i+1];
            possible_number[i+1] = temp;
            resheto[resheto_counter] =  array_to_num(possible_number, 4);
            resheto_counter++;
    }
    }


       for(int i=0; i < resheto_counter; i++){
            temp_array = toArray(resheto[i]);

          Count(toArray(resheto[i]) , secret_number, 4, &bull, &cow);
            printf("Trying number %d with %d bulls and %d cows \n", resheto[i], bull, cow );
            if(bull == 4){
                printf("Number is : ");
                printf("%d", resheto[i]);
                break;
            }
        }



        return 0;
    }


