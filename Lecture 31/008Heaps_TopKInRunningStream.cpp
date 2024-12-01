/*

Given an infinite stream of non-negative integers, design an algorithm to output the 
top-K integers every time you encounter -1.

Example : Input = 4, 1, 2, -1, 3, -1 7 0 1 2 -1 8 -1 . . . ; K = 3
          Output = 1 2 4
                   2 3 4
                   3 4 7
                   4 7 8
                   . . .

*/

#include<iostream>
#include<queue>

using namespace std;

int main() {

    int k = 3;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    return 0;
}