#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "door_struct.h"

#define DOORS_COUNT 15
#define MAX_ID_SEED 10000

void initialize_doors(struct door* doors);

int main() {
    struct door doors[DOORS_COUNT];

    initialize_doors(doors);
    sort(doors, DOORS_COUNT);
    for (int i = 0; i < DOORS_COUNT; i++) {
        doors[i].status = 0;
    }

    print_doors(doors, DOORS_COUNT);
    return 0;
}

// Doors initialization function
// ATTENTION!!!
// DO NOT CHANGE!
void initialize_doors(struct door* doors) {
    srand(time(0));

    int seed = rand() % MAX_ID_SEED;
    for (int i = 0; i < DOORS_COUNT; i++) {
        doors[i].id = (i + seed) % DOORS_COUNT;
        doors[i].status = rand() % 2;
    }
}

void sort(struct door* doors, int n) {
    struct door temp;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (doors[i].id > doors[j].id) {
                temp = doors[i];
                doors[i] = doors[j];
                doors[j] = temp;
            }
        }
    }
}

void print_doors(struct door* doors, int n) {
    for (int i = 0; i < n; i++) {
        printf("Door ID: %02d, Status: %d ", doors[i].id, doors[i].status);
        (doors[i].status == 0) ? printf("CLOSE\n") : printf("OPEN\n");
    }
}
