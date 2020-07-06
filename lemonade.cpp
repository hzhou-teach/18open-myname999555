/*
 * Jeffrey Chen
 * Time: 5 minutes
 * Test Cases: 10/10
 * Difficulty: 1/10
 * Easiest silver problem I've ever seen. Sorting by descending order worked.
 * */
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int main(int argc, char* argv[]) {
	const char* FIN = "lemonade.in";
	const char* FOUT = "lemonade.out";
	const char* inFile = argc > 1 ? argv[1] : FIN;
	ifstream cin(inFile);
	ofstream cout(FOUT);

	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end(), greater<int>());
	for (int i = 0; i < n; ++i) {
		if (arr[i] < i) {
			cout << i << endl;
			return 0;
		}
	}
	cout << n << endl;

	return 0;
}