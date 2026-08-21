#ifndef CUSTOMER_H
#define CUSTOMER_H
#define MAX_CUSTOMERS 200

struct Customer {
    int customer_id;
    char customer_name[50];
    char phone[15]; //! to add +
    char email[100];
    char address[100];
    float credit;
};

void addCustomer(struct Customer customers[], int *count);
void displayCustomers(struct Customer customers[], int count);
void searchCustomers(struct Customer customers[], int count);
void updateCustomer(struct Customer customers[], int count);
void deleteCustomer(struct Customer customers[], int *count);
void creditcustomer(struct Customer customers[], int count);




#endif