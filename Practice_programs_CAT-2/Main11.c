/*
A transport authority needs to store data about different types of vehicles. 
For Cars, the details include registration number, owner name, and seating capacity. 
For Trucks, the details include registration number, owner name, and load capacity (in tons). 
For Motorcycles, the details include registration number, owner name, and engine capacity (in cc). 
Since all vehicles share common details such as regno, owner name but also have type-specific fields such as seating capacity, fuel type, boot space.
The data structure should use a nested structure with a union to hold the varying details efficiently.
A program should allow adding vehicle records and displaying them based on their type.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Enum for vehicle type
typedef enum {
    CAR,
    TRUCK,
    MOTORCYCLE
} VehicleType;

// Structure for common vehicle info
typedef struct {
    char regno[20];
    char owner[50];
} CommonInfo;

// Union for type-specific details
typedef union {
    struct { // Car details
        int seating_capacity;
    } car;
    struct { // Truck details
        float load_capacity; // in tons
    } truck;
    struct { // Motorcycle details
        int engine_cc; // engine capacity
    } motorcycle;
} VehicleDetails;

// Vehicle structure
typedef struct {
    VehicleType type;
    CommonInfo common;
    VehicleDetails details;
} Vehicle;

// Function to display a vehicle record
void display_vehicle(Vehicle v) {
    printf("\nRegistration Number: %s\nOwner: %s\n", v.common.regno, v.common.owner);
    switch (v.type) {
        case CAR:
            printf("Type: Car\nSeating Capacity: %d\n", v.details.car.seating_capacity);
            break;
        case TRUCK:
            printf("Type: Truck\nLoad Capacity: %.2f tons\n", v.details.truck.load_capacity);
            break;
        case MOTORCYCLE:
            printf("Type: Motorcycle\nEngine Capacity: %dcc\n", v.details.motorcycle.engine_cc);
            break;
    }
}


int main() {
    int n;
    printf("Enter number of vehicles: ");
    scanf("%d", &n);

    Vehicle *vehicles = (Vehicle *)malloc(n * sizeof(Vehicle));
    if (!vehicles) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Input vehicle records
    for (int i = 0; i < n; i++) {
        printf("\nEnter details for vehicle %d:\n", i + 1);
        int type_choice;
        printf("Vehicle Type (0-Car, 1-Truck, 2-Motorcycle): ");
        scanf("%d", &type_choice);
        vehicles[i].type = (VehicleType)type_choice;

        getchar(); // consume newline
        printf("Registration Number: ");
        scanf("%[^\n]", vehicles[i].common.regno);
        getchar(); // consume newline
        printf("Owner Name: ");
        scanf("%[^\n]", vehicles[i].common.owner);

        switch (vehicles[i].type) {
            case CAR:
                printf("Seating Capacity: ");
                scanf("%d", &vehicles[i].details.car.seating_capacity);
                break;
            case TRUCK:
                printf("Load Capacity (tons): ");
                scanf("%f", &vehicles[i].details.truck.load_capacity);
                break;
            case MOTORCYCLE:
                printf("Engine Capacity (cc): ");
                scanf("%d", &vehicles[i].details.motorcycle.engine_cc);
                break;
            default:
                printf("Invalid type!\n");
                i--; // retry input
        }
    }

    // Display vehicles based on type
    int display_choice;
    printf("\nEnter vehicle type to display (0-Car, 1-Truck, 2-Motorcycle): ");
    scanf("%d", &display_choice);
    VehicleType display_type = (VehicleType)display_choice;

    printf("\n--- Vehicle Records ---\n");
    for (int i = 0; i < n; i++) {
        if (vehicles[i].type == display_type) {
            display_vehicle(vehicles[i]);
        }
    }

    free(vehicles);
    return 0;
}