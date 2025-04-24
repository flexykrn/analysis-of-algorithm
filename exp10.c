#include <stdio.h>
#include <string.h>
#include <conio.h>

/* 
   Naive pattern-matching: prints all positions where pattern p[]
   occurs in text t[]. Turbo C compatible. 
*/
void search(char t[], char p[]) {
    int n = strlen(t);
    int m = strlen(p);
    int flag = 0;

    printf("Pattern found at index: ");
    for (int s = 0; s <= n - m; s++) {
        int j;
        for (j = 0; j < m; j++) {
            if (t[s + j] != p[j]) {
                break;
            }
        }
        if (j == m) {
            if (flag) {
                printf(", ");
            }
            printf("%d", s);
            flag = 1;
        }
    }
    if (!flag) {
        printf("No match found");
    }
    printf("\n");
}

int main() {
    char t[100], p[50];

    // clrscr();              // Turbo C: clear screen
    printf("Text: ");
    gets(t);               // Turbo C only (unsafe in modern C)
    printf("Pattern: ");
    gets(p);

    search(t, p);

    getch();               // Turbo C: wait for keypress
    return 0;
}
