#include <stdio.h>

int main() {
    int num, sum = 0;
    
    printf("Enter a positive integer: ");
    if (scanf("%d", &num) != 1) {
        printf("Invalid input. Please enter a number.\n");
        return 1;
    }
    
    if(num <= 0) {
        printf("Please enter a positive number.\n");
        return 1;
    }
    
    printf("Digital root calculation: ");
    
    while(num >= 10) {
        printf("%d", num);
        sum = 0;
        
        // Calculate the sum of digits of num
        int temp = num;
        while(temp > 0) {
            sum += temp % 10;
            temp /= 10;
        }
        num = sum;
        if(num >= 10) {
            printf(" -> ");
        }
    }
    
    printf("%d\n", num);
    printf("Digital root: %d\n", num);
    return 0;
}