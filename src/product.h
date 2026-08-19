// "What can the product module do?"

//! So header file dont repeat more than one time
#ifndef PRODUCT_H //"If PRODUCT_H has NOT been defined..."
#define PRODUCT_H //"Define PRODUCT_H now."
#define MAX_PRODUCTS 100

struct Product {
    int product_id;
    char product_name [50];
    char category [50];
    float price;
    int quantity;
    char supplier [100];
   
};

void addProduct(struct Product inventory[], int *count);
void displayProduct(struct Product inventory[], int count);
void searchProduct(struct Product inventory[], int count);

#endif