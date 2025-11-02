#include <stdio.h>
#define SIZE 10   // size of the hash table

int hashTable[SIZE];

// Function to initialize hash table
void initialize() {
    for (int i = 0; i < SIZE; i++)
        hashTable[i] = -1;  // -1 means empty slot
}

// Function to insert a value using linear probing
void insert(int value) {
    int key = value % SIZE;   // hash function
    int i = key;

    // Linear probing
    while (hashTable[i] != -1) {
        i = (i + 1) % SIZE;
        if (i == key) {  // table is full
            printf("Hash table is full! Cannot insert %d\n", value);
            return;
        }
    }

    hashTable[i] = value;
    printf("%d inserted at index %d\n", value, i);
}

// Function to search for a value
void search(int value) {
    int key = value % SIZE;
    int i = key;

    while (hashTable[i] != -1) {
        if (hashTable[i] == value) {
            printf("%d found at index %d\n", value, i);
            return;
        }
        i = (i + 1) % SIZE;
        if (i == key)
            break;
    }

    printf("%d not found in the hash table.\n", value);
}

// Function to display the hash table
void display() {
    printf("\nHash Table:\n");
    for (int i = 0; i < SIZE; i++) {
        if (hashTable[i] != -1)
            printf("Index %d -> %d\n", i, hashTable[i]);
        else
            printf("Index %d -> [Empty]\n", i);
    }
}

int main() {
    int choice, value;

    initialize();  // initialize hash table

    do {
        printf("\n--- Hashing Using Linear Probing ---\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(value);
                break;

            case 2:
                printf("Enter value to search: ");
                scanf("%d", &value);
                search(value);
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 4);

    return 0;
}
