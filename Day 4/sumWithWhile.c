#include <stdio.h>

int main() {
    int num, sum = 0;
    
    printf("Enter integers (0 to quit):\n");
    
    while (1) {  // infinite loop with explicit break
        printf("Enter number: ");
        if (scanf("%d", &num) != 1) {  // check if input is valid
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n');  // clear input buffer
            continue;
        }
        
        if (num == 0) {  // check exit condition first
            break;
        }
        
        if (num > 0) {  // only add positive numbers
            sum += num;
        }
    }
    
    printf("Sum of positive numbers: %d\n", sum);
    return 0;
}