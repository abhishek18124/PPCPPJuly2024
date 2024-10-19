#include<iostream>

using namespace std;

class customer {

public :

	string name;
	int age;
	char gender;
	double credits;

};

void print(customer c) { // object are by default passed by value

	cout << "name = " << c.name << endl;
	cout << "age = " << c.age << endl;
	cout << "gender = " << c.gender << endl;
	cout << "credits = " << c.credits << endl << endl;

}


void printByRef(customer& ref) { // object are by default passed by value

	cout << "name = " << ref.name << endl;
	cout << "age = " << ref.age << endl;
	cout << "gender = " << ref.gender << endl;
	cout << "credits = " << ref.credits << endl << endl;

	ref.age++;

}

void printByConstRef(const customer& ref) { // object are by default passed by value

	cout << "name = " << ref.name << endl;
	cout << "age = " << ref.age << endl;
	cout << "gender = " << ref.gender << endl;
	cout << "credits = " << ref.credits << endl << endl;

	// ref.age++; // error since ref is const

}


int main() {

	customer c1;

	c1.name = "Ramanujan";
	c1.age = 32;
	c1.gender = 'M';
	c1.credits = 1729;


	cout << "c1.age = " << c1.age << endl << endl;

	// print(c1);
	printByRef(c1);

	cout << "c1.age = " << c1.age << endl << endl;

	customer c2;

	c2.name = "Aryabhata";
	c2.age = 74;
	c2.gender = 'M';
	c2.credits = 0;

	cout << "c2.age = " << c2.age << endl << endl;

	// print(c2);
	printByRef(c2);

	cout << "c2.age = " << c2.age << endl << endl;


	return 0;
}