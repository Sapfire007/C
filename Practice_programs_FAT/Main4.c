/*
Develop a C program to manage a dynamic list of customer orders in a restaurant system using
dynamic memory allocation. Define an Order structure with fields orderID, customerName, item,
quantity, and price. Use malloc, realloc, and free to handle memory allocation for an array of Order
records that can expand as new orders are added. Implement functions to add an order, view all
orders, calculate the total cost for each order, and delete an order based on orderID. In main(), allow
the user to interactively manage orders, demonstrating efficient use of dynamic memory allocation
to handle a varying number of records.
*/


#include <stdio.h>
#include <stdlib.h>

struct Order {
    int id;
    char name[50];
    char item[20];
    int qty;
    float price;
};

struct Order *orders = NULL;
int count = 0;

void addOrder(){
    if(count == 0){
        orders = (struct Order*)malloc(sizeof(struct Order));
    } else {
        orders = (struct Order*)realloc(orders, (count + 1) * (sizeof(struct Order)));
    }

    printf("Enter ID, CustomerName, ItemName, Qty, Price: ");
    scanf("%d %s %s %d %f", &orders[count].id, orders[count].name, orders[count].item, &orders[count].qty, &orders[count].price);

    count++;
    printf("Order added!");
}

void viewOrders() {
    printf("\nID\tName\tItem\tQty\tPrice\tTotal\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t%s\t%d\t%.2f\t%.2f\n", orders[i].id, orders[i].name, orders[i].item, orders[i].qty, orders[i].price, (orders[i].qty * orders[i].price));
    }
}

void deleteOrder() {
    int id, found = 0;
    printf("Enter ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (orders[i].id == id) {
            for (int j = i; j < count - 1; j++) {
                orders[j] = orders[j + 1];
            }
            count--;
            
            if (count > 0) 
                orders = (struct Order*)realloc(orders, count * sizeof(struct Order));
            else {
                free(orders);
                orders = NULL;
            }
            found = 1;
            printf("Deleted.\n");
            break;
        }
    }
    if (!found) printf("ID Not Found.\n");
}

int main(){
    int choice;
    while(1) {
        printf("\n1.Add 2.View 3.Delete 4.Exit: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                addOrder();
                break;
            case 2:
                viewOrders();
                break;
            case 3:
                deleteOrder();
                break;
            case 4:
                free(orders);
                return 0;
            default:
                printf("Invalid input please try again!\n");
        }
    }
    return 0;
}