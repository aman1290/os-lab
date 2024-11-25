#include <stdio.h>
#include <stdbool.h>  // Include for using bool type

bool search(int z, int a[]) {
    for (int i = 0; i < 3; i++) {
        if (a[i] == z) {
            return true;
        }
    }
    return false;
}

int main() {
    int a[3] = {-1, -1, -1};  // Initialize the array to -1 (indicating empty slots)
    int n = 0, i = 0, fault = 0;
    printf("1. Press 1 to insert reference\n2. Press 2 to exit\n");
    int c;
    
    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &c);
        switch (c) {
            case 1: {
                int z;
                printf("Enter the reference: ");
                scanf("%d", &z);
                if (!search(z, a)) {
                    a[i] = z;
                    i = (i + 1) % 3;
                    fault++;
                }
                break;
            }
            case 2:
                // Exit the while loop when the user chooses to exit
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid input\n");
        }
        // Exit the loop if user selects option 2
        if (c == 2) {
            break;
        }
    }
    
    printf("Currently in the queue: ");
    for (i = 0; i < 3; i++) {
        printf("%d ", a[i]);
    }
    printf("\nPage fault: %d\n", fault);  // Correct format specifier
    
    return 0;
}
