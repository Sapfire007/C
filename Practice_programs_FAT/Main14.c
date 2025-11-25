/*
A company hires freelancers for different types of jobs, and the payment structure varies based on
the job types. Writers are paid based on the number of words written (an int). Designers are paid a
fixed project fee (a double). Consultants are paid an hourly rate (a float). Create a C program that:
1. Define a Freelancer structure containing an id, name, job type, and a union to store payment
details.
2. Use the union to hold different payment details based on the job type.
3. Accept inputs for different freelancers and display their details with respective payment
details.
4. Also define a function which takes structure variable as argument and finds who is getting
more payment.
Write a C program to implement the above task.
*/

#include <stdio.h>

struct Freelancer{
    int id;
    char name[50];
    char jobType;
    union {
        int words;
        double fee;
        float hourlyRate;
    } pay;
    float totalPay;
};

void comparePay(struct Freelancer f1, struct Freelancer f2){
    if (f1.totalPay > f2.totalPay){
        printf("\nHighest payment is received by %s (%.2f)\n", f1.name, f1.totalPay);
    } else {
        printf("\nHighest payment is received by %s (%.2f)\n", f2.name, f2.totalPay);
    }
}

int main(){
    int n;
    printf("Enter the number of freelancers: ");
    scanf("%d", &n);

    struct Freelancer f[n];
    
    for(int i = 0; i < n; i++){
        printf("Enter ID of freelancer #%d: ", (i+1));
        scanf("%d", &f[i].id);
        printf("Enter name of freelancer #%d: ", (i+1));
        scanf(" %[^\n]", &f[i].name);
        printf("Enter Job Type (W/D/C): ");
        scanf(" %c", &f[i].jobType);

        if(f[i].jobType == 'W') {
            printf("Enter words written: ");
            scanf("%d", &f[i].pay.words);
            f[i].totalPay = f[i].pay.words * 0.5; // assume Rs.0.5 per word
        }
        else if(f[i].jobType == 'D') {
            printf("Enter project fee: ");
            scanf("%lf", &f[i].pay.fee);
            f[i].totalPay = f[i].pay.fee;
        }
        else if(f[i].jobType == 'C') {
            printf("Enter hourly rate: ");
            scanf("%f", &f[i].pay.hourlyRate);
            f[i].totalPay = f[i].pay.hourlyRate * 5; // assume 5 hrs
        }
        else{
            printf("Invalid Job type!");
            return 1;
        }
    }

    printf("\n--- Freelancer Details ---\n");
    for(int i = 0; i < n; i++) {
        printf("\nID: %d\nName: %s\nJob: %c\n", f[i].id, f[i].name, f[i].jobType);

        if(f[i].jobType == 'W')
            printf("Words: %d\nPayment: %.2f\n", f[i].pay.words, f[i].totalPay);
        else if(f[i].jobType == 'D')
            printf("Project Fee: %.2lf\n", f[i].pay.fee);
        else
            printf("Hourly Rate: %.2f\nPayment: %.2f\n", f[i].pay.hourlyRate, f[i].totalPay);
    }

    // Compare first two freelancers (as required)
    if(n >= 2){
        comparePay(f[0], f[1]);
    }
    return 0;
}