# Hashes (via Hash Tables)

Hash tables are data structures that implement an associative array abstract data type, mapping keys to values. They use a hash function to compute an index into an array of buckets or slots, from which the desired value can be found.

---

## Build a Basic Hash Table Using Arrays and Structs

A simple hash table can be built using an array where each element is a pointer to a linked list (to handle collisions).

### Example: Basic Hash Table in C

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10 // Our fixed-size array for the hash table

// Structure for a key-value pair (node in our linked list)
struct Entry {
    char *key;
    int value;
    struct Entry *next; // For chaining
};

// Our hash table array
struct Entry *hashTable[TABLE_SIZE];

// Simple hash function (for demonstration, not cryptographically secure)
unsigned int hash(char *key) {
    unsigned int sum = 0;
    for (int i = 0; key[i] != '\0'; i++) {
        sum += key[i];
    }
    return sum % TABLE_SIZE;
}

// Initialize the hash table
void initHashTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = NULL;
    }
}

// Insert an element
void insert(char *key, int value) {
    unsigned int index = hash(key);

    // Create a new entry
    struct Entry *newEntry = (struct Entry *)malloc(sizeof(struct Entry));
    if (newEntry == NULL) {
        printf("Memory allocation failed for new entry!\n");
        return;
    }
    newEntry->key = strdup(key); // Duplicate key string
    newEntry->value = value;
    newEntry->next = NULL;

    // Handle collision (chaining)
    if (hashTable[index] == NULL) {
        hashTable[index] = newEntry;
    } else {
        // Add to the beginning of the list
        newEntry->next = hashTable[index];
        hashTable[index] = newEntry;
    }
}

// Search for an element
struct Entry *search(char *key) {
    unsigned int index = hash(key);
    struct Entry *current = hashTable[index];

    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            return current; // Found
        }
        current = current->next;
    }
    return NULL; // Not found
}

// Delete an element (simplified - actual deletion can be more complex)
void delete(char *key) {
    unsigned int index = hash(key);
    struct Entry *current = hashTable[index];
    struct Entry *prev = NULL;

    while (current != NULL && strcmp(current->key, key) != 0) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        return; // Key not found
    }

    if (prev == NULL) { // First node in the list
        hashTable[index] = current->next;
    } else {
        prev->next = current->next;
    }
    free(current->key); // Free duplicated key string
    free(current);
}

// Clean up hash table memory
void cleanupHashTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        struct Entry *current = hashTable[i];
        while (current != NULL) {
            struct Entry *temp = current;
            current = current->next;
            free(temp->key);
            free(temp);
        }
        hashTable[i] = NULL;
    }
}

int main() {
    initHashTable();

    insert("apple", 10);
    insert("banana", 20);
    insert("cherry", 30);
    insert("date", 40); // Might collide depending on hash function

    struct Entry *found = search("banana");
    if (found) {
        printf("Found: %s -> %d\n", found->key, found->value);
    } else {
        printf("Banana not found.\n");
    }

    found = search("grape");
    if (found) {
        printf("Found: %s -> %d\n", found->key, found->value);
    } else {
        printf("Grape not found.\n");
    }

    printf("\nDeleting 'cherry'...\n");
    delete("cherry");
    found = search("cherry");
    if (found) {
        printf("Found: %s -> %d\n", found->key, found->value);
    } else {
        printf("Cherry not found after deletion.\n");
    }

    cleanupHashTable(); // Free all allocated memory

    return 0;
}
```

---

## Understand Collision Handling (e.g., Chaining)

- **Collision:** When two different keys hash to the same index.
- **Chaining:** Each slot in the hash table array points to a linked list. If a collision occurs, the new key-value pair is added to the linked list at that index. This is what the example above demonstrates.

---

## Practice Inserting, Searching, Deleting Elements

The example code above provides a basic implementation for inserting, searching, and deleting elements in a hash table.

