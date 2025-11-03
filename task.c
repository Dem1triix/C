//write a program to impliment simple calculator that performs addition, subtraction, multiplication and division using functions and switch case.
 
//switch case statement in C selects one code path which is based on the value of an integral expression.
//syntax is:

 //switch (expression) {
 //   case constant1:
 //       // Statement(s);
 //       break;
 //   case constant2:
 //       // Statement(s);
 //       break;
 //   ...
 //   default:
 //       // runs when no case matches
 //}

#include <stdio.h>

int main() {
    int day;
    printf("\nEnter day number 1-7: \n");
    scanf("%d", &day);

    switch (day) {
        case 1:
            printf("Monday\n");
            break;
        case 2:
            printf("Tuesday\n");
            break;
        case 3:
            printf("Wednesday\n");
            break;
        case 4:
            printf("Thursday\n");
            break;
        case 5:
            printf("Friday\n");
            break;
        case 6:
            printf("Saturday\n");
            break;
        case 7:
            printf("Sunday\n");
            break;
        default:
            printf("Invalid day number!\n");
    }
}
