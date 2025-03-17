#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    char program[10];
    char sex;
    float grades[5];
}Student;

void inputStudent(Student *s);
void displayStudents(const Student studs[], int count);
float computeStudentAverage(Student s);
Student getStudentWithHighestAverage(const Student studs[], int count);
Student getStudentWithHighestAverageInProgram(const Student studs[], int count, char program[]);
Student getStudentByName(const Student studs[], int count, int searchKey[]);
Student getStudentWithHighestGrade(const Student[], int count);

int main(){
    int size;
    printf("Enter number of students: "); scanf("%d", &size);
    getchar();
    Student student[size];

    for(int i=0;i<size;i++){
        printf("Enter for Student %d:\n", i + 1);
        inputStudent(student+i);
    }

    displayStudents(student, size);
    Student highest = getStudentWithHighestAverage(student, size);
    printf("Student with highest average: %s\n", highest.name);
    char program[50];
    printf("Enter program: "); gets(program);
    Student highestInProgram = getStudentWithHighestAverageInProgram(student, size, program);
    if(highestInProgram.grades[0] != -1){
        printf("Student with highest average in %s: %s\n", program, highestInProgram.name);
    }else{
        printf("No student in program %s\n", program);
    }
    
    
    return 0;
    
}

void inputStudent(Student *s){
    printf("Enter Student Name: "); gets((*s).name);
    printf("Enter Program: "); gets((*s).program);
    printf("Enter sex: "); scanf("%c", &(*s).sex);
    for(int i = 0; i < 5; i++){
        printf("Enter grade[%d]: ", i + 1);
        scanf("%f", &(*s).grades[i]);
    }
    getchar();
}

void displayStudents(const Student studs[], int count){
    printf("%-20s|%-20s|%-5s|%-30s", "Name", "Program", "Sex", "Grades");
    printf("\n");
    // printf("=========================================\n");sa
    for(int i=0;i<count;i++){
        printf("%-20s|%-20s|%-5c|", studs[i].name, studs[i].program, studs[i].sex);
        for(int j=0;j<5;j++){
            printf("%6.2f", studs[i].grades[j]);
            if(j != 4){
                printf(", ");
            }
        }

        printf(" (%6.2f) Average Grade.",computeStudentAverage(studs[i]));
        printf("\n");
    }

}

float computeStudentAverage(Student s){
    float avg, count=0, sum = 0;
    for(int i = 0;i<5 ;i++){
        sum += s.grades[i];
        count++;
    }
    avg = sum/count;
    return avg;
}

Student getStudentWithHighestAverage(const Student studs[], int count){
    Student highest = studs[0];
    float highestAvg = computeStudentAverage(highest);
    for(int i=1;i<count;i++){
        float avg = computeStudentAverage(studs[i]);
        if(avg > highestAvg){
            highest = studs[i];
            highestAvg = avg;
        }
    }
    return highest;
}

Student getStudentWithHighestAverageInProgram(const Student studs[], int count, char program[]){
    Student highest = studs[0];
    float highestAvg = computeStudentAverage(highest);
    for(int i=1;i<count;i++){
        if(strcmp(studs[i].program, program) == 0){
            float avg = computeStudentAverage(studs[i]);
            if(avg > highestAvg){
                highest = studs[i];
                highestAvg = avg;
            }
            }else{
            printf("No student in program %s\n", program);
            highest.grades[0] = -1;
        }
    }
    return highest;
}

Student getStudentByName(const Student studs[], int count, int searchKey[]){
    Student student;
    for(int i=0;i<count;i++){
        if(strcmp(studs[i].name, searchKey) == 0){
            student = studs[i];
            return student;
        }
    }
    student.grades[0] = -1;
    return student;
}

Student getStudentWithHighestGrade(const Student studs[], int count){
    Student highest = studs[0];
    float highestGrade = studs[0].grades[0];
    for(int i=1;i<count;i++){
        for(int j=1;j<5;j++){
            if(studs[i].grades[j] > highestGrade){
                highest = studs[i];
                highestGrade = studs[i].grades[j];
            }
        }
    }
    return highest;
}