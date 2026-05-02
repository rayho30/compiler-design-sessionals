#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Node structure
struct symbol {
    char name[10];
    char type[10];
    char kind[20];
    int scope;
    char value[20];
    struct symbol *next;
};

// Global head pointer
struct symbol *head = NULL;

// Search
struct symbol* search(char name[]) {
    struct symbol *temp = head;
    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

// Insert
void insert() {
    char tempName[10];
    printf("Enter name: ");
    scanf("%9s", tempName);

    if (search(tempName) != NULL) {
        printf("Symbol already exists!\n");
        return;
    }

    // Allocate memory for new node
    struct symbol *newNode = (struct symbol*)malloc(sizeof(struct symbol));

    strcpy(newNode->name, tempName);
    printf("Enter type: ");
    scanf("%9s", newNode->type);
    printf("Enter value: ");
    scanf("%19s", newNode->value);

    // Link the new node to the list
    newNode->next = head;
    head = newNode;

    printf("Symbol inserted successfully!\n");
}

// Update value
void update() {
    char name[10];
    printf("Enter symbol name to update: ");
    scanf("%9s", name);

    struct symbol *target = search(name);

    if (target != NULL) {
        printf("Enter new value: ");
        scanf("%19s", target->value);
        printf("Updated successfully!\n");
    } else {
        printf("Symbol not found!\n");
    }
}

// Delete entry
void deleteSymbol() {
    char name[10];
    printf("Enter symbol name to delete: ");
    scanf("%9s", name);

    struct symbol *temp = head, *prev = NULL;

    // Case 1: Head node itself holds the name
    if (temp != NULL && strcmp(temp->name, name) == 0) {
        head = temp->next;
        free(temp);
        printf("Deleted successfully!\n");
        return;
    }

    // Case 2: Search for the name, keep track of prev node
    while (temp != NULL && strcmp(temp->name, name) != 0) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Symbol not found!\n");
        return;
    }

    // Unlink node and free memory
    prev->next = temp->next;
    free(temp);
    printf("Deleted successfully!\n");
}

// Display table
void display() {
    if (head == NULL) {
        printf("Table is empty!\n");
        return;
    }

    struct symbol *temp = head;
    printf("\n%-10s %-10s %-10s\n", "Name", "Type", "Value");
    printf("-----------------------------\n");

    while (temp != NULL) {
        printf("%-10s %-10s %-10s\n", temp->name, temp->type, temp->value);
        temp = temp->next;
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n======= SYMBOL TABLE (LINKED LIST) =======\n");
        printf("1. Insert\n2. Display\n3. Search\n4. Update\n5. Delete\n6. Exit\n");
        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input!\n");
            break;
        }

        switch (choice) {
            case 1: insert(); break;
            case 2: display(); break;
            case 3: {
                char name[10];
                printf("Enter name to search: ");
                scanf("%9s", name);
                if (search(name)) printf("Symbol Found!\n");
                else printf("Symbol Not Found!\n");
                break;
            }
            case 4: update(); break;
            case 5: deleteSymbol(); break;
            case 6:
                printf("Exiting...\n");
                return 0;
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}
