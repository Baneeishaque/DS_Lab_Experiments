#include<stdio.h>
#include <process.h>

#define size 5
int q[size], del, item, front = -1, rear = -1;

void insert();

void delete();

void display();

void main() {
    int c;
    printf("\n1-Insert\n2-Delete\n3-Display\n4-Exit");
    do {
        printf("\nEnter your choice:");
        scanf("%d", &c);
        switch (c) {
            case 1:
                insert();
                break;
            case 2:
                delete();
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

void insert() {
    if (front == -1 && rear == -1) {
        front = rear = 0;
    } else {
        rear++;
    }

    printf("\nEnter the item to be inserted :");
    scanf("%d", &item);
    q[rear] = item;

    printf("\nThe number inserted is %d", q[rear]);

}

void delete() {
    if (front == -1 && front > rear) {
        printf("\nQueue is in underflow\n");
        return;
    } else {
        del = q[front];
        front++;
        printf("\nThe number deleted is %d", del);
        return;
    }

}

void display() {
    int i;

    if (front == -1 && front > rear) {
        printf("\nQueue is in underflow\n");
        return;
    } else {
        for (i = front; i <= rear; i++)
            printf("\t%d", q[i]);
    }
}
