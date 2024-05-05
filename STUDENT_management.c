#include <stdio.h>
#include <string.h>

// Define a structure to represent a student
struct Student {
    int rollNumber;
    char name[50];
    int age;
};

// Function prototypes
void addStudent(struct Student students[], int *count);
void displayStudents(struct Student students[], int count);
int searchStudentIndex(struct Student students[], int count, int rollNumber);
void deleteStudent(struct Student students[], int *count, int rollNumber);
void bubbleSort(struct Student students[], int count);

int main() {
    struct Student students[100]; // Array to store student information
    int count = 0; // Number of students currently in the system
    
    int choice;
    do {
        printf("\nStudent Management System\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Delete Student\n");
        printf("5. Sort Students by Roll Number\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                addStudent(students, &count);
                break;
            case 2:
                displayStudents(students, count);
                break;
            case 3: {
                int rollNumber;
                printf("Enter Roll Number to search: ");
                scanf("%d", &rollNumber);
                int index = searchStudentIndex(students, count, rollNumber);
                if (index != -1) {
                    printf("Student found:\n");
                    printf("Roll Number: %d, Name: %s, Age: %d\n", students[index].rollNumber, students[index].name, students[index].age);
                } else {
                    printf("Student not found.\n");
                }
                break;
            }
            case 4: {
                int rollNumber;
                printf("Enter Roll Number to delete: ");
                scanf("%d", &rollNumber);
                deleteStudent(students, &count, rollNumber);
                break;
            }
            case 5:
                bubbleSort(students, count);
                printf("Students sorted by Roll Number.\n");
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);
    
    return 0;
}

// Function to add a new student to the system
void addStudent(struct Student students[], int *count) {
    printf("Enter student details:\n");
    printf("Roll Number: ");
    scanf("%d", &students[*count].rollNumber);
    printf("Name: ");
    scanf("%s", students[*count].name);
    printf("Age: ");
    scanf("%d", &students[*count].age);
    
    (*count)++;
}

// Function to display all students in the system
void displayStudents(struct Student students[], int count) {
    printf("Student Details:\n");
    for (int i = 0; i < count; i++) {
        printf("Roll Number: %d, Name: %s, Age: %d\n", students[i].rollNumber, students[i].name, students[i].age);
    }
}

// Function to search for a student by roll number
int searchStudentIndex(struct Student students[], int count, int rollNumber) {
    for (int i = 0; i < count; i++) {
        if (students[i].rollNumber == rollNumber) {
            return i;
        }
    }
    return -1;
}

// Function to delete a student by roll number
void deleteStudent(struct Student students[], int *count, int rollNumber) {
    int index = searchStudentIndex(students, *count, rollNumber);
    if (index != -1) {
        // Shift remaining elements to the left to fill the gap
        for (int i = index; i < *count - 1; i++) {
            students[i] = students[i + 1];
        }
        (*count)--;
        printf("Student with Roll Number %d deleted successfully.\n", rollNumber);
    } else {
        printf("Student with Roll Number %d not found.\n", rollNumber);
    }
}

// Function to sort students by roll number using bubble sort
void bubbleSort(struct Student students[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (students[j].rollNumber > students[j + 1].rollNumber) {
                // Swap the students
                struct Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}
