/*
Write n C program using union to store vehicle data. The vehicle can be of either petrol or electric.
Based on the type, store and display specific fields such as fuel capacity (for petrol cars) or battery
life (for electric cars).
*/

#include <stdio.h>

typedef struct {
    float fuel_capacity;
} Petrol;

typedef struct {
    int battery_life;
} Electric;

typedef union {
    Petrol p;
    Electric e;
} Vehicle_Data;

typedef struct{
    int type;              // 1 = Petrol, 2 = Electric
    Vehicle_Data data;
} Vehicle;

int main(){
    Vehicle v;

    printf("Enter vehicle type (1 = Petrol, 2 = Electric): ");
    scanf("%d", &v.type);

    if (v.type == 1) {
        printf("Enter fuel capacity (in liters): ");
        scanf("%f", &v.data.p.fuel_capacity);

        printf("\n--- Vehicle Details ---\n");
        printf("Type: Petrol Car\n");
        printf("Fuel Capacity: %.2f liters\n", v.data.p.fuel_capacity);
    }

    else if (v.type == 2) {
        printf("Enter battery life (in km): ");
        scanf("%d", &v.data.e.battery_life);

        printf("\n--- Vehicle Details ---\n");
        printf("Type: Electric Car\n");
        printf("Battery Life: %d km\n", v.data.e.battery_life);
    }
    
    else {
        printf("Invalid vehicle type.\n");
    }

    return 0;
}