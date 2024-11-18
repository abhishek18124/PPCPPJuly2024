#include<iostream>

using namespace std;

class customer {

public :

	string name;
	int age;
	char gender;
	double credits;

};

int main() {

	customer c1;

	c1.name = "Aditya";
	c1.gender = 'M';
	c1.credits = 500;
	c1.age = 21;

	cout << "name = " << c1.name << endl;
	cout << "age = " << c1.age << endl;
	cout << "gender = " << c1.gender << endl;
	cout << "credits = " << c1.credits << endl << endl;

	customer c2;

	cin >> c2.name >> c2.age >> c2.gender >> c2.credits;

	cout << "name = " << c2.name << endl;
	cout << "age = " << c2.age << endl;
	cout << "gender = " << c2.gender << endl;
	cout << "credits = " << c2.credits << endl << endl;

	return 0;
}