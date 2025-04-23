#include <stdio.h>
#include<conio.h>
#define max 100


void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
	printf("%d ", arr[i]);
    }
    printf("\n");
}

void selectionSort(int arr[], int n) {
    int i, j, minIndex, temp;
    for (i = 0; i < n - 1; i++) {
	minIndex = i;
	for (j = i + 1; j < n; j++) {
	    if (arr[j] < arr[minIndex]) {
		minIndex = j;
	    }
	}
	temp = arr[minIndex];
	arr[minIndex] = arr[i];
	arr[i] = temp;
	printArray(arr,n);
    }
}


int main() {
    // clrscr();
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[max];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
	scanf("%d", &arr[i]);
    }

    printf("Original array: \n");
    printArray(arr, n);

    printf("passes:\n");

    selectionSort(arr, n);

    printf("Sorted array: \n");
    printArray(arr, n);
    getch();
    return 0;
}
