#include <stdio.h>
#include <stdlib.h>

int main() {
    int num, sum = 0;
    printf("Perfect Number Checker\n");
    printf("A perfect number is a positive integer that is equal to the sum of its proper divisors.\n\n");
    printf("Enter a positive integer (only integer input is accepted): ");
    if (scanf("%d", &num) != 1) {
        printf("Invalid input. Please enter a valid integer.\n");
        return 1;
    }
    
    if(num <= 0) {
        printf("Please enter a positive number.\n");
        return 1;
    }
    
    printf("Proper divisors: ");
    int i;
    for(i = 1; i <= num / 2; i++) {
        if(num % i == 0) {
            printf("%d ", i);
            sum += i;
        }
    }
    
    printf("\nSum of proper divisors: %d\n", sum);
    
    if(sum == num) {
        printf("%d is a Perfect number!\n", num);
    } else {
        printf("%d is not a Perfect number.\n", num);
    }
    
    return 0;
}