#include<stdio.h>
#include <process.h>

#define size 10
int stack[size], top = 0, del, del2, item, top2 = size / 2, l = size / 2;

void push();

void pop();

void pop2();

void display();

void push2(int del);

void main() {
    int c;
    printf("\n1-push\n2-pop\n3-Display\n4-Exit");
    do {
        printf("\nEnter your choice:");
        scanf("%d", &c);
        switch (c) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                printf("\nContens are \t");
                display();
                break;
            case 4:
                exit(0);

            default:
                printf("\nInvalid choice");
        }
    } while (1);
}

void push() {
    if (top >= size / 2) {
        printf("\nStack1 overflow\n");
        return;
    } else {
        printf("\nEnter the item to be pushed :");
        scanf("%d", &item);
        top++;
        stack[top] = item;
        printf("\nThe number pushed is %d", stack[top]);
        return;
    }
}

void push2(int del) {
    if (top2 >= size) {
        printf("\nStack2 overflow\n");
        return;
    } else {

        top2++;
        stack[top2] = del;
        printf("\nThe number pushed is %d", stack[top2]);
        return;
    }
}

void pop() {
    int ch;
    printf("\n Which array you want to pop\n 1-Stack1\n2-Stack2\n");
    scanf("%d", &ch);
    if (ch == 2) {
        pop2();
    }
    if (ch == 1) {
        if (top == 0) {
            printf("\nStack1 underflow\n");
            return;
        } else {
            del = stack[top];
            top--;
            push2(del);
            printf("\nThe number poped is %d", del);
            return;
        }
    }

}

void pop2() {
    int del;
    if (top2 == l) {
        printf("\nStack2 underflow\n");
        return;
    } else {
        del2 = stack[top2];
        top2--;

        printf("\nThe number poped is %d", del2);
        return;
    }

}

void display() {
    int i, ch;
    printf("\n Which array you want to display\n 1-Stack1\n2-Stack2\n");
    scanf("%d", &ch);
    if (ch == 2) {
        if (top2 == size / 2) {
            printf("\nStack2 underflow\n");
            return;
        } else {
            for (i = top2; i > size / 2; i--) {
                printf("\n\t%d", stack[i]);
                printf("\t\n");
            }
        }
    } else if (ch == 1) {
        if (top == 0) {
            printf("\nStack1 underflow\n");
            return;
        } else {
            for (i = top; i > 0; i--) {
                printf("\n\t%d", stack[i]);
                printf("\t\n");
            }
        }
    }
}
