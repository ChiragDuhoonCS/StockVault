// "What can the product module do?"

#ifndef PRODUCT_H //"If PRODUCT_H has NOT been defined..."
#define PRODUCT_H //"Define PRODUCT_H now."

struct Product {
    int product_id;
    char product_name [50];
    char category [50];
    float price;
    int quantity;
    char supplier [100];
};

#endif