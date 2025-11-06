#include <stdio.h>

#include <time.h>

int main() {
    int choice;
    
    do {
        printf("\n=== Menu ===\n");
        printf("1. Greet\n");
        printf("2. Show current time\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF) {}
            printf("Invalid input! Please enter a number.\n");
            choice = 0;
            continue;
        }
        
        switch(choice) {
            case 1:
                printf("Hello! Welcome to the program!\n");
                break;
            case 2: {
                time_t t = time(NULL);
                struct tm *lt = localtime(&t);
                if (lt) {
                    char buf[64];
                    if (strftime(buf, sizeof buf, "%Y-%m-%d %H:%M:%S", lt))
                        printf("Current time: %s\n", buf);
                    else
                        printf("Current time: [unable to format]\n");
                } else {
                    printf("Current time: [unable to get time]\n");
                }
                break;
            }
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while(choice != 3);
    
    return 0;
}