#include <stdio.h>

struct Student {
    char *name;
    char *course;
};

int main() {
    FILE *file;
    struct Student students[3]; 


    file = fopen("data.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

  
    printf("Enter details for 3 students:\n");
    for (int i = 0; i < 3; i++) {
        printf("\nStudent %d\n", i + 1);

        students[i].name = (char *)malloc(sizeof(char) * 50); 
        if (students[i].name == NULL) {
            printf("Memory allocation failed!\n");
            return 1;
        }

        students[i].course = (char *)malloc(sizeof(char) * 50); 
        if (students[i].course == NULL) {
            printf("Memory allocation failed!\n");
            return 1;
        }

        printf("Name: ");
        scanf("%49s", students[i].name); 

        printf("Course: ");
        scanf("%49s", students[i].course); 


        fprintf(file, "Student %d\nName: %s\nCourse: %s\n\n", i + 1, students[i].name, students[i].course);
    }

    printf("\nStudent details written to file successfully!\n");

 
    fclose(file);

   
    for (int i = 0; i < 3; i++) {
        free(students[i].name);
        free(students[i].course);
    }

    return 0;
}