#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generate_random_text(FILE *file, int length) {
    char characters[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    int i;
    
    for (i = 0; i < length; i++) {
        fprintf(file, "%c", characters[rand() % 62]);
    }
    fprintf(file, "\n");
}

int main(int argc, char *argv[]) {
    FILE *file;

    if (argc < 2) {
        printf("Please provide the filename as a command-line argument.\n");
        return 1;
    }

    file = fopen(argv[1], "w");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    srand(time(NULL));  // Initialize random number generator
    int random_text_length = 50;  // You can set this to any value you like

    generate_random_text(file, random_text_length);

    fclose(file);
    printf("Random text written to %s\n", argv[1]);

    return 0;
}

