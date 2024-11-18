#include<iostream>
#include<stack>

using namespace std;

// time : O(len of str)
// space: O(len of str) e.g. assume input str has only opening brackets

bool isBalanced(const string& str) { // we are passing str as a const ref. to avoid copy (expensive for strings)

	stack<char> s;

	for (char ch : str) {
		switch (ch) {
		case '(': s.push(ch); break;
		case '[': s.push(ch); break;
		case '{': s.push(ch); break;
		case ')': if (!s.empty() and s.top() == '(') s.pop(); else return false; break;
		case ']': if (!s.empty() and s.top() == '[') s.pop(); else return false; break;
		case '}': if (!s.empty() and s.top() == '{') s.pop(); else return false; break;
		}
	}

	return s.empty();

}

int main() {

	string str = ")(([{}]))";

	isBalanced(str) ? cout << "balanced!" << endl :
	                       cout << "not balanced!" << endl;

	return 0;
}