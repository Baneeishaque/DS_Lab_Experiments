#include<stdio.h>
#include <process.h>

#define size 3

int cq[size], f = -1, r = -1;

void insert();

void delete();

void display();

int main() {
    int c;
    do {
        printf("\n 1-Insert\n2-Delete\n3-Display\n4-Exit\n");
        scanf("%d", &c);
        switch (c) {
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);

            default:
                printf("\nInvalid Choice");
        }
    } while (1);
}

void insert() {
    int data;
    if (f == 0 && r == size - 1 || f == r + 1) {
        printf("\n Q Overflow\n");
        return;
    }
    printf("\nEnter the Data to be inserted:\n");
    scanf("%d", &data);
    if (f == -1) {
        f = 0;

    }
    if (r == size - 1)
        r = 0;
    r = r + 1;
    //printf("%d,%d",r,f);
    cq[r] = data;
}

void delete() {
    int d;
    if (f == -1) {
        printf("\n Q underflow\n");
        return;
    }

    if (f == r) {
        d = cq[f];
        cq[f] = NULL;
        f = -1;
        r = -1;
    } else if (f == size - 1) {
        d = cq[f];
        cq[f] = NULL;
        f = 0;
    } else {
        d = cq[f];
        cq[f] = NULL;
        f = f + 1;
    }
    printf("\nthe deleted data is %d", d);

}

void display() {
    printf("\nThe cicular q is :\n");
    int i;
    if (f == -1)
        printf("\n Q underflow\n");
    else {
        if (f > r) {
            for (i = 0; i <= r; i++)
                printf("\n%d\t", cq[i]);
            for (i = f; i <= size - 1; i++)
                printf("\n%d\t", cq[i]);
        } else
            for (i = f; i <= r; i++)
                printf("\n%d\t", cq[i]);
    }
}

