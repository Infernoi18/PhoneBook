#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structures
struct Contact {
    char name[50];
    char phone[15];
};

typedef struct Contact Contact;

// Function prototypes
void addContact(Contact *phoneBook, int *size);
void searchByName(Contact *phoneBook, int size, const char *name);
void searchByNumber(Contact *phoneBook, int size, const char *number);
void displayAllContacts(Contact *phoneBook, int size);

int main() {
    int size = 0;
    Contact *phoneBook = NULL;

    while (1) {
        printf("\nPhone Book Menu:\n");
        printf("1. Add Contact\n");
        printf("2. Search by Name\n");
        printf("3. Search by Number\n");
        printf("4. Display All Contacts\n");
        printf("5. Exit\n");

        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact(phoneBook, &size);
                break;
            case 2: {
                char name[50];
                printf("Enter name to search: ");
                scanf("%s", name);
                searchByName(phoneBook, size, name);
                break;
            }
            case 3: {
                char number[15];
                printf("Enter number to search: ");
                scanf("%s", number);
                searchByNumber(phoneBook, size, number);
                break;
            }
            case 4:
                displayAllContacts(phoneBook, size);
                break;
            case 5:
                free(phoneBook);
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

void addContact(Contact *phoneBook, int *size) {
    (*size)++;
    phoneBook = realloc(phoneBook, (*size) * sizeof(Contact));

    if (phoneBook == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    Contact *newContact = &phoneBook[(*size) - 1];
    printf("Enter name: ");
    scanf("%s", newContact->name);
    printf("Enter phone number: ");
    scanf("%s", newContact->phone);

    printf("Contact added successfully.\n");
}

void searchByName(Contact *phoneBook, int size, const char *name) {
    for (int i = 0; i < size; i++) {
        if (strcmp(phoneBook[i].name, name) == 0) {
            printf("Name: %s\n", phoneBook[i].name);
            printf("Phone: %s\n", phoneBook[i].phone);
            return;
        }
    }

    printf("Contact not found.\n");
}

void searchByNumber(Contact *phoneBook, int size, const char *number) {
    for (int i = 0; i < size; i++) {
        if (strcmp(phoneBook[i].phone, number) == 0) {
            printf("Name: %s\n", phoneBook[i].name);
            printf("Phone: %s\n", phoneBook[i].phone);
            return;
        }
    }

    printf("Contact not found.\n");
}

void displayAllContacts(Contact *phoneBook, int size) {
    if (size == 0) {
        printf("Phone book is empty.\n");
        return;
    }

    printf("All Contacts:\n");
    for (int i = 0; i < size; i++) {
        printf("Name: %s\n", phoneBook[i].name);
        printf("Phone: %s\n", phoneBook[i].phone);
        printf("------------\n");
    }
}
