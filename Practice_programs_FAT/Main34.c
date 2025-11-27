/*
A company wants to analyze the salary distribution of its employees for financial planning. The
number of employees n will be provided by the user, and their monthly salaries need to be stored
in an array. To process this data efficiently, the program should use a user-defined function
calAvg() that calculates both the total salary expenditure and the average salary. Since the
computed values to be reflect in the main function, the function should use appropriate passing
mechanism. Finally, the main function should display each employee's salary, the total salary paid
by the company, and the average monthly salary.
*/


#include <stdio.h>

void calcAvg(int n, int arr1[n], int *sum, float *avg){
    *sum = 0;
    for(int i = 0; i < n; i++){
        *sum += arr1[i];
    }
    *avg = (float)(*sum)/n;
}

int main(){
    int n;
    printf("Enter the number of employees: ");
    scanf("%d", &n);
    int arr1[n];
    for(int i = 0; i < n; i++){
        printf("Enter salary of employee #%d: ", (i+1));
        scanf("%d", &arr1[i]);
    }

    for(int i = 0; i < n; i++){
        printf("Salary of employee #%d: %d\n", (i+1), arr1[i]);
    }

    int sum;
    float avg;

    calcAvg(n, arr1, &sum, &avg);

    printf("Total salary paid: %d\n", sum);
    printf("Average salary: %.2f\n", avg);

    return 0;
}