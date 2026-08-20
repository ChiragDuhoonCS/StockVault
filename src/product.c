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
   
void searchProduct(struct Product inventory[], int count) {
    int searchId;
    int found = 0;

    printf("Enter ID to search: \n");
    scanf("%d", &searchId);

    for (int i = 0; i < count; i++)
    {
        if (inventory[i].product_id == searchId)
        {
             printf("\n----- Your Product Details -----\n");
             printf("Product ID   : %d\n", inventory[i].product_id);
             printf("Name         : %s\n", inventory[i].product_name);
             printf("Category     : %s\n", inventory[i].category);
             printf("Price        : INR %.2f\n", inventory[i].price);
             printf("Quantity     : %d\n", inventory[i].quantity);
             printf("Supplier     : %s\n", inventory[i].supplier);
             printf("---------------------------\n"); 
             found = 1; //! see here
        }
    }

    if (found == 0) {
        printf("Product not found.\n");
    }

}    


void updateProduct(struct Product inventory[], int count) {
    int updateId;
    int found = 0;

    printf("Enter ID to update: \n");
    scanf("%d", &updateId);

 for (int i = 0; i < count; i++)
 {
   if (inventory[i].product_id == updateId){

            
    //PRODUCT ID
    printf("Enter Product ID: ");
    scanf("%d", &inventory[i].product_id);
    getchar();
    
    //PRODUCT NAME
    printf("Enter Product Name: ");
    fgets(inventory[i].product_name, sizeof(inventory[i].product_name), stdin);
    inventory[i].product_name[strcspn(inventory[i].product_name, "\n")] = '\0';

    //CATEGORY
    printf("Enter Category: ");
    fgets(inventory[i].category, sizeof(inventory[i].category), stdin);
    inventory[i].category[strcspn(inventory[i].category, "\n")] = '\0';

    //PRICE
    printf("Enter Price: INR ");
    scanf("%f", &inventory[i].price);
    getchar();

    // QUANTITY
    printf("Enter Quantity: ");
    scanf("%d", &inventory[i].quantity);
    getchar();

    //SUPPLIER NAME
    printf("Enter Supplier Name: ");
    fgets(inventory[i].supplier, sizeof(inventory[i].supplier), stdin);
    inventory[i].supplier[strcspn(inventory[i].supplier, "\n")] = '\0';

    found = 1; //! see here
   }
    }

    if (found == 0) {
        printf("===== Product not found =====\n");
    }

}    

void deleteProduct(struct Product inventory[], int *count) {
    int deleteId;
    int found = 0;

    printf("Enter Product ID to delete: \n");
    scanf("%d", &deleteId);

    for (int i = 0; i < *count; i++)
    {
        if (inventory[i].product_id == deleteId) {

             printf("\n----- Your Delete Product Details  -----\n");
             printf("Product ID   : %d\n", inventory[i].product_id);
             printf("Name         : %s\n", inventory[i].product_name);
             printf("Category     : %s\n", inventory[i].category);
             printf("Price        : INR %.2f\n", inventory[i].price);
             printf("Quantity     : %d\n", inventory[i].quantity);
             printf("Supplier     : %s\n", inventory[i].supplier);
             printf("------------------------------------------\n"); 
            

             for (int j = i; j < *count - 1; j++) {
                inventory[j] = inventory[j + 1];
             }
             (*count)--;

             found = 1;
             break;
        }
    }
         if (found == 0) {
        printf("===== Product not found =====\n");
    }
 }
