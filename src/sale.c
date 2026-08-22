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
             
// STEP 1: find the product
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

       
 // STEP 2: find the customer
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
    printf("Product left after sell:  %d \n",(inventory[productCount].quantity - quantity));
}

else {
    printf("Not enough stock! Only %d available. Sale cancelled.\n",
               inventory[productIndex].quantity);
               return;
}
