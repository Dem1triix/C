#include <stdio.h>

int main() {
    int num;
    
    printf("Enter integers (stop when even number is entered):\n");
    
    do {
        printf("Enter number: ");
        scanf("%d", &num);
        
        if(num % 2 != 0) {
            printf("odd\n");
        }
    } while(num % 2 != 0);
    
    printf("Program terminated, Even number entered");
    return 0;
}