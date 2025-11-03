#include<stdio.h>
#include <crtdbg.h>
#include <conio.h>

int swapping(){
   int a = 5, b = 6;
   printf("Values Before swapping:\n a = %d, b = %d\n", a, b);
   a+=b;
   b=a-b;
   a=a-b;
   printf("Values After swapping:\n a = %d, b = %d\n", a, b);
   return 0;   
}

int switchCase(){
    clrscr();
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    float num1, num2, result;
    int choice;

    printf("Simple Calculator\n");
    printf("Select operation:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");

    printf("Enter your choice (1-4): ");
    scanf("%d", &choice);

    printf("Enter two numbers: ");
    scanf("%f %f", &num1, &num2);
    if (num2==0)
    {
        printf("Warning: The second number is zero. Division by zero will not be allowed.\n");
    }
    
    
    switch (choice)
    {
    case 1:
        result = num1 + num2;
        printf("Result: %.3f\n", result);
        break;

    case 2:
        result = num1 - num2;
        printf("Result: %.3f\n", result);
        break;

    case 3:
        result = num1 * num2;
        printf("Result: %.3f\n", result);
        break;

    case 4:
        if(num2 != 0){
            result = num1 / num2;
            printf("Result: %.3f\n", result);
        } else {
            printf("Error: Division by zero is not allowed.\n");
        }
        break;
    case 5:
        

    default:
        printf("Invalid choice\n");
        break;

        return 0;
    }
}

int main(){
    switchCase();
    swapping();
    return 0;
}