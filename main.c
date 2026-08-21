#include<stdio.h>
#include "src/product.h"
#include "src/customer.h"

int main() {
    printf("====================================\n");
    printf("=          Storage Vault           =\n");
    printf("   Inventory Management System     =\n");
    printf("====================================\n");

    struct Product inventory[MAX_PRODUCTS];//@ for product.c
    struct Customer customers[MAX_CUSTOMERS];

    int productCount = 0;
    int customerCount = 0;
    int choice1;
    int choice;

    while (1) { //! means always true  loop will always go
        printf("\n===== Main Menu =====\n");
        printf("1. Product Management\n");
        printf("2. Customer Management\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice1);
        getchar();

        if (choice1 == 1) {
            while (1) {
                printf("\n----- Product Menu -----\n");
                printf("1. Add Product\n");
                printf("2. Display Products\n");
                printf("3. Search Products\n");
                printf("4. Update Products\n");
                printf("5. Delete Products\n");
                printf("0. Back to Main Menu\n");
                printf("\n--------------------------\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);
                getchar();

                if (choice == 1) {
                    addProduct(inventory, &productCount);
                } else if (choice == 2) {
                    displayProduct(inventory, productCount);
                } else if (choice == 3) {
                    searchProduct(inventory, productCount);
                } else if (choice == 4) {
                    updateProduct(inventory, productCount);
                } else if (choice == 5) {
                    deleteProduct(inventory, &productCount);
                } else if (choice == 0) {
                    break;  // back to main menu
                } else {
                    printf("Invalid choice. Try again.\n");
                }
            }
        }
        else if (choice1 == 2) {
            while (1) {
                printf("\n----- Customer Menu -----\n");
                printf("1. Add Customer\n");
                printf("2. Display Customers\n");
                printf("3. Search Customers\n");
                printf("4. Update Customers\n");
                printf("5. Delete Customers\n");
                printf("6. Credit Customers\n");
                printf("0. Back to Main Menu\n");
                printf("\n--------------------------\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);
                getchar();

                if (choice == 1) {
                    addCustomer(customers, &customerCount);
                } else if (choice == 2) {
                    displayCustomers(customers, customerCount);
                } else if (choice == 3) {
                    searchCustomers(customers, customerCount);
                } else if (choice == 4) {
                    updateCustomers(customers, customerCount);
                } else if (choice == 5) {
                    deleteCustomer(customers, &customerCount);
                } else if (choice == 6) {
                    creditcustomer(customers, customerCount);
                } else if (choice == 0) {
                    break;  // back to main menu
                } else {
                    printf("Invalid choice. Try again.\n");
                }
            }
        }
        else if (choice1 == 0) {
            printf("Exiting StockVault. Goodbye!\n");
            break;  // exits the outer loop, program ends
        }
        else {
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}