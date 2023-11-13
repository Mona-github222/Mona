#include <stdio.h>

// Structure to represent a student
struct Student {
    char name[50];
    char reg_no[20];
    float grades[5];
};

// Function to input information for 5 students
void inputStudentInfo(struct Student students[]) {
    for (int i = 0; i < 5; ++i) {
        printf("Enter student %d's name: ", i + 1);
        scanf("%s", students[i].name);
        printf("Enter %s's registration number: ", students[i].name);
        scanf("%s", students[i].reg_no);

        // Input grades for 5 units
        printf("Enter grades for %s (Networking, C Programming, Data Structures, Economics, Marketing):\n", students[i].name);
        for (int j = 0; j < 5; ++j) {
            printf("Enter grade for unit %d: ", j + 1);
            scanf("%f", &students[i].grades[j]);
        }
    }
}

// Function to calculate and display average, highest, and lowest grades
void displayStatistics(struct Student students[]) {
    for (int i = 0; i < 5; ++i) {
        float sum = 0.0;
        for (int j = 0; j < 5; ++j) {
            sum += students[i].grades[j];
        }
        float average = sum / 5.0;
        printf("\n%s's Average Grade: %.2f\n", students[i].name, average);
    }

    float highest = students[0].grades[0];
    float lowest = students[0].grades[0];

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (students[i].grades[j] > highest) {
                highest = students[i].grades[j];
            }
            if (students[i].grades[j] < lowest) {
                lowest = students[i].grades[j];
            }
        }
    }

    printf("\nHighest Grade: %.2f\n", highest);
    printf("Lowest Grade: %.2f\n", lowest);
}

// Function to search for a specific student by registration number
void searchStudent(struct Student students[]) {
    char searchRegNo[20];
    printf("\nEnter a student's registration number to search for their grades: ");
    scanf("%s", searchRegNo);

    int found = 0;

    for (int i = 0; i < 5; ++i) {
        if (strcmp(students[i].reg_no, searchRegNo) == 0) {
            found = 1;
            printf("\nGrades for %s (Reg No: %s):\n", students[i].name, students[i].reg_no);
            for (int j = 0; j < 5; ++j) {
                printf("Unit %d: %.2f\n", j + 1, students[i].grades[j]);
            }
            break;
        }
    }

    if (!found) {
        printf("\nStudent with registration number %s not found.\n", searchRegNo);
    }
}

int main() {
    struct Student students[5];

    // Input student information
    inputStudentInfo(students);

    // Display statistics
    displayStatistics(students);

    // Search for a specific student
    searchStudent(students);

    return 0;
}
