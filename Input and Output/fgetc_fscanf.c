#include <stdio.h>

int main() {

    FILE *file = fopen(argv[1], "r");

    // Read characters from the file using fgetc
    while ((c = fgetc(file)) != EOF) {
        numChars++; // Increment character count

	}

	 // Use fscanf to read formatted input
    while (fscanf(file, "%s %d", name, &age) == 2) {
        // Process the data
        printf("Name: %s, Age: %d\n", name, age);
    }

    fclose(file);



    return 0;
}
