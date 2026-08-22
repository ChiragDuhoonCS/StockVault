#include<stdio.h>
#include<string.h>
#include "product.h"
#include "customer.h"
#include "sale.h"

void makeSale(struct Product inventory[], int productCount,
              struct Customer customers[], int customerCount,
              struct Sale sales[], int *saleCount) {
                 if (*saleCount >= MAX_SALES) {
                       printf("Sales list full!\n");
                     return;
              }
             
//! STEP 1: find the product
int productId;
printf("Enter Product ID: ");
scanf("%d", &productId);
getchar();

int productIndex = -1;
for (int i = 0; i < productCount; i++) {
    if (inventory[i].product_id == productId) {
        productIndex = i;
        break;
    }
}

if (productIndex == -1) {
    printf("Product not found. Sale cancelled.\n");
    return;
}

printf("Product found: %s (Price: INR %.2f, Stock: %d)\n",
       inventory[productIndex].product_name,
       inventory[productIndex].price,
       inventory[productIndex].quantity);

       
 //! STEP 2: find the customer
 int customerid;
 printf("Enter Customer ID: ");
scanf("%d", &customerid);
getchar();
    
int customerIndex = -1;
for (int i = 0; i < customerCount; i++)
{
    if (customers[i].customer_id == customerid)
    {
        customerIndex = i;
        break;
    }
}

if (customerIndex == -1) {
    printf("Customer not found.\n");
    return;
}

printf("Customer found: %s (Phone: %s, Credit: %f, Address: %s)\n",
       customers[customerIndex].customer_name,
       customers[customerIndex].phone,
       customers[customerIndex].credit,
       customers[customerIndex].address);


//! STEP 3: ask for quantity, check stock
int quantity;
printf("Enter Quantity to sell: ");
scanf("%d", &quantity);

if (inventory[productIndex].quantity >= quantity)
{
    printf("Enough Product to sell\n");
    printf("Stock: %d \n",inventory[productIndex].quantity);
    printf("Product left after sell:  %d \n",(inventory[productIndex].quantity - quantity));
}

else {
    printf("Not enough stock! Only %d available. Sale cancelled.\n",
               inventory[productIndex].quantity);
               return;
}

//! Total Sale
float totalPrice = inventory[productIndex].price*quantity;
inventory[productIndex].quantity -= quantity;

struct Sale s;
s.sale_id = *saleCount + 1;
s.product_id = inventory[productIndex].product_id;
s.customer_id = customers[customerIndex].customer_id;
s.quantity_sold = quantity;
s.total_price = totalPrice;


sales[*saleCount] = s;
(*saleCount)++;
printf("Sale completed! Total: INR %.2f\n", totalPrice);
}


//! Sale Recept
void displaySales(struct Sale sales[], int saleCount) {
    if (saleCount == 0) {
        printf("No sales recorded.\n");
        return;
    }

    printf("\n----- Sales History -----\n");
    for (int i = 0; i < saleCount; i++) {
        printf("Sale ID       : %d\n", sales[i].sale_id);
        printf("Product ID    : %d\n", sales[i].product_id);
        printf("Customer ID   : %d\n", sales[i].customer_id);
        printf("Quantity Sold : %d\n", sales[i].quantity_sold);
        printf("Total Price   : INR %.2f\n", sales[i].total_price);
        printf("---------------------------\n");
    }
}