#include <stdio.h>

int main() {
    int num, i, isPrime = 1;
    
    printf("Enter an integer: ");
    scanf("%d", &num);
    
    // Positive/Negative/Zero
    if(num > 0) {
        printf("Positive, ");
    } else if(num < 0) {
        printf("Negative, ");
    } else {
        printf("Zero, ");
        isPrime = 0;
    }
    
    // Even/Odd
    if(num % 2 == 0) {
        printf("Even, ");
    } else {
        printf("Odd, ");
    }
    
    // Prime/Composite (for numbers > 1)
    if(num > 1) {
        for(i = 2; i * i <= num; i++) {
            if(num % i == 0) {
                isPrime = 0;
                break;
            }
        }
        if(isPrime) {
            printf("Prime\n");
        } else {
            printf("Composite\n");
        }
    } else if(num == 1) {
        printf("Neither prime nor composite\n");
    } else {
        printf("Not prime\n");
    }
    
    return 0;
}