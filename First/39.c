#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


bool is_lucky(int n){
    int d;
    int i=1;
    int sum1=0,sum2=0;
    while (n > 0) {
        d = n % 10;
        if (i % 2 == 0)
            sum2 += d;
        else
            sum1 += d;
        n = n / 10;
        i++;
    }
    if (sum1 == sum2)
        return true;
    else
        return false;
}

int* generate_array(int n){
    int* arr;

    int start_index = pow(10,n-1);
    int final_index  = pow(10,n) - 1;

    int len= final_index - start_index + 1;

    arr = malloc(sizeof(int) * len);

    for(int i=0; i<len; i++){
        printf("%d,  ", start_index);
        arr[i] = start_index;
        start_index++;
    }

    return arr;
}



int main () {
    int n;
    int count = 0;
    scanf("%d", &n);

    int* arr = generate_array(n);
     int start_index = pow(10,n-1);
     int final_index  = pow(10,n) - 1;
     int len= final_index - start_index + 1;
    for(int i=0; i < len; i++){
        if(is_lucky(arr[i])){
            count++;
        }
    }

    printf("Number of lucky numbers %d", count);

}
