#include <stdio.h>

char GRADE_MAP[] = { 'F', 'F', 'F', 'F', 'F', 'F', 'D', 'C', 'B', 'A', 'A'};

typedef struct _Grade {
    char letter;
    int percent;
} Grade;

void setGradeByPercent(Grade * grade, int percent){
    grade->percent = percent;
    grade->letter = GRADE_MAP[percent / 10];
}

void setGradeByLetter(Grade * grade, char letter){
    grade->letter = letter;
    grade->percent = 100 - (letter - 'A') * 10 - 5;
}

void printGrade(Grade * grade){
    printf("Grade: %d: %c\n", grade->percent, grade->letter);
}

int main(){
    Grade g;
    int percent;
    
    printf("Enter two grades separated by a space. Use a percentage for the first and letter for the second: ");
    scanf("%d", &percent);
    scanf("\n");
    
    setGradeByPercent(&g, percent);
    printGrade(&g);
    
    setGradeByLetter(&g, getchar());
    printGrade(&g);
}
