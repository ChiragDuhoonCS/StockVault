#ifndef SALE_H
#define SALE_H
#define MAX_SALES 100

struct Sale {
    int sale_id;
    int product_id;
    int customerid;
    int quantity_sold;
    float total_price;
};

void makeSale(struct Product inventory[], int productCount,
              struct Customer customers[], int customerCount,
              struct Sale sales[], int *saleCount);
void displaySales(struct Sale sales[], int saleCount);

#endif