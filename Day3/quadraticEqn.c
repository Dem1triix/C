#include <stdio.h>
#include <math.h>

int main() {
    float a, b, c;
    printf("Enter coefficients a, b, c: ");
    scanf("%f %f %f", &a, &b, &c);

    float d = b*b - 4*a*c;

    if (d > 0) {
        float r1 = (-b + sqrt(d)) / (2*a);
        float r2 = (-b - sqrt(d)) / (2*a);
        printf("Real and distinct roots: %.2f, %.2f\n", r1, r2);
    } else if (d == 0) {
        float r = -b / (2*a);
        printf("Real and equal roots: %.2f\n", r);
    } else {
        float real = -b / (2*a);
        float imag = sqrt(-d) / (2*a);
        printf("Complex roots: %.2f + %.2fi, %.2f - %.2fi\n", real, imag, real, imag);
    }

    return 0;
}