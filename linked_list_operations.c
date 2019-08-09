#include <stdio.h>
//#include <conio.h>
#include <malloc.h>

struct node {
    int data;
    struct node *link;
} *ptr, *cpt, *first = NULL;

void create();

void display();

void sort();

void search();

void insert();

void binsert();

void einsert();

void ginsert();

void sinsert();

void Delete();

void bdelete();

void edelete();

void gdelete();

void under();

void main() {
    int c;
    //clrscr();
    do {
        printf(
                "\n1-Create\n2-Insert\n3-Delete\n4-Display\n5-Sorting\n6-Search\n7-Exit\n");
        printf("\nEnter the Choice :");
        scanf("%d", &c);
        switch (c) {
            case 1:
                create();
                //getch();
                break;
            case 2:
                insert();
                //getch();
                break;
            case 3:
                Delete();
                //getch();
                break;
            case 4:
                display();
                break;
            case 5:
                sort();
                //getch();
                break;
            case 6:
                search();
                //getch();
                break;
            case 7:
                exit(0);
            default:
                printf("\nInvalid choice\n");
        }
    } while (1);
}

void create() {
    int n;
    if (first != NULL) {
        printf("\nList all ready exist\n");
        return;
    }
    ptr = (struct node *) malloc(sizeof(struct node));
    printf("\nEnter the value of node:");
    scanf("%d", &ptr->data);
    first = ptr;
    do {
        cpt = (struct node *) malloc(sizeof(struct node));
        printf("\nEnter the value of node:");
        scanf("%d", &cpt->data);
        ptr->link = cpt;
        ptr = cpt;
        printf("\nDo you want to cont..(1/0) :");
        scanf("%d", &n);
    } while (n == 1);
    ptr->link = NULL;
    return;
}

void display() {
    ptr = first;
    if (ptr == NULL) {
        printf("\nThe List is Empty\n");
        return;
    }
    printf("\nThe List is \n");
    while (ptr != NULL) {
        printf("%d\t", ptr->data);
        ptr = ptr->link;
    }
    return;
}

void insert() {
    int c;
    do {
        printf("\n1-@Begining\n2-@End\n3-@GivenPos\n4-@sorted list\n5-Exit");
        printf("\nEnter the Choice :");
        scanf("%d", &c);
        switch (c) {
            case 1:
                binsert();
                //getch();
                break;
            case 2:
                einsert();
                //getch();
                break;
            case 3:
                ginsert();
                //getch();
                break;
            case 4:
                sinsert();
                //getch();
                break;
            case 5:
                return;
            default:
                printf("\nInvalid choice\n");
        }
    } while (1);
}

void binsert() {
    ptr = (struct node *) malloc(sizeof(struct node));
    printf("\nEnter the value of node:");
    scanf("%d", &ptr->data);
    ptr->link = first;
    first = ptr;
    return;
}

void einsert() {
    ptr = (struct node *) malloc(sizeof(struct node));
    printf("\nEnter the value of node:");
    scanf("%d", &ptr->data);
    ptr->link = NULL;
    cpt = first;
    while (cpt->link != NULL) {
        cpt = cpt->link;
    }
    cpt->link = ptr;
    return;
}

void ginsert() {
    int data;
    ptr = (struct node *) malloc(sizeof(struct node));
    printf("\nEnter the value of node:");
    scanf("%d", &ptr->data);
    printf("\nEnter the value of node after which insertion will be made :");
    scanf("%d", &data);
    cpt = first;
    while (cpt->data != data) {
        cpt = cpt->link;
    }
    ptr->link = cpt->link;
    cpt->link = ptr;
    return;
}

void sinsert() {
    struct node *tpt;
    sort();
    ptr = (struct node *) malloc(sizeof(struct node));
    printf("\nEnter the value of node:");
    scanf("%d", &ptr->data);

    cpt = first;
    while (cpt->data < ptr->data) {
        tpt = cpt;
        cpt = cpt->link;
    }
    ptr->link = cpt;
    tpt->link = ptr;
    return;
}

void sort() {
    int temp;
    ptr = first;
    while (ptr->link != NULL) {
        cpt = ptr->link;
        while (cpt != NULL) {
            if (ptr->data > cpt->data) {
                temp = ptr->data;
                ptr->data = cpt->data;
                cpt->data = temp;
            }
            cpt = cpt->link;
        }
        ptr = ptr->link;
    }
}

void Delete() {
    int c;
    do {
        printf("\n1-From Begining\n2-From End\n3-From GivenPos\n4-Exit");
        printf("\nEnter the Choice :");
        scanf("%d", &c);
        switch (c) {
            case 1:
                bdelete();
                //getch();
                break;
            case 2:
                edelete();
                //getch();
                break;
            case 3:
                gdelete();
                //getch();
                break;
            case 4:
                return;
            default:
                printf("\nInvalid choice\n");
        }
    } while (1);
}

void bdelete() {
    under();
    ptr = first;
    first = ptr->link;
    free(ptr);
    return;
}

void edelete() {
    /*if(first==NULL)
     {
     printf("\n The List is empty\n");
     return;
     }*/
    under();
    ptr = first;
    while (ptr->link != NULL) {
        cpt = ptr;
        ptr = ptr->link;
    }
    cpt->link = NULL;
    free(ptr);
    return;
}

void gdelete() {
    int data;
    if (first == NULL) {
        printf("\n The List is empty\n");
        return;
    }
    ptr = first;
    printf("\nEnter the value of node to be deleted :");
    scanf("%d", &data);
    while (ptr->data != data) {
        cpt = ptr;
        ptr = ptr->link;
    }
    cpt->link = ptr->link;
    free(ptr);
    return;
}

void search() {
    int data, f = 0, c = 0;
    printf("\nEnter the value of node to be searched :");
    scanf("%d", &data);
    ptr = first;
    while (ptr != NULL) {
        if (ptr->data == data) {
            c++;
            f = 1;
        }
        ptr = ptr->link;
    }
    if (f == 1) {
        printf("\nData is found :%d times\n", c);
        return;
    } else {
        printf("\nData is not found\n");
        return;
    }
}

void under() {
    if (first == NULL) {
        printf("\n The List is empty\n");
        return;
    }
}
