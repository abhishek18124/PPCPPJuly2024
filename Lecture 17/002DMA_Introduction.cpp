#include<iostream>

using namespace std;

int main() {

	// type* ptr = new type;

	int* iptr = new int;
	*iptr = 50;
	cout << *iptr << endl;

	delete iptr; // releases the memory to which iptr points to

	iptr = new int;
	*iptr = 60;
	cout << *iptr << endl;

	char* chptr = new char;
	*chptr = 'B';
	cout << *chptr << endl;

	double* dptr = new double;
	*dptr = 3.14;
	cout << *dptr << endl;

	string* sptr = new string;
	*sptr = "coding";
	cout << *sptr << endl;

	return 0;
}