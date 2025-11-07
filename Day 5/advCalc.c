#include <stdio.h>

int main() {
    char operator;
    double num1, num2, result;
    
    printf("Enter operator (+, -, *, /, ^ for power): ");
    scanf(" %c", &operator);
    printf("Enter two numbers: ");
    scanf("%lf %lf", &num1, &num2);
    
    switch(operator) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if(num2 != 0) {
                result = num1 / num2;
            } else {
                printf("Error: Division by zero!\n");
                return 1;
            }
            break;
        case '^':
            result = 1;
            for(int i = 0; i < num2; i++) {
                result *= num1;
            }
            break;
        default:
            printf("Invalid operator!\n");
            return 1;
    }
    
    printf("%.2lf %c %.2lf = %.2lf\n", num1, operator, num2, result);
    return 0;
}