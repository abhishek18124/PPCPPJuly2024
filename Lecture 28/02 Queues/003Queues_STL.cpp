#include<iostream>
#include<queue>

using namespace std;

int main() {

	queue<int> q;

	cout << "size : " << q.size() << endl;
	cout << "empty : " << q.empty() << endl;

	q.push(10);
	q.push(20);
	q.push(30);

	cout << "size : " << q.size() << endl;
	cout << "front : " << q.front() << endl;
	cout << "back : " << q.back() << endl;

	q.pop();

	cout << "size : " << q.size() << endl;
	cout << "front : " << q.front() << endl;
	cout << "back : " << q.back() << endl;


	q.pop();

	cout << "size : " << q.size() << endl;
	cout << "front : " << q.front() << endl;
	cout << "back : " << q.back() << endl;


	q.pop();
	q.empty() ? cout << "queue is empty!" << endl : cout << "queue is not empty!" << endl;

	return 0;
}