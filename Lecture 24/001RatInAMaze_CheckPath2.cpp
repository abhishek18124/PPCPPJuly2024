/*

Given a m x n maze with some blocked cells (marked with 'X'), and rat that wants to
go from the src (0, 0) to the dst (m-1, n-1) design a recursive algorithm to

	> check if there exists a path from src to dst

such at each step the rat can only move in the right or down direction.

Constraint

 1 <= m, n < 10

Example
	Input :

		maze = {"0000",
	            "00X0",
	            "000X",
	            "0X00"}

	Output :

		true (Yes, a path exist from src to dst)

*/

#include<iostream>

using namespace std;

bool f(char maze[][10], int m, int n, int i, int j) {

	// base case

	if (i == m || j == n) { // you've gone outside the maze
		return false;
	}

	if (maze[i][j] == 'X') { // you've reached a blocked cell
		return false;
	}

	if (i == m - 1 and j == n - 1) { // you've reached the destn and it is not blocked
		return true;
	}

	// recursive case

	// f(i, j) = check if there exists a path from the (i, j)th cell to the (m-1, n-1)th cell

	// decide the next step

	// // option 1 : move right

	// bool X = f(maze, m, n, i, j + 1);

	// // option 2 : move down

	// bool Y = f(maze, m, n, i + 1, j);

	// return X or Y;

	return f(maze, m, n, i, j + 1) or f(maze, m, n, i + 1, j);

}

int main() {

	char maze[][10] = {
		"0000",
		"0X00",
		"0X0X",
		"0X00"
	};

	int m = 4;
	int n = 4;

	f(maze, m, n, 0, 0) ? cout << "path exists" << endl :
	                           cout << "path doesn't exists" << endl;

	return 0;
}