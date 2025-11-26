/*
Write a C program to implement an Inventory Management System with a menu-based
structure. The program should allow users to add, update, delete, and view items. Use arrays to 
store item codes, names, and quantities, ensuring that item codes are unique. Provide an option
to exit the system.

Sample Input: 
Inventory Management System Menu: 
1. Add Item 
2. Update Item Quantity 
3. Delete Item 
4. View Inventory 
5. Exit. 
Enter your choice: 4
Sample Output: 
Current Inventory: Item Code: 101, Name: Apple, Quantity: 60
*/

#include <stdio.h>
#include <string.h>

#define MAX 100

int main(){
    int itemCode[MAX];
    char itemName[MAX][50];
    int quantity[MAX];
    int count = 0;
    int choice;

    while (1) {
        printf("\nInventory Management System Menu:\n");
        printf("1. Add Item\n");
        printf("2. Update Item Quantity\n");
        printf("3. Delete Item\n");
        printf("4. View Inventory\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            // Add Item
            int code, exists = 0;
            char name[50];
            int qty;

            printf("Enter item code: ");
            scanf("%d", &code);

            // Check for duplicate item code
            for (int i = 0; i < count; i++) {
                if (itemCode[i] == code) {
                    exists = 1;
                    break;
                }
            }

            if (exists) {
                printf("Item code already exists! Cannot add.\n");
            } else {
                printf("Enter item name: ");
                scanf("%s", name);
                printf("Enter quantity: ");
                scanf("%d", &qty);

                itemCode[count] = code;
                strcpy(itemName[count], name);
                quantity[count] = qty;
                count++;

                printf("Item added successfully.\n");
            }

        } else if (choice == 2) {
            // Update Quantity
            int code, found = 0;
            printf("Enter item code to update: ");
            scanf("%d", &code);

            for (int i = 0; i < count; i++) {
                if (itemCode[i] == code) {
                    printf("Enter new quantity: ");
                    scanf("%d", &quantity[i]);
                    printf("Quantity updated.\n");
                    found = 1;
                    break;
                }
            }

            if (!found) {
                printf("Item code not found.\n");
            }

        } else if (choice == 3) {
            // Delete Item
            int code, found = 0;
            printf("Enter item code to delete: ");
            scanf("%d", &code);

            for (int i = 0; i < count; i++) {
                if (itemCode[i] == code) {
                    // Shift all elements left
                    for (int j = i; j < count - 1; j++) {
                        itemCode[j] = itemCode[j + 1];
                        strcpy(itemName[j], itemName[j + 1]);
                        quantity[j] = quantity[j + 1];
                    }
                    count--;
                    found = 1;
                    printf("Item deleted.\n");
                    break;
                }
            }

            if (!found) {
                printf("Item code not found.\n");
            }

        } else if (choice == 4) {
            // View Inventory
            if (count == 0) {
                printf("Inventory is empty.\n");
            } else {
                printf("Current Inventory:\n");
                for (int i = 0; i < count; i++) {
                    printf("Item Code: %d, Name: %s, Quantity: %d\n", itemCode[i], itemName[i], quantity[i]);
                }
            }

        } else if (choice == 5) {
            // Exit
            printf("Exiting Inventory System.\n");
            break;

        } else {
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}