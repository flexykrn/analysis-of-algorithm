#include <stdio.h>

void DC_MAXMIN(int A[], int low, int high, int *min, int *max) {
    if (low == high) {
        *min = A[low];
        *max = A[low];
    } else if (low == high - 1) {
        if (A[low] < A[high]) {
            *min = A[low];
            *max = A[high];
        } else {
            *min = A[high];
            *max = A[low];
        }
    } else {
        int mid = (low + high) / 2;
        int LMin, LMax, RMin, RMax;
        
        // Left half
        DC_MAXMIN(A, low, mid, &LMin, &LMax);
        // Right half
        DC_MAXMIN(A, mid + 1, high, &RMin, &RMax);
        
        // Combine the results
        if (LMax > RMax) {
            *max = LMax;
        } else {
            *max = RMax;
        }

        if (LMin < RMin) {
            *min = LMin;
        } else {
            *min = RMin;
        }
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    int A[100]; 

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    int min, max;
    DC_MAXMIN(A, 0, n - 1, &min, &max);
    
    printf("Min: %d, Max: %d\n", min, max);
    return 0;
}

