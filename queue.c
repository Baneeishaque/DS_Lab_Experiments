#include <stdio.h>
#include <stdlib.h>

#define queue_max 5
#define circular_queue_max 5

void queue();

void queue_insert();

void circular_queue_insert();

void circular_queue_delete();

void circular_queue_display();

void queue_delete();

void queue_display();

void circular_queue();

int queue_array[queue_max], queue_front = 0, queue_rear = 0;
int circular_queue_array[queue_max], circular_queue_front = 0,
        circular_queue_rear = 0;

void main() {
    int choice;
    system("cls");
    do {
        printf(
                "\nQueue Imlementation Using Array\n1. Queue\n2. Circular Queue\n3. Double Ended Queue\n4. Exit\nEnter Your choice : ");
        scanf("%d", &choice);
        //printf("\n Input is %d",choice);
        switch (choice) {
            case 1:
                queue();
                break;
            case 2:
                printf("\nTo be Implemented...");
                break;
            case 3:
                printf("\nTo be Implemented...");
                break;
            case 4:
                printf("\nThank You...\n");
                break;
            default:
                printf("\nInvalid Choice,Try Again\n");
                break;
        }
    } while (choice != 4);

}

void queue() {
    int choice;
    do {
        printf(
                "\nQueue Operations\n1. Insertion\n2. Deletion\n3. Display\n4. Exit\nEnter Your choice : ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                queue_insert();
                break;
            case 2:
                queue_delete();
                break;
            case 3:
                queue_display();
                break;
            case 4:
                printf("\nThank You...\n");
                break;
            default:
                printf("\nInvalid Choice,Try Again\n");
        }

    } while (choice != 4);
}

void circular_queue() {
    int choice;
    do {
        printf(
                "\nCircular Queue Operations\n1. Insertion\n2. Deletion\n3. Display\n4. Exit\nEnter Your choice : ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                circular_queue_insert();
                break;
            case 2:
                circular_queue_delete();
                break;
            case 3:
                circular_queue_display();
                break;
            case 4:
                printf("\nThank You...\n");
                break;
            default:
                printf("\nInvalid Choice,Try Again\n");
        }

    } while (choice != 4);
}

void queue_insert() {
    int insert_item;
    if (queue_rear == queue_max) {
        printf("\nQueue Overflow...\n");
    } else {
        printf("\nEnter The Number to be Inserted : ");
        scanf("%d", &insert_item);
        queue_array[queue_rear] = insert_item;
        printf("\nThe inserted item is : %d\n", queue_array[queue_rear]);
        queue_rear++;
    }

}

void circular_queue_insert() {
    int insert_item;
    if (circular_queue_rear == circular_queue_max) {
        printf("\nQueue Overflow...\n");
    } else {
        printf("\nEnter The Number to be Inserted : ");
        scanf("%d", &insert_item);
        circular_queue_array[circular_queue_rear] = insert_item;
        printf("\nThe inserted item is : %d\n",
               circular_queue_array[circular_queue_rear]);
        circular_queue_rear++;
    }

}

void queue_delete() {
    int delete_item;
    if (queue_front == queue_rear) {
        printf("\nQueue Underflow...\n");
    } else {

        delete_item = queue_array[queue_front];
        printf("\nThe deleted item is : %d\n", queue_array[queue_front]);
        queue_front++;
    }

}

void circular_queue_delete() {
    int delete_item;
    if (queue_front == queue_rear) {
        printf("\nQueue Underflow...\n");
    } else {

        delete_item = queue_array[queue_front];
        printf("\nThe deleted item is : %d\n", queue_array[queue_front]);
        queue_front++;
    }

}

void queue_display() {
    int i;
    if (queue_front == queue_rear) {
        printf("\nQueue Underflow...\n");
    } else {

        for (i = queue_front; i < queue_rear; i++) {
            printf("%d\t", queue_array[i]);
        }
    }

}

void circular_queue_display() {
    int i;
    if (queue_front == queue_rear) {
        printf("\nQueue Underflow...\n");
    } else {

        for (i = queue_front; i < queue_rear; i++) {
            printf("%d\t", queue_array[i]);
        }
    }

}

/*bool queue_isempty()
 {
 if(queue_front==queue_max)
 {
 return 1;
 }
 else
 {
 return 0;
 }
 }*/
