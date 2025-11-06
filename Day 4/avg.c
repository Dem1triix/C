#include <stdio.h>

int main() {
    float num, sum = 0;
    int count = 0;
    
    printf("Enter numbers (-1.0 to stop):\n");
    
    do {
        printf("Enter number: ");
        scanf("%f", &num);
        
        if(num != -1.0) {
            sum += num;
            count++;
        }
    } while(num != -1.0);
    
    if(count > 0) {
        printf("Average of %d numbers: %.2f\n", count, sum / count);
    } else {
        printf("No numbers entered.\n");
    }
    
    return 0;
}