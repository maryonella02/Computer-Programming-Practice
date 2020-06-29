/*
 Farmer program
 */
#include <stdio.h>
#define MAXSIZE 10

struct stack
{
    int stk[MAXSIZE];
    int top;
};
typedef struct stack STACK;
STACK s;

void push(void);
int  pop();
void display(void);

void main ()
{
    int desiredSum;

    int choice;
    int option = 1;

    s.top = -1;

    printf ("Farmer's budget\n");
    printf ("------------------------------------------\n");
    printf ("Enter desired sum: \n");
    scanf("%d", &desiredSum);
    while (option)
    {
        printf ("------------------------------------------\n");
        printf ("      1    -->    Add envelope               \n");
        printf ("      2    -->    Remove envelopes till desired sum               \n");
        printf ("      3    -->    View budget               \n");
        printf ("      4    -->    Exit           \n");
        printf ("------------------------------------------\n");

        printf ("Enter your choice\n");
        scanf    ("%d", &choice);
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop(desiredSum);
            break;
        case 3:
            display();
            break;
        case 4:
            return;
        }
        fflush (stdin);
        printf ("Do you want to continue(Type 0 or 1)?\n");
        scanf    ("%d", &option);
    }
}

void push ()
{
    int num;
    if (s.top == (MAXSIZE - 1))
    {
        printf ("Stack is Full\n");
        return;
    }
    else
    {
        printf ("Enter the element to be pushed\n");
        scanf ("%d", &num);
        s.top = s.top + 1;
        s.stk[s.top] = num;
    }
    return;
}
/*  Function to take envelopes till the desired sum is reached*/
int pop (int desiredSum)
{       int num;
        int sum=0;
        num = s.stk[s.top];

    while(sum < desiredSum){
        if (s.top == - 1)
            {
                printf ("No budget\n");
                return (s.top);
            }

        if(sum == desiredSum)
            return sum;

        printf ("In envelope is = %d\n", s.stk[s.top]);
        s.top = s.top - 1;
        sum=sum+num;

    }


    printf ("Was taken %d\n", sum);
    return(num);
}
/*  Function to display the status of the budget*/
void display ()
{
    int i;
    if (s.top == -1)
    {
        printf ("Stack is empty\n");
        return;
    }
    else
    {
        printf ("\n The curent budget is \n");
        for (i = s.top; i >= 0; i--)
        {
            printf ("%d\n", s.stk[i]);
        }
    }
    printf ("\n");
}
