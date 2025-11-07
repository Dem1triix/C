#include <stdio.h>

int main() {
    int rows, i, j, space;
    
    printf("Enter number of rows (odd number): ");
    scanf("%d", &rows);
    
    // Upper part of diamond
    for(i = 1; i <= rows; i += 2) {
        for(space = 1; space <= (rows - i) / 2; space++) {
            printf(" ");
        }
        for(j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }
    
    // Lower part of diamond
    for(i = rows - 2; i >= 1; i -= 2) {
        for(space = 1; space <= (rows - i) / 2; space++) {
            printf(" ");
        }
        for(j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }
    
    return 0;
}