#include <stdio.h>

int main() {
    int num, count = 0;
    
    printf("Enter a non-negative integer: ");
    scanf("%d", &num);
    
    if(num < 0) {
        printf("Please enter a non-negative number.\n");
        return 1;
    }
    
    int temp = num;
    
    do {
        count++;
        temp = temp / 10;
    } while(temp != 0);
    
    printf("Number of digits in %d: %d\n", num, count);
    return 0;
}
