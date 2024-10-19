#include<iostream>

using namespace std;

class customer {

public :

	string name;
	int age;
	char gender;
	double credits;

	customer() {
		cout << "\ninsde the default const of the customer class\n";
	}

	customer(string n, int a, char g, double c) {
		cout << "\ninside the parameterised constructor of the \'customer\' class\n" << endl;
		name = n;
		age = a;
		gender = g;
		credits = c;
	}

	void print() {
		cout << "name = " << name << endl;
		cout << "age =  " << age << endl;
		cout << "gender = " << gender << endl;
		cout << "credits = " << credits << endl << endl;
	}

};

int main() {

	customer c1("Ramanujan", 32, 'M', 1729); // parameterised const
	c1.print();

	customer c2 = c1; // copy constr
	c2.print();

	customer c3; // default const
	c3 = c1; // c3.operator=(c1) // copy assignment operator
	c3.print();

	return 0;
}