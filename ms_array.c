# include <stdio.h>
#include <process.h>

# define max 20

int push(int stack[max], int sno, int top[], int limit[], int *data) ;

int pop(int stack[max], int sno, int top[], int bott[], int *data) ;

void main() {
    int stack[max], data, n, size, sno;
    int top[10], bott[10], limit[10];
    int i, option, reply;

//    clrscr();

    printf("\n C Language program to implement the Multiple Stacks \n");
    printf("\n How Many Stacks ? : ");
    scanf("%d", &n);
    size = max / n; //... Get Max. size for each Stack

    //... Initialize bottom for each Stack

    bott[0] = -1; //... Bottom of first Stack is -1
    for (i = 1; i < n; i++)
        bott[i] = bott[i - 1] + size;

    //... Initialize Limit of each Stack

    for (i = 0; i < n - 1; i++) //... Limit of i'th Stack is bottom of i'th Stack + Size
        limit[i] = bott[i] + size;

    //... Initialize top of each Stack
    //... Initial value for i'th Stack is equal to its Bottom Value

    for (i = 0; i < n; i++)
        top[i] = bott[i];

    //... Process the Stacks

    do {
        printf("\n C Language program to implement the Multiple Stacks \n");
        printf("\n 1. Push");
        printf("\n 2. Pop");
        printf("\n 3. Exit \n");
        printf("\n Select proper option ( 1 / 2 / 3 ) : ");
        scanf("%d", &option);
        switch (option) {
            case 1: //... Push
                printf("\n Enter a Logical Stack Number (0 to %d) : ", n - 1);
                scanf("%d", &sno);
                printf("\n Enter a Value: ");
                scanf("%d", &data);
                reply = push(stack, sno, top, limit, &data);
                if (reply == -1)
                    printf("\n Stack %d is Full", sno);
                else
                    printf("\n %d is Pushed in Stack No. %d \n", data, sno);
                break;
            case 2: //... Pop
                printf("\n Enter a Logical Stack Number (0 to %d) : ", n - 1);
                scanf("%d", &sno);
                reply = pop(stack, sno, top, bott, &data);
                if (reply == -1)
                    printf("\n Stack %d is Empty \n", sno);
                else
                    printf("\n %d is popped from Stack No. %d \n", data, sno);
                break;
            case 3:
                exit(0);
        } // switch
    } while (1);
} // main

int push(int stack[max], int sno, int top[], int limit[], int *data) {
    if (top[sno] == limit[sno])
        return (-1);
    else {
        top[sno]++;
        stack[top[sno]] = *data;
        return (1);
    } // else
} // push

int pop(int stack[max], int sno, int top[], int bott[], int *data) {
    if (top[sno] == bott[sno])
        return (-1);
    else {
        *data = stack[top[sno]];
        top[sno]--; //... Or top[sno] = top[sno] -1
        return (1);
    } // else
} // pop
