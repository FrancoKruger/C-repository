#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generate_using_rand() {
    printf("Generating 5 random numbers using rand():\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", rand());
    }
    printf("\n");
}

void generate_using_random() {
    printf("Generating 5 random numbers using random():\n");
    for (int i = 0; i < 5; i++) {
        printf("%ld ", random());
    }
    printf("\n");
}

void generate_using_drand48() {
    printf("Generating 5 random floating-point numbers using drand48():\n");
    for (int i = 0; i < 5; i++) {
        printf("%f ", drand48());
    }
    printf("\n");
}

void generate_random_within_range(int min, int max) {
    printf("Generating 5 random numbers within a range [%d, %d] using rand():\n", min, max);
    for (int i = 0; i < 5; i++) {
        printf("%d ", min + rand() % (max - min + 1));
    }
    printf("\n");
}

int main() {
    // Initialize random seed using the current time
    srand(time(NULL));
    srandom(time(NULL));

    generate_using_rand();
    generate_using_random();
    generate_using_drand48();
    generate_random_within_range(10, 20);

    return 0;
}

