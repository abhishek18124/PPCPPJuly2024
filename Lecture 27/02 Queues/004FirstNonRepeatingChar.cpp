#include<iostream>
#include<queue>

using namespace std;

int main() {

	int freq[26] = {0};
	char ch;
	queue<char> q;

	while (true) {

		cin >> ch;
		freq[ch - 'a']++;
		if (freq[ch - 'a'] == 1) {
			// current ch is a non-repeating character therefore we should track it in the queue
			q.push(ch);
		}

		// find the 1st non-repeating character after reading 'ch'

		while (!q.empty() and freq[q.front() - 'a'] > 1) {
			// char. at the front of the queue is no longer a non-repeating char.
			q.pop();
		}

		if (q.empty()) {
			// there is no non-repeating ch. in the stream
			cout << -1 << " ";
		} else {
			// whatever is at the fron the queue is the 1st non-repeating character after reading ch
			cout << q.front() << " ";
		}

	}



	return 0;
}