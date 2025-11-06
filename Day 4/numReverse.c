#include <stdio.h>

int main() {
    int num, reversed, original, remainder;
    char repeat;
    
    do {
        printf("Enter a non-negative integer: ");
        scanf("%d", &num);
        
        if(num < 0) {
            printf("Please enter a non-negative number.\n");
            continue;
        }
        
        original = num;
        reversed = 0;
        
        do {
            remainder = num % 10;
            reversed = reversed * 10 + remainder;
            num = num / 10;
        } while(num != 0);
        
        printf("Original: %d, Reversed: %d\n", original, reversed);
        
        printf("Do you want to reverse another number? (y/n): ");
        scanf(" %c", &repeat);
    } while(repeat == 'y' || repeat == 'Y');
    printf("Program terminated.\n");
    return 0;
}