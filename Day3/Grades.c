#include <stdio.h>

int main() {
    float phy, chem, bio, math, comp;
    printf("Enter marks for Physics, Chemistry, Biology, Math, Computer: ");
    scanf("%f %f %f %f %f", &phy, &chem, &bio, &math, &comp);

    float total = phy + chem + bio + math + comp;
    float percent = total / 5;

    printf("Percentage = %.2f\n", percent);

    if (percent >= 90)
        printf("Grade A\n");
    else if (percent >= 80)
        printf("Grade B\n");
    else if (percent >= 70)
        printf("Grade C\n");
    else if (percent >= 60)
        printf("Grade D\n");
    else if (percent >= 40)
        printf("Grade E\n");
    else
        printf("Grade F\n");

    return 0;
}