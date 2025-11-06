#include <stdio.h>

int main() {
    char password[20];
    char correctPassword[] = "secret123";
    int attempts = 0;
    int maxAttempts = 4;
    int success = 0;
    int i;
    
    do {
        printf("Enter password (attempt %d/%d): ", attempts + 1, maxAttempts);
        scanf("%s", password);
        
        // Manual string comparison
        int match = 1;
        for(i = 0; correctPassword[i] != '\0'; i++) {
            if(password[i] != correctPassword[i]) {
                match = 0;
                break;
            }
        }
        if(match && password[i] == '\0') {
            success = 1;
            break;
        }
        
        attempts++;
        printf("Incorrect password!\n");
    } while(attempts < maxAttempts);
    
    if(success) {
        printf("Access granted\n");
    } else {
        printf("Access denied\n");
    }
    
    return 0;
}