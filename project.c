#include <stdio.h>
#include <string.h>

// Define food product structure
struct food {
    char name[50];
    double price;
    char condition[10];
    char shop[50];
    char location[50];
};

// Function to display the list of food products
void display_food_products(struct food foods[], int size) {
    printf("Food Products:\n");
    printf("--------------------\n");
    printf("Name\t\tPrice(Ksh.)\tCondition\tShop\t\tLocation\n");
    for (int i = 0; i < size; i++) {
        printf("%d. %s\t%.2f\t\t%s\t%s\t\t%s\n", i+1, foods[i].name, foods[i].price, foods[i].condition, foods[i].shop, foods[i].location);
    }
}

int main() {
    // Define array of food products
    struct food foods[] = {
        {"Bananas", 20.00, "Ripe", "Jane's Fruits", "Section A"},
        {"Mangoes", 30.00, "Ripe", "Jack's Fruits", "Section B"},
        {"Apples", 25.00, "Unripe", "Mike's Grocery", "Section C"},
        {"Oranges", 15.00, "Ripe", "Sally's Fruits", "Section D"},
        {"Pineapples", 50.00, "Ripe", "Tim's Fruits", "Section E"}
    };
    
    // Prompt for user input to access the list
    int access_choice;
    printf("Welcome to The 4 Fathers Market!\n");
    do {
        printf("Do you want to access the list? (1 for YES or 2 for NO): ");
        scanf("%d", &access_choice);
        if (access_choice == 2) {
            printf("Thanks for your response, let us know when you'll need to access us!\n");
            printf("Press any key to continue...");
            getchar();
            printf("\nWelcome to The 4 Fathers Market!\n");
        }
    } while (access_choice != 1);
    
    // Display food products
    display_food_products(foods, sizeof(foods) / sizeof(foods[0]));
    
    // Prompt for user input on preferred food product
    int food_choice;
    printf("\nChoose a food product (1-%d): ", sizeof(foods) / sizeof(foods[0]));
    scanf("%d", &food_choice);
    printf("You chose: %s\n", foods[food_choice-1].name);
    
    // Check if the chosen shop has the preferred food product
    int shop_index = -1;
    for (int i = 0; i < sizeof(foods) / sizeof(foods[0]); i++) {
        if (strcmp(foods[i].shop, foods[food_choice-1].shop) == 0) {
            shop_index = i;
            break;
        }
    }
    
    // Print shop and location information
    if (shop_index != -1) {
        printf("You can find %s at %s in %s.\n", foods[food_choice-1].name, foods[shop_index].shop, foods[shop_index].location);
    } else {
        printf("Sorry, we could not find %s at any of our shops.\n", foods[food_choice-1].name);
    }
    
    return 0;
}
