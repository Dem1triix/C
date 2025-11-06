#include <stdio.h>

int main() {
    float principal, rate, years, interest;
    
    do {
        printf("(type 0 to exit)");
        printf("\nEnter principal amount: \n");
        
        scanf("%f", &principal);
        
        if(principal == 0) {
            break;
        }
        
        printf("Enter rate of interest: ");
        scanf("%f", &rate);
        printf("Enter time in years: ");
        scanf("%f", &years);
        
        interest = (principal * rate * years) / 100;
        printf("Simple Interest = %.2f\n", interest);
        
    } while(principal != 0);
    
    printf("Calculator closed.\n");
    return 0;
}