/*
Create a structure Book containing fields for book ID, title, author, and price. Write a C
program to create an array of Book structures, allowing users to enter details of multiple books.
Include options to search for books by title and display details of all books costing more than
a specified price.

Sample Input:
Add book: ID = 101, Title = Programming C, Author = Author A, Price =350
Add book: ID = 102, Title = Data Structures, Author = Author B, Price = 500
Search book by title: Programming C
Sample Output:
Book ID: 101, Title: Programming C, Author: Author A, Price: 350
*/


#include <stdio.h>
#include <string.h>

typedef struct {
    int id;
    char title[50];
    char author[50];
    float price;
} Book;

void inputBooks(Book *p, int n) {
    for(int i=0; i<n; i++) {
        printf("\nEnter details of book %d\n", i+1);
        printf("ID: ");
        scanf("%d", &(p+i)->id);

        printf("Title: ");
        scanf(" %[^\n]", (p+i)->title);

        printf("Author: ");
        scanf(" %[^\n]", (p+i)->author);

        printf("Price: ");
        scanf("%f", &(p+i)->price);
    }
}

void searchByTitle(Book *p, int n, char key[]) {
    for(int i=0; i<n; i++) {
        if(strcmp((p+i)->title, key) == 0) {
            printf("\nBook ID: %d, Title: %s, Author: %s, Price: %.2f\n", (p+i)->id, (p+i)->title, (p+i)->author, (p+i)->price);
            return;
        }
    }
    printf("Book not found.\n");
}

void displayAbovePrice(Book *p, int n, float limit) {
    printf("\nBooks costing more than %.2f:\n", limit);
    for(int i=0; i<n; i++) {
        if((p+i)->price > limit) {
            printf("ID: %d, Title: %s, Author: %s, Price: %.2f\n", (p+i)->id, (p+i)->title, (p+i)->author, (p+i)->price);
        }
    }
}

int main() {
    int n;
    printf("Enter number of books: ");
    scanf("%d", &n);

    Book books[n];        // normal array
    Book *ptr = books;    // pointer to the first element

    inputBooks(ptr, n);

    int ch;
    char title[50];
    float price;

    while(1) {
        printf("\n1. Search by Title\n2. Display above price\n3. Exit\nChoose: ");
        scanf("%d", &ch);

        switch(ch) {
            case 1:
                printf("Enter title to search: ");
                scanf(" %[^\n]", title);
                searchByTitle(ptr, n, title);
                break;

            case 2:
                printf("Enter price limit: ");
                scanf("%f", &price);
                displayAbovePrice(ptr, n, price);
                break;

            case 3:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}