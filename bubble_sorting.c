#include<stdio.h>

#define max 50

void bubble(int a[], int n);

int main() {

    int x[max], i, n;

    printf("\nEnter the no:of elements:");
    scanf("\n%d", &n);

    printf("\nEnter the elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &x[i]);

    bubble(x, n);

    printf("\nThe sorted array is\n");
    for (i = 0; i < n; i++)
        printf("%d\t", x[i]);
    printf("\n");

    return 0;
}

void bubble(int a[], int n) {
    int i, j, t;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n - 1; j++) {
            if (a[j] > a[j + 1]) {
                t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        }
    }
}


