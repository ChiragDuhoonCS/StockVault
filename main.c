#include<stdio.h>
#include "src/product.h"

int main() {
    printf("====================================\n");
    printf("=          Storage Vault           =\n");
    printf("   Inventory Management System     =\n");
    printf("====================================\n");

    struct Product inventory[MAX_PRODUCTS];
    int count = 0;
    int choice;

    while (1) {
        printf("\n----- Menu -----\n");
        printf("1. Add Product\n");
        printf("2. Display Products\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // clear leftover newline before addProduct's fgets calls

        if (choice == 1) {
            addProduct(inventory, &count);
        } else if (choice == 2) {
            displayProducts(inventory, count);
        } else if (choice == 0) {
            printf("Exiting StockVault. Goodbye!\n");
            break;
        } else {
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}