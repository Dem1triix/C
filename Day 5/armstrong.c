#include <stdio.h>

int main() {
    int num, original, remainder, result = 0, digits = 0;
    
    printf("Enter a number: ");
    scanf("%d", &num);
    
    original = num;
    
    // Count digits
    int temp = num;
    while(temp != 0) {
        digits++;
        temp /= 10;
    }
    
    // Calculate sum of digits raised to power of digits count
    temp = num;
    while(temp != 0) {
        remainder = temp % 10;
        
        // Calculate power without pow() function
        int power = 1;
        for(int i = 0; i < digits; i++) {
            power *= remainder;
        }
        
        result += power;
        temp /= 10;
    }
    
    if(result == original) {
        printf("%d is an Armstrong number.\n", original);
    } else {
        printf("%d is not an Armstrong number.\n", original);
    }
    
    return 0;
}