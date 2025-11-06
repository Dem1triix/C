#include <stdio.h>

int main() {
    int n, i, j, isPrime;
    
    printf("Enter N (>1): ");
    scanf("%d", &n);
    
    if(n <= 1) {
        printf("Please enter a number greater than 1.\n");
        return 1;
    }
    
    printf("Prime numbers up to %d: ", n);
    
    i = 2;
    do {
        isPrime = 1;
        
        j = 2;
        do {
            if(i % j == 0 && i != j) {
                isPrime = 0;
                break;
            }
            j++;
        } while(j <= i / 2);
        
        if(isPrime) {
            printf("%d ", i);
        }
        i++;
    } while(i <= n);
    
    printf("\n");
    return 0;
}