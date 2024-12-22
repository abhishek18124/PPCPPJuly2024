
#include<iostream>
#include<queue>

using namespace std;

string reorganise(string str) {

    int freq[26] = {0};
    for (char ch : str) {
        int idx = ch - 'a';
        freq[idx]++;
    }

    priority_queue<pair<int, char>> maxHeap;

    for (int i = 0; i < 26; i++) {
        if (freq[i] > 0) {
            maxHeap.push({freq[i], i + 'a'});
        }
    }

    // while (!maxHeap.empty()) {
    //     pair<int, char> p = maxHeap.top(); maxHeap.pop();
    //     cout << p.first << " " << p.second << endl;
    // }

    string ans = "";

    while (!maxHeap.empty()) {

        if (maxHeap.size() == 1) {

            pair<int, char> maxPair = maxHeap.top();
            maxHeap.pop();
            if (maxPair.first > 1) {
                ans = "";
            } else {
                ans += maxPair.second;
            }

        } else {
            // maxHeap.size() > 1

            pair<int, char> firstMaxPair = maxHeap.top(); // 5 a
            maxHeap.pop();

            pair<int, char> secondMaxPair = maxHeap.top(); // 4 b
            maxHeap.pop();

            ans += firstMaxPair.second;
            firstMaxPair.first--;

            ans += secondMaxPair.second;
            secondMaxPair.first--;

            if (firstMaxPair.first > 0) {
                maxHeap.push(firstMaxPair);
            }

            if (secondMaxPair.first > 0) {
                maxHeap.push(secondMaxPair);
            }

        }

    }

    return ans;

}

int main() {

    string str = "aaaaaaabbbcc";

    cout << reorganise(str) << endl;

    return 0;
}