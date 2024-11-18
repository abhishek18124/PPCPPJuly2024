#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>

using namespace std;

// time : O(n) e.g. 1 2 3 4 5 -6 => 2n-1 ops ~ O(n)
// space: O(n) e.g. 1 2 3 4 5 6

vector<int> asteroidCollision(vector<int>& asteroids) {

	stack<int> s;

	for (int ast : asteroids) {

		if (ast < 0 and !s.empty() and s.top() > 0) {

			// collisions will happen

			bool flag = true; // assume ast will survive collisions

			while (!s.empty() and s.top() > 0) {

				// collisions will happen

				if (abs(ast) > s.top()) {

					// s.top() will be destroyed, go to the next iteration

					s.pop();

				} else if (abs(ast) < s.top()) {

					// ast will be destroyed, collisions will stop

					flag = false;
					break;

				} else {

					// abs(ast) is equal to s.top()

					// ast and s.top() both will be destroyed, collisions will stop

					flag = false;
					s.pop();
					break;

				}

			}

			if (flag) {

				// ast has actually survived all the collisions in which it was involved

				s.push(ast);

			}

		} else {

			// no collisions will happen

			s.push(ast);

		}

	}

	vector<int> ans;

	while (!s.empty()) {
		ans.push_back(s.top());
		s.pop();
	}

	reverse(ans.begin(), ans.end());

	return ans;

}

int main() {

	vector<int> asteroids = {7, 3, -4, 5, 2, -8, 2, 4, 1, -4};

	vector<int> ans = asteroidCollision(asteroids);

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
	cout << endl;

	return 0;
}