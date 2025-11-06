#include <stdio.h>

int main() {
    char input[100];
    int isQuit;

    while (1) {
        printf("Enter a line (type 'quit' to exit): ");

        if (fgets(input, sizeof(input), stdin) == NULL) {
            // Handle EOF (Ctrl+D)
            break;
        }
        // Remove newline if present
        int i = 0;
        while (input[i] != '\0') {
            if (input[i] == '\n') {
                input[i] = '\0';
                break;
            }
            i++;
        }

        // Check if user typed "quit"
        char quit[] = "quit";
        isQuit = 1; // assume true until mismatch

        for (i = 0; quit[i] != '\0' || input[i] != '\0'; i++) {
            if (quit[i] != input[i]) {
                isQuit = 0;
                break;
            }
        }

        if (isQuit) {
            break;
        }

        printf("You entered: %s\n", input);
    }

    printf("Goodbye!\n");
    return 0;
}

