/*
Create a C program to manage vehicle details using a union. Define a union VehicleInfo to store
specific details for different types of vehicles, including car, truck, and motorcycle. The union
should contain members like seatingCapacity for cars, payloadCapacity for trucks, and engineCC
for motorcycles, ensuring only one attribute is used at a time. Create a Vehicle structure containing
a type identifier (e.g., "Car," "Truck," or "Motorcycle"), a VehicleInfo union, and a modelName
string. Implement functions to input and display vehicle details based on type. In main(), create an
array of Vehicle structures to store details for up to 10 vehicles, and demonstrate the program by
displaying appropriate information for each vehicle type.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_VEHICLES 10

enum VehicleType{
    CAR = 1,
    TRUCK = 2,
    MOTORCYCLE = 3,
};

union VehicleInfo{
    int seatingCapacity;
    float payloadCapacity;
    int engineCC;
};

struct Vehicle{
    char modelName[50];
    enum VehicleType type;
    union VehicleInfo info;
};

const char *getTypeString(enum VehicleType type){
    switch(type){
        case CAR:
            return "CAR";
        case TRUCK:
            return "TRUCK";
        case MOTORCYCLE:
            return "MOTORCYCLE";
        default:
            return "UNKNOWN";
    }
}

void inputVehicle(struct Vehicle *v){
    int type_input;
    printf("Enter vehicle type (1:Car, 2:Truck, 3:Motorcycle): ");
    if (scanf("%d", &type_input) != 1 || type_input < 1 || type_input > 3) {
        printf("Invalid type selection.\n");
        exit(EXIT_FAILURE);
    }
    v->type = (enum VehicleType)type_input;

    printf("Enter Model Name: ");
    scanf("%s", v->modelName);

    switch (v->type) {
        case CAR:
            printf("Enter Seating Capacity (integer): ");
            scanf("%d", &v->info.seatingCapacity);
            break;
        case TRUCK:
            printf("Enter Payload Capacity (float in tons): ");
            scanf("%f", &v->info.payloadCapacity);
            break;
        case MOTORCYCLE:
            printf("Enter Engine CC (integer): ");
            scanf("%d", &v->info.engineCC);
            break;
    }
    printf("Details recorded successfully.\n");
}

void displayVehicle(const struct Vehicle *v) {
    printf("\n------------------------------------\n");
    printf("Model: %s (Type: %s)\n", v->modelName, getTypeString(v->type));
    
    switch (v->type) {
        case CAR:
            printf("Specific Detail: Seating Capacity = %d passengers\n", v->info.seatingCapacity);
            break;
        case TRUCK:
            printf("Specific Detail: Payload Capacity = %.2f tons\n", v->info.payloadCapacity);
            break;
        case MOTORCYCLE:
            printf("Specific Detail: Engine CC = %d CC\n", v->info.engineCC);
            break;
        default:
            printf("Error: Unknown vehicle type.\n");
    }
}

int main(){
    struct Vehicle fleet[MAX_VEHICLES];
    int num_vehicles = 0;
    int i;

    printf("--- Vehicle Management System ---\n");
    printf("Entering details for 3 sample vehicles (Max %d).\n", MAX_VEHICLES);
    
    // Input loop for sample data
    for (i = 0; i < 3; i++) {
        printf("\n--- Vehicle %d ---\n", i + 1);
        inputVehicle(&fleet[i]);
        num_vehicles++;
    }

    printf("\n==================================\n");
    printf("Displaying All Vehicle Details:\n");
    
    // Display loop
    for (i = 0; i < num_vehicles; i++) {
        displayVehicle(&fleet[i]);
    }
    printf("\n==================================\n");
    
    return 0;
}