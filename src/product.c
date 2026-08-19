// A actual implementation of the product module
#include<stdio.h>
#include<string.h>
#include "product.h"

//INVENTORY
void addProduct(struct Product inventory[], int *count) { //@ just a name
     if (*count >= MAX_PRODUCTS) {
        printf("Inventory full! Cannot add more products.\n");
        return;
    }

    struct Product p;
    
    //PRODUCT ID
    printf("Enter Product ID: ");
    scanf("%d", &p.product_id);
    getchar();
    
    //PRODUCT NAME
    printf("Enter Product Name: ");
    fgets(p.product_name, sizeof(p.product_name), stdin);
    p.product_name[strcspn(p.product_name, "\n")] = '\0';

    //CATEGORY
    printf("Enter Category: ");
    fgets(p.category, sizeof(p.category), stdin);
    p.category[strcspn(p.category, "\n")] = '\0';

    //PRICE
    printf("Enter Price: INR ");
    scanf("%f", &p.price);
    getchar();

    // QUANTITY
    printf("Enter Quantity: ");
    scanf("%d", &p.quantity);
    getchar();

    //SUPPLIER NAME
    printf("Enter Supplier Name: ");
    fgets(p.supplier, sizeof(p.supplier), stdin);
    p.supplier[strcspn(p.supplier, "\n")] = '\0';

    inventory[*count] = p;
    (*count)++;

}    

void displayProduct(struct Product inventory[], int count) {
    if (count == 0) {
        printf("No products in inventory.\n");
        return;
    }

     printf("\n----- Inventory List -----\n");
    for (int i = 0; i < count; i++) {
        printf("Product ID   : %d\n", inventory[i].product_id);
        printf("Name         : %s\n", inventory[i].product_name);
        printf("Category     : %s\n", inventory[i].category);
        printf("Price        : INR %.2f\n", inventory[i].price);
        printf("Quantity     : %d\n", inventory[i].quantity);
        printf("Supplier     : %s\n", inventory[i].supplier);
        printf("---------------------------\n");
    }
}
   
