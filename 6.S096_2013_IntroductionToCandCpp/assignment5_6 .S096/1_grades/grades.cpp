#include <stdio.h>
char GRADE_MAP[] = { 'F', 'F', 'F', 'F', 'F', 'F', 'D', 'C', 'B', 'A', 'A'};

class Grade{
	public: char *percent; int *letter;

		//methods
		void print(){
		printf("Grade: %d: %c\n", *percent, *letter);
		}
		void setByPercent(int perc){
		    percent=new char;	
		    *percent = perc;
		    *letter = GRADE_MAP[perc / 10];
		}

		void setByLetter(char lett){
		    letter = new int;
		    *letter = lett;
		    *percent = 100 - (lett - 'A') * 10 - 5;
		}

		//Destructor
		~Grade(){
		delete percent;
		delete letter;
		}
}; 

int main() {
    Grade g;
    int percent;

    printf("Enter two grades separated by a space. Use a percentage for the first and letter for the second: ");
    scanf("%d", &percent);
    scanf("\n");

    g.setByPercent(percent);
    g.print();

    g.setByLetter(getchar());
    g.print();

    return 0;
}
