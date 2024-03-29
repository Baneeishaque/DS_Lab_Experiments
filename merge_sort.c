#include <stdio.h>

#define MAX_ARY 7

void merge_sort(int x[], int end, int start);

int main(void) {
    int ary[MAX_ARY];
    int j = 0;
    printf("\n\nEnter the elements to be sorted: \n");
    for (j = 0; j < MAX_ARY; j++)
        scanf("%d", &ary[j]);
    /* array before mergesort */
    printf("Before :");
    for (j = 0; j < MAX_ARY; j++)
        printf(" %d", ary[j]);
    printf("\n");
    merge_sort(ary, 0, MAX_ARY - 1);
    /* array after mergesort */
    printf("After Merge Sort :");
    for (j = 0; j < MAX_ARY; j++)
        printf(" %d", ary[j]);
    printf("\n");
}

/* Method to implement Merge Sort*/
void merge_sort(int x[], int end, int start) {
    int j = 0;
    const int size = start - end + 1;
    int mid = 0;
    int mrg1 = 0;
    int mrg2 = 0;
    int executing[MAX_ARY];
    if (end == start)
        return;
    mid = (end + start) / 2;
    merge_sort(x, end, mid);
    merge_sort(x, mid + 1, start);
    for (j = 0; j < size; j++)
        executing[j] = x[end + j];
    mrg1 = 0;
    mrg2 = mid - end + 1;
    for (j = 0; j < size; j++) {
        if (mrg2 <= start - end)
            if (mrg1 <= mid - end)
                if (executing[mrg1] > executing[mrg2])
                    x[j + end] = executing[mrg2++];
                else
                    x[j + end] = executing[mrg1++];
            else
                x[j + end] = executing[mrg2++];
        else
            x[j + end] = executing[mrg1++];
    }
}
