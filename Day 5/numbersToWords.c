#include <stdio.h>

// Function to print ones digit
void printOnes(int digit) {
    char *ones[] = {"", "One", "Two", "Three", "Four", "Five", 
                   "Six", "Seven", "Eight", "Nine"};
    printf("%s", ones[digit]);
}

// Function to print teens
void printTeens(int num) {
    char *teens[] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen",
                    "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    printf("%s", teens[num - 10]);
}

// Function to print tens
void printTens(int digit) {
    char *tens[] = {"", "", "Twenty", "Thirty", "Forty", "Fifty",
                   "Sixty", "Seventy", "Eighty", "Ninety"};
    printf("%s", tens[digit]);
}

// Main conversion function
void convertToWords(int num) {
    if(num == 0) {
        printf("Zero");
        return;
    }
    
    // Hundreds place
    if(num >= 100) {
        printOnes(num / 100);
        printf(" Hundred ");
        num %= 100;
    }
    
    // Tens and ones place
    if(num >= 20) {
        printTens(num / 10);
        printf(" ");
        printOnes(num % 10);
    } else if(num >= 10) {
        printTeens(num);
    } else {
        printOnes(num);
    }
}

int main() {
    int num;
    
    printf("Enter a number (0-999): ");
    scanf("%d", &num);
    
    if(num < 0 || num > 999) {
        printf("Number out of range!\n");
        return 1;
    }
    
    printf("%d in words: ", num);
    convertToWords(num);
    printf("\n");
    
    return 0;
}