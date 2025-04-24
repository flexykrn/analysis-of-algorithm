#include <stdio.h>
#include <conio.h>

void knapsack(int N, int M, int P[], int W[]) {
    float ratio[20], profit = 0.0;
    int i, j;
    int tempP, tempW;
    float tempR;

    // Calculate profit/weight ratio
    for (i = 0; i < N; i++) {
        ratio[i] = (float)P[i] / W[i];
    }

    // Sort items by ratio (descending)
    for (i = 0; i < N - 1; i++) {
        for (j = i + 1; j < N; j++) {
            if (ratio[i] < ratio[j]) {
                tempR = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = tempR;

                tempP = P[i];
                P[i] = P[j];
                P[j] = tempP;

                tempW = W[i];
                W[i] = W[j];
                W[j] = tempW;
            }
        }
    }

    // Apply fractional knapsack
    for (i = 0; i < N; i++) {
        if (M >= W[i]) {
            M -= W[i];
            profit += P[i];
        } else {
            profit += P[i] * ((float)M / W[i]);
            break;
        }
    }

    printf("\nTotal Profit: %.2f", profit);
}

void main() {
    int N, M, i, P[20], W[20];

    // clrscr();

    printf("Enter the number of objects (N): ");
    scanf("%d", &N);

    printf("Enter the capacity of the knapsack (M): ");
    scanf("%d", &M);

    printf("Enter the profits of the objects:\n");
    for (i = 0; i < N; i++) {
        scanf("%d", &P[i]);
    }

    printf("Enter the weights of the objects:\n");
    for (i = 0; i < N; i++) {
        scanf("%d", &W[i]);
    }

    knapsack(N, M, P, W);

    // getch();
}
