#include<stdio.h>
void insertionsort(int arr[], int n) {
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
        for (int k = 0; k < n; k++) {
            printf("%d ", arr[k]);
        }
        printf("\n");
    }
}
int main() {
    int n;
    printf("enter the number of element:\n");
    scanf("%d", &n);
    int arr[n];
    printf("enter the element of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("unsorted array:\n");
    for (int j = 0; j < n; j++) {
        printf("%d ", arr[j]);
    }
    printf("\n");
    printf("passes:\n");
    insertionsort(arr, n);
    printf("sorted array:\n");
    for (int k = 0; k < n; k++) {
        printf("%d ", arr[k]);
    }
    printf("\n");
    return 0;
}
