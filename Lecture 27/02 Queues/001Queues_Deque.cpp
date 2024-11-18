#include<iostream>
#include<deque>

using namespace std;

template <typename T>
class queue {

	deque<T> d;

public:

	void push(T val) {
		d.push_back(val);
	}

	void pop() {
		d.pop_front();
	}

	T front() {
		return d[0]; // d.front()
	}

	int size() {
		return d.size();
	}

	bool empty() {
		return d.empty();
	}

};

int main() {

	queue<int> q;

	cout << "size : " << q.size() << endl; // 0
	cout << "empty : " << q.empty() << endl; // true

	q.push(10);
	q.push(20);
	q.push(30);

	cout << "size : " << q.size() << endl; // 3
	cout << "front : " << q.front() << endl; // 10

	q.pop(); // 10 is popped

	cout << "size : " << q.size() << endl; // 2
	cout << "front : " << q.front() << endl; // 20

	q.pop(); // 20 is popped

	cout << "size : " << q.size() << endl; // 1
	cout << "front : " << q.front() << endl; // 30

	q.pop(); // 30 is popped
	q.empty() ? cout << "queue is empty!" << endl : cout << "queue is not empty!" << endl;

	return 0;
}