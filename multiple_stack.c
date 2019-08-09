#include<stdio.h>

#define max 10

#include<stdlib.h>

void stack1_push();

void stack1_pop();

void stack1_display();

void stack2_push();

void stack2_pop();

void stack2_display();

int n, multiple_stack[max], top1 = 0, top2 = max / 2, i;

void main() {
    int c;
    do {
        printf(
                "\n 1.push 1 \n2.pop 1\n3.display 1\n4.push 2\n5.pop 2\n6.display 2\n7.exit\n enter your choice");
        scanf("%d", &c);
        switch (c) {
            case 1:
                stack1_push();
                break;
            case 2:
                stack1_pop();
                break;
            case 3:
                stack1_display();
                break;
            case 4:
                stack2_push();
                break;
            case 5:
                stack2_pop();
                break;
            case 6:
                stack2_display();
                break;
            case 7:
                printf("\nthank you\n");
                exit(0);
                break;
            default:
                printf("\ntry again");
        }
    } while (c != 7);
}

void stack1_push() {
    int insert_item;
    if (top1 == ((max / 2) - 1)) {
        printf("stack over flow");
    } else {
        printf("\nenter the item to be inserted to stack1");
        scanf("\t%d", &insert_item);
        multiple_stack[top1] = insert_item;
        top1++;
    }
}

void stack1_pop() {
    int del_item;
    if (top1 == 0) {
        printf("\nstack underflow");
    } else {
        top1--;
        del_item = multiple_stack[top1];
    }
}

void stack1_display() {
    if (top1 == 0) {
        printf("\n the stack1 is empty..");
        return;
    } else {
        printf("\nthe elements of stack1.....");
        for (i = 0; i < top1; i++) {
            printf("%d\t", multiple_stack[i]);
        }
    }
}

void stack2_push() {
    int insert_item;
    if (top2 == max - 1) {
        printf("\nstack over flow");
    } else {
        printf("\nenter the item to be inserted to stack1");
        scanf("\t%d", &insert_item);
        multiple_stack[top2] = insert_item;
        top2++;
    }
}

void stack2_pop() {
    int del_item;
    if (top2 == max / 2) {
        printf("\nstack underflow");
    } else {
        top2--;
        del_item = multiple_stack[top2];
    }
}

void stack2_display() {
    if (top2 == max / 2) {
        printf("\n the stack2 is empty..");
        return;
    } else {
        printf("\nthe elements of stack2.....");
        for (i = max / 2; i < top2; i++) {
            printf("%d\t", multiple_stack[i]);
        }
    }
}
