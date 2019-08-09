#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    struct node *next;
    struct node *prev;
};
typedef struct node n;

n *create_node(int);

void add_node();

void insert_at_first();

void insert_at_end();

void insert_at_position();

void delete_node_position();

void sort_list();

void update();

void search();

void display_from_beg();

void display_in_rev();

n *new, *ptr, *prev;
n *first = NULL, *last = NULL;
int number = 0;

void main() {
    int ch;

    printf("\n linked list\n");
    printf(
            "1.insert at beginning \n 2.insert at end\n 3.insert at position\n4.sort linked list\n 5.delete node at position\n 6.updatenodevalue\n7.search element \n8.displaylist from beginning\n9.display list from end\n10.exit ");

    while (1) {

        printf("\n enter your choice:");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                insert_at_first();
                break;
            case 2:
                insert_at_end();
                break;
            case 3:
                insert_at_position();
                break;
            case 4:
                sort_list();
                break;
            case 5:
                delete_node_position();
                break;
            case 6:
                update();
                break;
            case 7:
                search();
                break;
            case 8:
                display_from_beg();
                break;
            case 9:
                display_in_rev();
                break;
            case 10:
                exit(0);
            case 11:
                add_node();
                break;
            default:
                printf("\ninvalid choice");
        }
    }
}

/*
 *MEMORY ALLOCATED FOR NODE DYNAMICALLY
 */
n *create_node(int info) {
    number++;
    new = (n *) malloc(sizeof(n));
    new->val = info;
    new->next = NULL;
    new->prev = NULL;
    return new;
}

/*
 *ADDS NEW NODE
 */
void add_node() {

    int info;

    printf("\nenter the value you would like to add:");
    scanf("%d", &info);
    new = create_node(info);

    if (first == last && first == NULL) {

        first = last = new;
        first->next = last->next = NULL;
        first->prev = last->prev = NULL;
    } else {
        last->next = new;
        new->prev = last;
        last = new;
        last->next = first;
        first->prev = last;
    }
}

/*
 *INSERTS ELEMENT AT FIRST
 */
void insert_at_first() {

    int info;

    printf("\nenter the value to be inserted at first:");
    scanf("%d", &info);
    new = create_node(info);

    if (first == last && first == NULL) {
        printf("\ninitially it is empty linked list later insertion is done");
        first = last = new;
        first->next = last->next = NULL;
        first->prev = last->prev = NULL;
    } else {
        new->next = first;
        first->prev = new;
        first = new;
        first->prev = last;
        last->next = first;
        printf("\n the value is inserted at begining");
    }
}

/*
 *INSERTS ELEMNET AT END
 */
void insert_at_end() {

    int info;

    printf("\nenter the value that has to be inserted at last:");
    scanf("%d", &info);
    new = create_node(info);

    if (first == last && first == NULL) {
        printf(
                "\ninitially the list is empty and now new node is inserted but at first");
        first = last = new;
        first->next = last->next = NULL;
        first->prev = last->prev = NULL;
    } else {
        last->next = new;
        new->prev = last;
        last = new;
        first->prev = last;
        last->next = first;
    }
}

/*
 *INSERTS THE ELEMENT AT GIVEN POSITION
 */
void insert_at_position() {
    int info, pos, len = 0, i;
    int *prevnode;

    printf("\n enter the value that you would like to insert:");
    scanf("%d", &info);
    printf("\n enter the position where you have to enter:");
    scanf("%d", &pos);
    new = create_node(info);

    if (first == last && first == NULL) {
        if (pos == 1) {
        }
    }
}

