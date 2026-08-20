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

