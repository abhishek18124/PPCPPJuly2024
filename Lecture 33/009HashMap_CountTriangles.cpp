/*
	Given N cartesian points in a 2D plane, count the number of right-angled triangles that
	can be formed such that the base or perpendicular is parallel to the x-axis or y-axis.

	Examples

	Input : {(0, 0),
	         (2, 0),
	         (0, 1)}

	Output: 1

	Input : {(1, 2),
			 (2, 0),
			 (2, 2),
			 (2, 3),
			 (4, 2)}

	Output: 4
*/

#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Point {
public:
	int x;
	int y;

	Point(int x, int y) {
		this->x = x;
		this->y = y;
	}
};

// time : O(n^2)

int countTriangles(const vector<Point>& points) {

	int cnt = 0;

	for (Point p : points) {

		// with 'p' as the pivot, find the no. of valid triangles around 'p'

		int a = 0; // to track no. of points in the 2d plane whose x-coor matches p.x
		int b = 0; // to track no. of points in the 2d plane whose y-coor matches p.y

		for (Point q : points) {
			if (q.x == p.x) {
				a++;
			}
			if (q.y == p.y) {
				b++;
			}
		}

		cnt += (a - 1) * (b - 1);

	}

	return cnt;

}

// time : on avg. O(n) since we are using unordered_map
// time : worst case O(nlogn) if you use map<>
// space: O(n) due to xFreqMap and yFreqMap

int countTrianglesOptimised(const vector<Point>& points) {

	unordered_map<int, int> xFreqMap;
	unordered_map<int, int> yFreqMap;

	for (Point p : points) {
		xFreqMap[p.x]++;
		yFreqMap[p.y]++;
	}

	int cnt = 0;

	for (Point p : points) {

		// with 'p' as the pivot, find the no. of valid triangles around 'p'

		int a = xFreqMap[p.x]; // to track no. of points in the 2d plane whose x-coor matches p.x
		int b = yFreqMap[p.y]; // to track no. of points in the 2d plane whose y-coor matches p.y

		cnt += (a - 1) * (b - 1);

	}

	return cnt;

}

int main() {

	vector<Point> points = {
		Point(1, 2),
		Point(2, 0),
		Point(2, 2),
		Point(2, 3),
		Point(4, 2)
	};

	cout << countTriangles(points) << endl;
	cout << countTrianglesOptimised(points) << endl;

	return 0;
}