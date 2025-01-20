#include <stdio.h>
#include <string.h>

// Define the structure for storing element information
struct Element {
    int atomicNumber;
    char name[30];
    char symbol[5];
    float atomicMass;
    int group;
    int period;
    char type[20];
};

// Function prototypes
void displayMenu();
void searchByAtomicNumber(struct Element table[], int n, int atomicNumber);
void searchByName(struct Element table[], int n, char name[]);
void displayPeriodicTable(struct Element table[], int n);

int main() {
    // Array to store periodic table elements
    struct Element periodicTable[118] = {
        {1, "Hydrogen", "H", 1.008, 1, 1, "Nonmetal"},
        {2, "Helium", "He", 4.0026, 18, 1, "Noble Gas"},
        {3, "Lithium", "Li", 6.94, 1, 2, "Alkali Metal"},
        {4, "Beryllium", "Be", 9.0122, 2, 2, "Alkaline Earth Metal"},
        {5, "Boron", "B", 10.81, 13, 2, "Metalloid"},
        {6, "Carbon", "C", 12.011, 14, 2, "Nonmetal"},
        {7, "Nitrogen", "N", 14.007, 15, 2, "Nonmetal"},
        {8, "Oxygen", "O", 15.999, 16, 2, "Nonmetal"},
        {9, "Fluorine", "F", 18.998, 17, 2, "Halogen"},
        {10, "Neon", "Ne", 20.180, 18, 2, "Noble Gas"},
        // Add more elements as needed...
    };

    int n = 10; // Current number of elements in the periodic table
    int choice, atomicNumber;
    char name[30];

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter atomic number: ");
                scanf("%d", &atomicNumber);
                searchByAtomicNumber(periodicTable, n, atomicNumber);
                break;

            case 2:
                printf("Enter name of the element: ");
                scanf("%s", name);
                searchByName(periodicTable, n, name);
                break;

            case 3:
                displayPeriodicTable(periodicTable, n);
                break;

            case 4:
                printf("Exiting the program.\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

// Function to display the main menu
void displayMenu() {
    printf("\n--- Periodic Table Explorer ---\n");
    printf("1. Search by Atomic Number\n");
    printf("2. Search by Name\n");
    printf("3. Display Full Periodic Table\n");
    printf("4. Exit\n");
}

// Function to search for an element by its atomic number
void searchByAtomicNumber(struct Element table[], int n, int atomicNumber) {
    for (int i = 0; i < n; i++) {
        if (table[i].atomicNumber == atomicNumber) {
            printf("\nElement Found:\n");
            printf("Name: %s\n", table[i].name);
            printf("Symbol: %s\n", table[i].symbol);
            printf("Atomic Mass: %.3f\n", table[i].atomicMass);
            printf("Group: %d\n", table[i].group);
            printf("Period: %d\n", table[i].period);
            printf("Type: %s\n", table[i].type);
            return;
        }
    }
    printf("Element with atomic number %d not found.\n", atomicNumber);
}

// Function to search for an element by its name
void searchByName(struct Element table[], int n, char name[]) {
    for (int i = 0; i < n; i++) {
        if (strcasecmp(table[i].name, name) == 0) { // Case-insensitive comparison
            printf("\nElement Found:\n");
            printf("Name: %s\n", table[i].name);
            printf("Symbol: %s\n", table[i].symbol);
            printf("Atomic Mass: %.3f\n", table[i].atomicMass);
            printf("Group: %d\n", table[i].group);
            printf("Period: %d\n", table[i].period);
            printf("Type: %s\n", table[i].type);
            return;
        }
    }
    printf("Element with name '%s' not found.\n", name);
}

// Function to display the full periodic table
void displayPeriodicTable(struct Element table[], int n) {
    printf("\n--- Periodic Table ---\n");
    printf("Atomic Number | Name       | Symbol | Atomic Mass | Group | Period | Type\n");
    printf("---------------------------------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%13d | %-10s | %-6s | %11.3f | %5d | %6d | %-15s\n",
               table[i].atomicNumber, table[i].name, table[i].symbol,
               table[i].atomicMass, table[i].group, table[i].period, table[i].type);
    }
}
