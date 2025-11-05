#include <stdio.h>

int main() {
    int amount;
    printf("Enter amount: ");
    scanf("%d", &amount);

    int notes[] = {2000, 500, 200, 100, 50, 20, 10, 5, 1};
    for (int i = 0; i < 9; i++) {
        int count = amount / notes[i];
        if (count > 0) {
            printf("%d x ₹%d\n", count, notes[i]);
            amount %= notes[i];
        }
    }

    return 0;
}