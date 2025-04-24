#include <stdio.h>
#include <conio.h>

#define MAX_VERTICES 10   // Turbo C has limited memory, so use smaller size
#define INF 10000         // Representing infinity

void floyd(int w[MAX_VERTICES][MAX_VERTICES], int n) {
    int i, j, k;
    int d[MAX_VERTICES][MAX_VERTICES];

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            d[i][j] = w[i][j];
        }
    }

    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (d[i][k] != INF && d[k][j] != INF && d[i][k] + d[k][j] < d[i][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }

    printf("\nShortest Path Matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (d[i][j] == INF)
                printf("INF ");
            else
                printf("%3d ", d[i][j]);
        }
        printf("\n");
    }
}

void main() {
    int i, j, n;
    int w[MAX_VERTICES][MAX_VERTICES];

    // clrscr();

    printf("Enter the number of vertices (Max %d): ", MAX_VERTICES);
    scanf("%d", &n);

    if (n > MAX_VERTICES) {
        printf("Number exceeds limit.");
        // getch();
        return;
    }

    printf("Enter the adjacency matrix (use 10000 or more for no edge):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &w[i][j]);
            if (i != j && w[i][j] >= 10000)
                w[i][j] = INF;
        }
    }

    floyd(w, n);

    // getch();
}
