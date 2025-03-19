#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100

struct Book {
    int id;
    char title[100];
    char author[100];
    int is_issued;
};

struct Book library[MAX_BOOKS];
int book_count = 0;

void addBook() {
    if (book_count < MAX_BOOKS) {
        printf("Enter Book ID: ");
        scanf("%d", &library[book_count].id);
        getchar(); // Consume newline
        printf("Enter Book Title: ");
        fgets(library[book_count].title, 100, stdin);
        library[book_count].title[strcspn(library[book_count].title, "\n")] = 0;
        printf("Enter Author: ");
        fgets(library[book_count].author, 100, stdin);
        library[book_count].author[strcspn(library[book_count].author, "\n")] = 0;
        library[book_count].is_issued = 0;
        book_count++;
        printf("Book added successfully!\n");
    } else {
        printf("Library is full!\n");
    }
}

void displayBooks() {
    if (book_count == 0) {
        printf("No books available.\n");
        return;
    }
    printf("\nList of Books:\n");
    for (int i = 0; i < book_count; i++) {
        printf("ID: %d, Title: %s, Author: %s, Status: %s\n", library[i].id, library[i].title, library[i].author, 
               library[i].is_issued ? "Issued" : "Available");
    }
}

void searchBook() {
    int id;
    printf("Enter Book ID to search: ");
    scanf("%d", &id);
    for (int i = 0; i < book_count; i++) {
        if (library[i].id == id) {
            printf("Book Found: ID: %d, Title: %s, Author: %s, Status: %s\n", library[i].id, library[i].title, 
                   library[i].author, library[i].is_issued ? "Issued" : "Available");
            return;
        }
    }
    printf("Book not found!\n");
}

void issueBook() {
    int id;
    printf("Enter Book ID to issue: ");
    scanf("%d", &id);
    for (int i = 0; i < book_count; i++) {
        if (library[i].id == id) {
            if (library[i].is_issued) {
                printf("Book is already issued!\n");
            } else {
                library[i].is_issued = 1;
                printf("Book issued successfully!\n");
            }
            return;
        }
    }
    printf("Book not found!\n");
}

void returnBook() {
    int id;
    printf("Enter Book ID to return: ");
    scanf("%d", &id);
    for (int i = 0; i < book_count; i++) {
        if (library[i].id == id) {
            if (!library[i].is_issued) {
                printf("Book is not issued!\n");
            } else {
                library[i].is_issued = 0;
                printf("Book returned successfully!\n");
            }
            return;
        }
    }
    printf("Book not found!\n");
}

void deleteBook() {
    int id;
    printf("Enter Book ID to delete: ");
    scanf("%d", &id);
    for (int i = 0; i < book_count; i++) {
        if (library[i].id == id) {
            for (int j = i; j < book_count - 1; j++) {
                library[j] = library[j + 1];
            }
            book_count--;
            printf("Book deleted successfully!\n");
            return;
        }
    }
    printf("Book not found!\n");
}

int main() {
    int choice;
    while (1) {
        printf("\nLibrary Management System\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Search Book\n");
        printf("4. Issue Book\n");
        printf("5. Return Book\n");
        printf("6. Delete Book\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: addBook(); break;
            case 2: displayBooks(); break;
            case 3: searchBook(); break;
            case 4: issueBook(); break;
            case 5: returnBook(); break;
            case 6: deleteBook(); break;
            case 7: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}
