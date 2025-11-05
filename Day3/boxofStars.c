#include <stdio.h>

void main() {
    int stars = 0;
    printf("Enter number of stars (columns): ");
    scanf("%d", &stars);
    

    for (int i = 0; i < stars; i++) {
        for (int j = 0; j < stars; j++) {
            // Print '*' for first/last row or first/last column
            if (i == 0 || i == stars - 1|| j == 0 || j == stars - 1)
                printf(" *");
            else
                printf("  ");
        }
        printf("\n");
    }
}
