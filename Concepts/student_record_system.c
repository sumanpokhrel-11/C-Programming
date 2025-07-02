// Define a struct called Student with members for id (int), name (char array), and gpa (float).

// Create an array of Student structs (e.g., for 3 students).

// Populate the details for each student.

// Print the details of all students

#include <stdio.h>
#include <string.h>

struct Student {
    int id;
    char name[50];
    float gpa;
};

int main() {
    struct Student s1 = {1, "John Doe", 3.28};
    struct Student s2 = {2, "Doe John", 3.98};
    struct Student s3 = {3, "Ram", 4.00};

    struct Student s[3];
    s[0].id = 1;
    s[0].gpa = 3.31;
    strcpy(s[0].name,  "John doe");    
    s[1].id = 2;
    s[1].gpa = 3.34;
    strcpy(s[1].name,  "Ram Lal"); 
    s[2].id = 3;
    s[2].gpa = 2.31;
    strcpy(s[2].name,  "Ram"); 

    for(int i=0; i<3; i++) {
    printf("%s\'s ID is %d who has got %.2f gpa who is of S%d section.\n", s[i].name, s[i].id, s[i].gpa, i);
    }

    return 0;
}