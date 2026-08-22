#ifndef SALE_H
#define SALE_H
#define MAX_SALES 100

//! see here
struct Sale {
    int sale_id; // sale id here
    int product_id;
    int customer_id;
    int quantity_sold;
    float total_price;
};

//! see in sale count
void makeSale(struct Product inventory[], int productCount,
              struct Customer customers[], int customerCount,
              struct Sale sales[], int *saleCount);

//! read only so no *              
void displaySales(struct Sale sales[], int saleCount);

#endif