#include <iostream>

using namespace std;

class Tool {
	protected: int strength;
		   char type;
	
	private:
		   //Tool(int str, char ty) : strength(str),type(ty) {}
		   void setStrength(int strength){ this->strength = strength;}
	public:
		   int getStrength{return strength;}
		   char getType{return type;}

};

/*
	Implement class Scissors
*/

class Scissors : public Tool{
	public:
	Scissors(int str) : strength(str),type('s') {}
	bool fight(Tool tool){
		if(tool.getType() == 'p'){}
		else if(tool.getType() == 'r') {}	
	}

}

/*
	Implement class Paper
*/
class Paper : public Tool{
	public:
	Paper(int str) : strength(str),type('p') {}

}

/*
	Implement class Rock
*/
class Rock : public Tool{
	public:
	Rock(int str, char ty) : strength(str),type('r') {}

}

int main() {
	// Example main function
	// You may add your own testing code if you like

	Scissors s1(5);
	Paper p1(7);
	Rock r1(15);
	cout << s1.fight(p1) << p1.fight(s1) << endl;
	cout << p1.fight(r1) << r1.fight(p1) << endl;
	cout << r1.fight(s1) << s1.fight(r1) << endl;

	return 0;
}
