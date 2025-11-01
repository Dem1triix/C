#include <stdio.h>

int main()
{
    int a, b, sum;
    a = 145;
    b = 5;
    sum = a + b;
    float p = a * b;
    float d = a / b;    
    printf("Sum of %d and %d is %d\n\n", a, b, sum);
    printf("Product of %d and %d is %f\n", a,b, p);
    printf("Division of %d and %d is %d\n", a,b,a/b);
    printf("Sum of %d and %d is %d\n", a, b, a+b);
    return 0;
}