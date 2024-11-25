#include<stdio.h>
#include<stdlib.h>

int chopsticks[5] = {1, 1, 1, 1, 1}; // 1 indicates the chopstick is available
int mutex = 1; // To ensure mutual exclusion
int philosophers = 5;
int eating[5] = {0, 0, 0, 0, 0}; // Track whether each philosopher is eating

void pick_chopsticks(int philosopher) {
    --mutex;
    if (eating[philosopher] == 1) { // Check if the philosopher is already eating
        printf("Philosopher %d is already eating. They cannot pick up chopsticks again.\n", philosopher + 1);
    } else if (chopsticks[philosopher] == 1 && chopsticks[(philosopher + 1) % philosophers] == 1) {
        chopsticks[philosopher] = chopsticks[(philosopher + 1) % philosophers] = 0;
        eating[philosopher] = 1; // Philosopher is now eating
        printf("Philosopher %d picks up chopsticks %d and %d\n", philosopher + 1, philosopher + 1, (philosopher + 1) % philosophers + 1);
        printf("Philosopher %d is now eating\n", philosopher + 1);
    } else {
        printf("Philosopher %d is waiting for chopsticks\n", philosopher + 1);
    }
    ++mutex;
}

void put_chopsticks(int philosopher) {
    --mutex;
    if (eating[philosopher] == 1) { // Only allow putting down if the philosopher is eating
        chopsticks[philosopher] = chopsticks[(philosopher + 1) % philosophers] = 1;
        eating[philosopher] = 0; // Philosopher stops eating
        printf("Philosopher %d puts down chopsticks %d and %d\n", philosopher + 1, philosopher + 1, (philosopher + 1) % philosophers + 1);
        printf("Philosopher %d is done eating\n", philosopher + 1);
    } else {
        printf("Philosopher %d cannot put down chopsticks because they are not holding any\n", philosopher + 1);
    }
    ++mutex;
}

int main() {
    int choice, philosopher;

    printf("1. Press 1 for Philosopher to Pick Chopsticks\n2. Press 2 for Philosopher to Put Chopsticks\n3. Press 3 to Exit\n");

    while(1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter Philosopher number (1-5): ");
                scanf("%d", &philosopher);
                if (philosopher < 1 || philosopher > 5) {
                    printf("Invalid Philosopher number!\n");
                } else {
                    pick_chopsticks(philosopher - 1);
                }
                break;

            case 2:
                printf("Enter Philosopher number (1-5): ");
                scanf("%d", &philosopher);
                if (philosopher < 1 || philosopher > 5) {
                    printf("Invalid Philosopher number!\n");
                } else {
                    put_chopsticks(philosopher - 1);
                }
                break;

            case 3:
                exit(0);

            default:
                printf("Incorrect option chosen\n");
        }
    }

    return 0;
}
