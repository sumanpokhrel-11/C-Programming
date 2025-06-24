// **Student Record System**  
//     - Define a `struct Student` with fields like name, roll number, grades  
//     - Add, search, update, and delete records  
//     - Store data in files (`fopen`, `fwrite`, `fread`)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a student's name for safety
#define MAX_NAME_LENGTH 50
#define FILENAME "students.txt"
#define TEMP_FILENAME "temp_students.txt"


struct Student {
    int roll;
    char name[MAX_NAME_LENGTH];
    float marks;
};

// Function to clear input buffer (important after scanf for numbers before char input)
void clear_input_buffer() {
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

void add_student(FILE *fp) {
    struct Student s;
    printf("Enter roll, name, marks: ");
    scanf("%d %s %f", &s.roll, s.name, &s.marks);
    fwrite(&s, sizeof(s), 1, fp);
    printf("Student added.\n");
}

void list_students(FILE *fp) {
    struct Student s;
    rewind(fp);
    printf("List of Students:\n");
    while (fread(&s, sizeof(s), 1, fp))
        printf("Roll: %d\t, Name: %s\t, Marks: %.2f\n", s.roll, s.name, s.marks);
}

void delete_students(void) {
    struct Student s;
    char name_to_delete[MAX_NAME_LENGTH];
    int found = 0; //flag to indicate if name is found.

    // 1. List students to help the user choose
    FILE *read_fp = fopen(FILENAME, "rb"); // Open in read binary mode
    if(read_fp == NULL){
        perror("Error opening file for listing");
        return; // Exit if file cannot be opened for listing
    }
    list_students(read_fp); // This function will rewind its own fp
    fclose(read_fp); // Close after listing

    printf("\n------------Delete Student from record-------------\n");
    printf("Enter the name of the student to delete: ");
    // clear_input_buffer(); // <-- REMOVE THIS LINE HERE. It's causing the extra Enter wait.
    scanf("%s", name_to_delete); // This will correctly read the name after the prompt

    // 2. Open original and temporary files for the deletion process
    FILE *original_fp, *temp_fp;

    original_fp  = fopen(FILENAME, "rb"); // Open original file for reading
    if (original_fp == NULL) {
        perror("Error opening original file for deletion"); // More descriptive message
        return;
    }

    temp_fp = fopen(TEMP_FILENAME, "wb"); // Open temporary file for writing (CRITICAL: use TEMP_FILENAME)
    if (temp_fp == NULL) {
        perror("Error opening temporary file for writing");
        fclose(original_fp);
        return;
    }

    // 3. Read records, copy desired ones to temp file
    while(fread(&s, sizeof(struct Student), 1, original_fp) == 1) {
        // Compare the name from original file with the name to delete
        if(strcmp(name_to_delete, s.name) != 0) { // If names are NOT equal
            fwrite(&s, sizeof(struct Student), 1, temp_fp); // Write to temp file
        }
        else { // If names ARE equal
            found = 1; // Mark that the student was found
            printf("Student '%s' found and marked for deletion.\n", s.name); // Use %s
        }
    }

    // 4. Close files
    fclose(temp_fp);
    fclose(original_fp);

    // 5. Replace original file with temporary file if deletion occurred
    if(found) {
        if(remove(FILENAME) != 0) { // Delete the original file
            perror("Error deleting the original file");
            return;
        }
        if(rename(TEMP_FILENAME, FILENAME) != 0) { // Rename temp to original
            perror("Error renaming the temporary file");
            return;
        }
        printf("Student '%s' successfully deleted.\n", name_to_delete); // Use %s
    }
    else {
        printf("Student '%s' not found.\n", name_to_delete); // Use %s
        remove(TEMP_FILENAME); // Remove temp file if no match was found
    }
}
int main() {
    FILE *fp = fopen("students.txt", "ab+");
    int choice;
    do {
        printf("\n1. Add Student\n2. List Students\n3. Delete Student Record\n0. Exit\nChoice: ");
        scanf("%d", &choice);
        clear_input_buffer();
        if (choice == 1) add_student(fp);
        else if (choice == 2) list_students(fp);
        else if (choice ==3) {
            delete_students(); // Call delete_students without arguments

            // Close the old, now invalid, file pointer
            fclose(fp);
            // Reopen the file to get a fresh, valid file pointer to the new 'students.txt'
            fp = fopen(FILENAME, "ab+");
            if (fp == NULL) {
                perror("Error reopening students.txt after deletion");
                return EXIT_FAILURE; // Exit if file cannot be reopened
            }
        }

    } while (choice != 0);
    fclose(fp);
    return 0;
}
