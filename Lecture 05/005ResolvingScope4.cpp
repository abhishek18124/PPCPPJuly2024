#include<iostream>

using namespace std;

int x = 100;

int main() {

	cout << x << endl; // 100

	int x = 10;

	cout << x << endl; // 10

	{
		int x = 30;
		int y = 20;

		cout << x << " " << y << endl; // 30 20

		{

			int x = 40;
			int y = 50;

			cout << x << " " << y << endl; // 40 50

			{

				int z = 60;

				cout << x << " " << y << " " << z << endl; // 40 50 60

			}

		}

		cout << x << " " << y << endl; // 30 20

	}

	cout << x << endl; // 10

	return 0;
}