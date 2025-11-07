#include <stdio.h>

// Function to reverse a number
int reverseNumber(int num) {
    int reversed = 0;
    while(num != 0) {
        reversed = reversed * 10 + num % 10;
        num /= 10;
    }
    return reversed;
}

// Function to check palindrome
int isPalindrome(int num) {
    return num == reverseNumber(num);
}

int main() {
    int num;
    
    printf("Enter a number: ");
    scanf("%d", &num);
    
    if(isPalindrome(num)) {
        printf("%d is a palindrome.\n", num);
    } else {
        printf("%d is not a palindrome.\n", num);
    }
    
    return 0;
}