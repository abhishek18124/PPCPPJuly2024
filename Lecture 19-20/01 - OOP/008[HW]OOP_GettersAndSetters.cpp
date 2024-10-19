#include<iostream>

using namespace std;

class customer {

private:

	string name;
	int age;
	char gender;
	double credits;

public :

	customer() {
		cout << "\ninside the default constructor of the \'customer\' class\n" << endl;
	}

	string getName() {
		return name;
	}

	void setName(string n) {
		name = n;
	}

	int getAge() {
		return age;
	}

	void setAge(int a) {
		age = a;
	}

	char getGender() {
		return gender;
	}

	void setGender(char g) {
		gender = g;
	}

	double getCredits() {
		return credits;
	}

	void setCredits(double c) {
		credits = c;
	}

	void print() {
		cout << "name = " << name << endl;
		cout << "age = " << age << endl;
		cout << "gender = " << gender << endl;
		cout << "credits = " << credits << endl << endl;
	}
};



int main() {

	customer c;

	c.name = "Ramanujan";
	c.age = 32;
	c.gender = 'M';
	c.credits = 1729;

	c.print();

	return 0;
}