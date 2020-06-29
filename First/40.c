/*Write a program which determines the index of splitting a linear array
into 2 parts of sums that are close to each other*/
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>


int findSplitPoint(int arr[], int n)
{
    int leftSum = 0 ;

    // traverse array element
    for (int i = 0; i < n; i++)
    {
        // add current element to left Sum
        leftSum += arr[i] ;

        // find sum of rest array elements (rightSum)
        int rightSum = 0 ;
        for (int j = i+1 ; j < n ; j++ )
            rightSum += arr[j] ;

        // split point index
        if (leftSum == rightSum)
            return i+1 ;
    }

    // if it is not possible to split array into
    // two parts
    return -1;
}



// driver program
int main()
{
    int arr[] = {1 , 2, 1, 2, 2 };
    int n = 5;
    int split_point = findSplitPoint(arr, n);
    printf("%d", split_point);
    return 0;
}
