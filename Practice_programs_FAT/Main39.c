/*
Design a program that uses a union to store information about different types of electronic devices.
A device may be a Mobile, Laptop, or Television. For a mobile, store its RAM and storage; for a
laptop, store its processor and price; for a television, store its screen_size and type. Demonstrate
how memory sharing in a union allows efficient storage based on the device type.
*/

#include <stdio.h>

union DeviceInfo {
    struct {
        int ram;
        int storage;
    } mobile;

    struct {
        char processor[20];
        float price;
    } laptop;

    struct {
        int screen_size;
        char type[20];
    } tv;
};

int main() {
    union DeviceInfo d;
    int choice;

    printf("Select Device Type:\n");
    printf("1. Mobile\n");
    printf("2. Laptop\n");
    printf("3. Television\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    printf("\n");

    switch(choice) {
        case 1:
            printf("Enter Mobile RAM (GB): ");
            scanf("%d", &d.mobile.ram);

            printf("Enter Storage (GB): ");
            scanf("%d", &d.mobile.storage);

            printf("\n--- MOBILE DETAILS ---\n");
            printf("RAM: %d GB\n", d.mobile.ram);
            printf("Storage: %d GB\n", d.mobile.storage);
            break;

        case 2:
            printf("Enter Laptop Processor: ");
            scanf("%s", d.laptop.processor);

            printf("Enter Laptop Price: ");
            scanf("%f", &d.laptop.price);

            printf("\n--- LAPTOP DETAILS ---\n");
            printf("Processor: %s\n", d.laptop.processor);
            printf("Price: %.2f\n", d.laptop.price);
            break;

        case 3:
            printf("Enter TV Screen Size (inches): ");
            scanf("%d", &d.tv.screen_size);

            printf("Enter TV Type (LED/LCD/OLED): ");
            scanf("%s", d.tv.type);

            printf("\n--- TELEVISION DETAILS ---\n");
            printf("Screen Size: %d inches\n", d.tv.screen_size);
            printf("Type: %s\n", d.tv.type);
            break;

        default:
            printf("Invalid choice!\n");
    }

    return 0;
}