#include <stdio.h>

// Constants for ingredient amounts per coffee type and prices
#define ESPRESSO_BEANS 8
#define ESPRESSO_WATER 30
#define ESPRESSO_PRICE 3.5

#define CAPPUCCINO_BEANS 8
#define CAPPUCCINO_WATER 30
#define CAPPUCCINO_MILK 70
#define CAPPUCCINO_PRICE 4.5

#define MOCHA_BEANS 8
#define MOCHA_WATER 39
#define MOCHA_MILK 160
#define MOCHA_SYRUP 30
#define MOCHA_PRICE 5.5

// Low ingredient thresholds
#define LOW_BEANS_THRESHOLD 10
#define LOW_WATER_THRESHOLD 50
#define LOW_MILK_THRESHOLD 50
#define LOW_SYRUP_THRESHOLD 20

// Admin password
#define ADMIN_PASSWORD 1234

// Total sales variable
double total_amount = 0.0;

// Initial quantities of ingredients in the machine
int beans = 50, water = 300, milk = 200, syrup = 100;

// Function declarations
void order_coffee();
void admin_mode();
void check_ingredients();
void replenish_ingredients();
void change_prices();
void display_ingredients();
void reset_sales();

int main() {
    int option;
    while (1) {
        // Main menu loop
        printf("\n--- Coffee Maker Simulator ---\n");
        printf("1. Order a coffee\n");
        printf("2. Admin mode\n");
        printf("3. Exit\n");
        printf("Select an option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                order_coffee(); // User ordering coffee
                break;
            case 2:
                admin_mode(); // Admin features
                break;
            case 3:
                printf("Exiting the application.\n");
                return 0; // Ends program
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
    return 0;
}

// Handles coffee orders from users
void order_coffee() {
    int coffee_type, confirm;
    double price = 0.0;

    while (1) {
        // Show coffee menu and check availability
        printf("\n--- Coffee Menu ---\n");
        printf("1. Espresso - %.2f AED\n", ESPRESSO_PRICE);
        printf("2. Cappuccino - %.2f AED\n", CAPPUCCINO_PRICE);
        printf("3. Mocha - %.2f AED\n", MOCHA_PRICE);
        printf("0. Cancel\n");
        printf("Select a coffee type: ");
        scanf("%d", &coffee_type);

        if (coffee_type == 0) {
            printf("Order canceled.\n");
            return;
        }

        // Check ingredient availability for each coffee type
        switch (coffee_type) {
            case 1:
                if (beans >= ESPRESSO_BEANS && water >= ESPRESSO_WATER) {
                    printf("You selected Espresso - %.2f AED\n", ESPRESSO_PRICE);
                    price = ESPRESSO_PRICE;
                } else {
                    printf("Espresso unavailable due to low ingredients.\n");
                    continue;
                }
                break;
            case 2:
                if (beans >= CAPPUCCINO_BEANS && water >= CAPPUCCINO_WATER && milk >= CAPPUCCINO_MILK) {
                    printf("You selected Cappuccino - %.2f AED\n", CAPPUCCINO_PRICE);
                    price = CAPPUCCINO_PRICE;
                } else {
                    printf("Cappuccino unavailable due to low ingredients.\n");
                    continue;
                }
                break;
            case 3:
                if (beans >= MOCHA_BEANS && water >= MOCHA_WATER && milk >= MOCHA_MILK && syrup >= MOCHA_SYRUP) {
                    printf("You selected Mocha - %.2f AED\n", MOCHA_PRICE);
                    price = MOCHA_PRICE;
                } else {
                    printf("Mocha unavailable due to low ingredients.\n");
                    continue;
                }
                break;
            default:
                printf("Invalid selection. Please try again.\n");
                continue;
        }

        // Confirm order
        printf("Confirm your order? (1 for Yes, 0 for No): ");
        scanf("%d", &confirm);

        if (confirm == 1) {
            double payment = 0.0;
            printf("Please pay %.2f AED (1 or 0.5 AED coins):\n", price);
            while (payment < price) {
                // Ask user to insert coins and validate input
                double coin;
                printf("Insert coin: ");
                scanf("%lf", &coin);
                if (coin == 1 || coin == 0.5) {
                    payment += coin;
                    printf("You have paid: %.2f AED\n", payment);
                } else {
                    printf("Invalid coin. Please collect it and insert a valid one.\n");
                }
            }
            double change = payment - price;
            if (change > 0) {
                printf("Collect your change: %.2f AED\n", change);
            }
            total_amount += price;

            // Update ingredient quantities
            switch (coffee_type) {
                case 1:
                    beans -= ESPRESSO_BEANS;
                    water -= ESPRESSO_WATER;
                    break;
                case 2:
                    beans -= CAPPUCCINO_BEANS;
                    water -= CAPPUCCINO_WATER;
                    milk -= CAPPUCCINO_MILK;
                    break;
                case 3:
                    beans -= MOCHA_BEANS;
                    water -= MOCHA_WATER;
                    milk -= MOCHA_MILK;
                    syrup -= MOCHA_SYRUP;
                    break;
            }

            printf("Enjoy your coffee!\n");

            check_ingredients(); // Check if any ingredient is running low
            return;
        } else {
            printf("Order canceled.\n");
        }
    }
}

// Check if any ingredients are running low and alert the operator
void check_ingredients() {
    if (beans <= LOW_BEANS_THRESHOLD) {
        printf("ALERT: Low coffee beans!\n");
    }
    if (water <= LOW_WATER_THRESHOLD) {
        printf("ALERT: Low water!\n");
    }
    if (milk <= LOW_MILK_THRESHOLD) {
        printf("ALERT: Low milk!\n");
    }
    if (syrup <= LOW_SYRUP_THRESHOLD) {
        printf("ALERT: Low syrup!\n");
    }
}

// Admin mode for managing the coffee machine
void admin_mode() {
    int password, admin_option;
    printf("Enter admin password: ");
    scanf("%d", &password);

    if (password != ADMIN_PASSWORD) {
        printf("Incorrect password.\n");
        return;
    }

    while (1) {
        // Admin menu options
        printf("\n--- Admin Mode ---\n");
        printf("1. Display ingredients and total sales\n");
        printf("2. Replenish ingredients\n");
        printf("3. Change coffee prices\n");
        printf("4. Reset total sales\n");
        printf("0. Exit Admin Mode\n");
        printf("Select an option: ");
        scanf("%d", &admin_option);

        switch (admin_option) {
            case 1:
                display_ingredients(); // Show current ingredient levels and total sales
                break;
            case 2:
                replenish_ingredients(); // Refill ingredients in the machine
                break;
            case 3:
                change_prices(); // Change coffee prices (not implemented in this version)
                break;
            case 4:
                reset_sales(); // Reset total sales amount to zero
                break;
            case 0:
                printf("Exiting Admin Mode.\n");
                return;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
}

// Display current ingredient levels and total sales
void display_ingredients() {
    printf("\nIngredients status:\n");
    printf("Coffee beans: %d grams\n", beans);
    printf("Water: %d milliliters\n", water);
    printf("Milk: %d milliliters\n", milk);
    printf("Syrup: %d milliliters\n", syrup);
    printf("Total sales: %.2f AED\n", total_amount);
}

// Replenish all ingredients in the machine (manual reset)
void replenish_ingredients() {
    beans = 50;
    water = 300;
    milk = 200;
    syrup = 100;
    printf("Ingredients have been replenished.\n");
}

// Placeholder function for changing coffee prices (not implemented yet)
void change_prices() {
    printf("Changing prices is not implemented in this demo.\n");
}

// Reset the total sales amount to zero
void reset_sales() {
    total_amount = 0.0;
    printf("Total sales have been reset.\n");
}
