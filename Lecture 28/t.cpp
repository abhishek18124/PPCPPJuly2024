#include<iostream>

using namespace std;

class customer {
	string name;
	int age;
public:
	customer(string name, int age) {
		this->name = name;
		this->age = age;
	}

	void print();
};

void customer::print() {
	cout << name << " " << age << endl;
}

int main() {

	customer c("abhishek", 29);
	c.print();

	return 0;
}