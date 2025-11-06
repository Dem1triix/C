#include <stdio.h>

int main() {
    int num, i;
    long long factorial;
    char repeat;
    
    do {
        printf("Enter a non-negative integer: ");
        scanf("%d", &num);
        
        if(num < 0) {
            printf("Factorial is not defined for negative numbers.\n");
        } else {
            factorial = 1;
            for(i = 1; i <= num; i++) {
                factorial *= i;
            }
            printf("Factorial of %d = %lld\n", num, factorial);
        }
        
        printf("Do you want to compute another factorial? (y/n): ");
        scanf(" %c", &repeat);
    } while(repeat == 'y' || repeat == 'Y');
    
    return 0;
}