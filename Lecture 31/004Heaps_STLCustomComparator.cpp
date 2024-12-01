/*

	STL implementation of the min_heap data structure with custom comparator.


*/

#include<iostream>
#include<queue>

using namespace std;

class customer {
public:
	string name;
	int age;
	double credits;
	customer(string name, int age, double credits) {
		this->name = name;
		this->age = age;
		this->credits = credits;
	}
};

class customerAgeComp {
public:

	// // return true if you want a to be ordered before b otherwise return false

	// bool operator()(customer a, customer b) {
	// 	if (a.age < b.age) {
	// 		// we want a to be ordered before b since we are building a minHeap based on age
	// 		return true;
	// 	}
	// 	return false;
	// }

	// return false if you want a to be given more priority than b otherwise return true

	bool operator()(customer a, customer b) {
		if (a.age < b.age) {
			// we want a to be given more priority than b since we are building a minHeap based on age
			return false;
		}
		return true;
	}
};

int main() {

	priority_queue<customer, vector<customer>, customerAgeComp> m; // minHead based on customer age

	// customer c1("Rahul", 20, 100);
	// m.push(c1);

	m.push(customer("Rahul", 20, 100));
	m.push(customer("Parv", 19, 350));
	m.push(customer("Yukta", 21, 250));
	m.push(customer("Aditya", 22, 300));
	m.push(customer("Vaibhav", 17, 1000));
	m.push(customer("Dheeraj", 18, 500));

	cout << m.size() << endl; // 6

	while (!m.empty()) {
		customer c = m.top();
		m.pop();
		cout << c.name << " " << c.age << " " << c.credits << endl;
	}
	// exp o/p :
	// Vaibhav 17
	// Dheeraj 18
	// Parv 19
	// Rahul 20
	// Yukta 21
	// Aditya 22

	cout << endl;

	cout << m.size() << endl; // 0

	return 0;
}