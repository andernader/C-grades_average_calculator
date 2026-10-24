#include <stdio.h>
#define GRADE_SIZE_5 5
#define STUDENT_SIZE_5 5

int main(void){
    int students_grades[STUDENT_SIZE_5][GRADE_SIZE_5] = {0};
    int total_grade_for_students[STUDENT_SIZE_5] = {0};
    int total_grade_for_quizzs[GRADE_SIZE_5] = {0};
    int lowest_grade_for_quizzs[GRADE_SIZE_5] = {0};
    int highest_grade_for_quizzs[GRADE_SIZE_5] = {0};

    for(int i = 0; i < STUDENT_SIZE_5; i++){
        printf("Enter the %d grads of the student number %d: ", GRADE_SIZE_5, i);
        for(int j = 0; j < GRADE_SIZE_5; j++)
            scanf("%d", &students_grades[i][j]);
    }

    for(int i = 0; i < STUDENT_SIZE_5; i++){
        for(int j = 0; j < GRADE_SIZE_5; j++){
            total_grade_for_students[i] += students_grades[i][j];
            total_grade_for_quizzs[j] += students_grades[i][j];
        }
    }
    int lowest, highest;
    for(int j = 0; j < GRADE_SIZE_5; j++){
        lowest = highest = students_grades[0][j];
        for(int i = 0; i < STUDENT_SIZE_5; i++){
            if(lowest > students_grades[i][j])
                lowest = students_grades[i][j];
            if(highest < students_grades[i][j])
                highest = students_grades[i][j];
        }
        lowest_grade_for_quizzs[j] = lowest;
        highest_grade_for_quizzs[j] = highest;
    }

    printf("\n\n\n");
    for(int i = 0; i < STUDENT_SIZE_5; i++){
        printf("Student %d's total grade   : %d\n", i, total_grade_for_students[i]);
        printf("student %d's average grade : %.1f\n\n", i, total_grade_for_students[i]/(float)GRADE_SIZE_5);
    }
        printf("\n");
    for(int j = 0; j < GRADE_SIZE_5; j++){
        printf("Quiz %d's average grade    : %.1f\n", j, total_grade_for_quizzs[j]/(float)STUDENT_SIZE_5);
        printf("Quiz %d's lowest grade     : %d\n", j, lowest_grade_for_quizzs[j]);
        printf("Quiz %d's highest grade    : %d\n\n", j, highest_grade_for_quizzs[j]);
    }
    printf("\n\n\n");


    printf("The matrix of the grades:\n\n\n");
    printf("\t\t Q1\t Q2\t Q3\t Q4\t Q5\n\n");
    for(int i = 0; i < STUDENT_SIZE_5; i++){
        printf("Student %d:\t", i);
        for(int j = 0; j < GRADE_SIZE_5; j++){
            printf("%3d\t", students_grades[i][j]);
        }
        printf("\n");
    }
    return 0;
}
