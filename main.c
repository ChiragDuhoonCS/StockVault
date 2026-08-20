#include<stdio.h>
#include "src/product.h"

int main() {
    printf("====================================\n");
    printf("=          Storage Vault           =\n");
    printf("   Inventory Management System     =\n");
    printf("====================================\n");

    struct Product inventory[MAX_PRODUCTS]; //@ for inventory in product
    int count = 0;
    int choice;

    while (1) { //@ 1 means always true here  loop will go forever
        printf("\n----- Menu -----\n");
        printf("1. Add Product\n");
        printf("2. Display Products\n");
        printf("3. Search Products\n");
        printf("4. Update Products\n");
        printf("5. Delete Products\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // clear leftover newline before addProduct's fgets calls

        if (choice == 1) { //! & this when we add  or delete
            addProduct(inventory, &count);
        } else if (choice == 2) { //! not & when we only read
            displayProduct(inventory, count);
        } else if (choice == 3) {
            searchProduct(inventory, count);
        }else if (choice == 4) {
            updateProduct(inventory, count); 
        }else if (choice == 5) {
            deleteProduct(inventory,&count); 
        }else if (choice == 0) {
            printf("Exiting StockVault. Goodbye!\n");
            break;
        } else {
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}