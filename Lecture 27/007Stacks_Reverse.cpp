#include<iostream>
#include<stack>

using namespace std;

void print(stack<int> s) {

	while (!s.empty()) {
		cout << s.top() << endl;
		s.pop();
	}

	cout << endl;

}

void insertAtBottom(stack<int>& s, int data) { // s is passed-by-ref

	// base case

	if (s.empty()) {
		s.push(data);
		return;
	}

	// recursive case

	int x = s.top();
	s.pop();

	insertAtBottom(s, data);

	s.push(x);

}

// time : t(n) = t(n-1) + n.c ~ O(n^2)
// space: O(n) due to fn call stk, at any pt. of time only 1 insertAtBottom is called

void reverse(stack<int>& s) {

	// base case

	if (s.empty()) {
		return;
	}

	// recursive case

	int x = s.top();
	s.pop();

	reverse(s); // t(n-1)

	insertAtBottom(s, x); // linear

}

int main() {

	stack<int> s;

	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.push(50);

	print(s);

	reverse(s);

	print(s);

	return 0;
}