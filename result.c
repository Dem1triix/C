#include <stdio.h>

int main() {
    int marks, total = 0;
    float percent;

    printf("Enter marks of 5 subjects:\n");
    for (int i = 1; i <= 5; i++) {
        printf("Subject %d: ", i);
        scanf("%d", &marks);
        total += marks;
    }
    if(marks<40)
    percent= (total / 5);

    if(percent < 40)
        printf("Result: %2.1f%, Fail\n",percent);
    else if (percent >=75)
        printf("Result: %2.1f%, Distinction\n",percent);
    else if(percent >= 60)
        printf("Result: %2.1f%, First Class\n",percent);
    else if(percent >= 50)
        printf("Result: %2.1f%, Second Class\n",percent);
    else
        printf("Result: %2.1f%, Third Class\n",percent);
    return 0;
}