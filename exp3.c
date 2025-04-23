#include<stdio.h>
#include<conio.h>
#define MAX 100

void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    // clrscr();
    int n, i;
    int beg, end, mid, num, found = 0;
    int arr[MAX];

    printf("Enter the size of the array (max %d):\n", MAX);
    scanf("%d", &n);

    if (n > MAX) {
        printf("Size exceeds the maximum limit of %d.\n", MAX);
        getch();
        return 1;
    }

    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }


    bubbleSort(arr, n);

    printf("Enter the number to be searched:\n");
    scanf("%d", &num);

    beg = 0;
    end = n - 1;

    while (beg <= end) {
        mid = (beg + end) / 2;

        if (arr[mid] == num) {
            printf("%d found at index %d\n", num, mid);
            found = 1; // Mark as found
            break; // Exit the loop
        } else if (arr[mid] > num) {
            end = mid - 1;
        } else {
            beg = mid + 1;
        }
    }

    if (!found) {
        printf("%d not found in the array.\n", num);
    }

    getch();
    return 0;
}

