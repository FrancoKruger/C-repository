#include <stdio.h>

// Defining a new structure type named 'Person' using typedef
typedef struct {
    char name[50];
    int age;
    float salary;
} Person;

void displayPerson(Person p) {
    printf("Name: %s\n", p.name);
    printf("Age: %d\n", p.age);
    printf("Salary: %.2f\n", p.salary);
}

int main() {
    // Declare and initialize a Person variable
    Person person1;
    
    // Assign values to the person1 variable
    snprintf(person1.name, sizeof(person1.name), "John");
    person1.age = 30;
    person1.salary = 50000.50;

    // Display the properties of the person
    displayPerson(person1);

    // Declare and initialize another Person variable in one line
    Person person2 = {"Jane", 25, 45000.25};

    // Display the properties of the second person
    displayPerson(person2);

    return 0;
}

