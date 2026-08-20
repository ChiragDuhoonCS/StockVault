#include<stdio.h>
#include<string.h>
#include "customer.h"

void addCustomer(struct Customer customers[], int *count) {
    if (*count >= MAX_CUSTOMERS) {
        printf("⚠ Customer list full! Cannot add more customer ⚠\n");
        printf("PLEASE DELETE SOME CUSTOMER.\n");
        return;
    }

    struct Customer c;

    //CUSTOMER ID
    printf("Enter Customer ID: ");
    scanf("%d", &c.customer_id);
    getchar();
    
    //CUSTOMER NAME
    printf("Enter Customer Name: ");
    fgets(c.customer_name, sizeof(c.customer_name), stdin);
    c.customer_name[strcspn(c.customer_name, "\n")] = '\0';

    //Phone no.
    printf("Enter Phone Number: ");
    fgets(c.phone, sizeof(c.phone), stdin);
    c.phone[strcspn(c.phone, "\n")] = '\0';

    //Email
    printf("Enter Email: ");
    fgets(c.email, sizeof(c.email), stdin);
    c.email[strcspn(c.email, "\n")] = '\0';

    //Address
    printf("Enter Address: ");
    fgets(c.address, sizeof(c.address), stdin);
    c.address[strcspn(c.address, "\n")] = '\0';
}

void displayCustomers(struct Customer customers[], int count) {
    if (count == 0) {
        printf("No Customer in list.\n");
        return;
    }

     printf("\n----- Customer List -----\n");
    for (int i = 0; i < count; i++) {
        printf("\n-------- Your Customers List --------\n");
        printf("Customer ID   : %d\n", customers[i].customer_id);
        printf("Name         : %s\n", customers[i].customer_name);
        printf("Phone     : %s\n", customers[i].phone);
        printf("Email        : INR %.2f\n", customers[i].email);
        printf("Address     : %d\n", customers[i].address);
        printf("---------------------------\n");
    }
}
   
void searchCustomers(struct Customer customers[], int count) {
    int searchId;
    int found = 0;

    printf("Enter Customer Id:  \n");
    scanf("%d", &searchId);

    for (int i = 0; i < count; i++)
    {
        if (customers[i].customer_id == searchId)
        {
         printf("\n-------- Your Customers Details --------\n");
         printf("Customer ID   : %d\n", customers[i].customer_id);
         printf("Name         : %s\n", customers[i].customer_name);
         printf("Phone     : %s\n", customers[i].phone);
         printf("Email        : INR %.2f\n", customers[i].email);
         printf("Address     : %d\n", customers[i].address);
         printf("---------------------------\n");
        }
        
    }
    if (found = 0) {
        printf("===== Customer not found =====\n");
    }
}

void updateCustomer(struct Customer customers[], int count) {
    int updateId;
    int found = 0;

    printf("Enter Customer Id to Update: \n");
    scanf("%d", &updateId);

    for (int i = 0; i < count; i++)
    {
        if (customers[i].customer_id == updateId)
        {
             //CUSTOMER ID
    printf("Enter Customer ID: ");
    scanf("%d", &customers[i].customer_id);
    getchar();
    
    //CUSTOMER NAME
    printf("Enter Customer Name: ");
    fgets(customers[i].customer_name, sizeof(customers[i].customer_name), stdin);
    customers[i].customer_name[strcspn(customers[i].customer_name, "\n")] = '\0';

    //Phone no.
    printf("Enter Phone Number: ");
    fgets(customers[i].phone, sizeof(customers[i].phone), stdin);
    customers[i].phone[strcspn(customers[i].phone, "\n")] = '\0';

    //Email
    printf("Enter Email: ");
    fgets(customers[i].email, sizeof(customers[i].email), stdin);
    customers[i].email[strcspn(customers[i].email, "\n")] = '\0';

    //Address
    printf("Enter Address: ");
    fgets(customers[i].address, sizeof(customers[i].address), stdin);
    customers[i].address[strcspn(customers[i].address, "\n")] = '\0';

    found = 1; //! see here
   }
    }

    if (found == 0) {
        printf("===== Customer not found =====\n");
    }
}    

void deleteCustomer(struct Customer customers[], int *count) {
    int deleteId;
    int found = 0;

    printf("Enter Customer Id to Delete: \n");
    scanf("%d", &deleteId);

    for (int i = 0; i < count; i++)
    {
        if (customers[i].customer_id == deleteId)
        {
         printf("\n-------- Your Deleted Customers Details --------\n");
         printf("Customer ID   : %d\n", customers[i].customer_id);
         printf("Name         : %s\n", customers[i].customer_name);
         printf("Phone     : %s\n", customers[i].phone);
         printf("Email        : INR %.2f\n", customers[i].email);
         printf("Address     : %d\n", customers[i].address);
         printf("--------------------------------------------------\n");

         
             for (int j = i; j < *count - 1; j++) {
                customers[j] = customers[j + 1];
             }
             (*count)--;

             found = 1;
             break;
        }
    }
     if (found == 0) {
        printf("===== Customer not found =====\n");
    }
 }

    


