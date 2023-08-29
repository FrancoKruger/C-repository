#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    FILE *file;
    char line[256];

    // Check if a filename was passed as a command-line argument
    if (argc < 2) {
        printf("Please provide the filename as a command-line argument.\n");
        return 1;
    }

    // Open the file
    file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    // Read lines from the file and print them
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }

    // Close the file
    fclose(file);

    return 0;
}

