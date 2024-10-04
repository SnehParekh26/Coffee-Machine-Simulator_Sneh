#include <stdio.h>   // Standard input-output library

// Define constants for coffee types and ingredients
#define ESPRESSO_BEANS 8       // Grams of coffee beans for Espresso
#define ESPRESSO_WATER 30      // Milliliters of water for Espresso
#define ESPRESSO_PRICE 3.5     // Price of Espresso in AED

#define CAPPUCCINO_BEANS 8     // Grams of coffee beans for Cappuccino
#define CAPPUCCINO_WATER 30    // Milliliters of water for Cappuccino
#define CAPPUCCINO_MILK 70     // Milliliters of milk for Cappuccino
#define CAPPUCCINO_PRICE 4.5   // Price of Cappuccino in AED

#define MOCHA_BEANS 8          // Grams of coffee beans for Mocha
#define MOCHA_WATER 39         // Milliliters of water for Mocha
#define MOCHA_MILK 160         // Milliliters of milk for Mocha
#define MOCHA_CHOCOLATE 30     // Milliliters of chocolate syrup for Mocha
#define MOCHA_PRICE 5.5        // Price of Mocha in AED

#define LOW_THRESHOLD 10       // Minimum ingredient level before alert
#define ADMIN_PASSWORD 1234    // Admin mode password

// Global variables for ingredients and sales
float total_amount = 0;        // Variable to store total sales
int coffee_beans = 100;        // Initial quantity of coffee beans in grams
int water = 500;               // Initial quantity of water in milliliters
int milk = 500;                // Initial quantity of milk in milliliters
int chocolate = 200;           // Initial quantity of chocolate syrup in milliliters

// Function declarations
void orderCoffee();
void adminMode();
void displayMenu();
void checkLowIngredients();

// Main function
int main() {
    int choice;  // Variable to store user's menu selection
    
    while (1) {
        displayMenu();          // Display menu options
        scanf("%d", &choice);   // Get user's choice

        if (choice == 1) orderCoffee();       // Call orderCoffee if choice is 1
        else if (choice == 2) adminMode();    // Call adminMode if choice is 2
        else if (choice == 3) break;          // Exit the program if choice is 3
        else printf("Invalid choice\n");      // Handle invalid input
    }
    return 0;
}
// Function to display the menu
void displayMenu() {
    printf("\n1. Order Coffee\n2. Admin Mode\n3. Exit\nSelect: ");
}

// Function to handle coffee ordering
void orderCoffee() {
    int choice;
    
    // Display coffee options and prices
    printf("\n1. Espresso (%.2f AED)\n2. Cappuccino (%.2f AED)\n3. Mocha (%.2f AED)\n0. Cancel\n", 
}
 