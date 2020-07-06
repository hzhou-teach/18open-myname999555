/*
 * Jeffrey Chen
 * Time: 25 minutes
 * Test Cases: 10/10
 * Difficulty: 3/10
 * It was really easy for a silver problem. The main concept was noticing that the answer was the maximum distance between the old point and the new point.
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
	const char* FIN = "sort.in";
	const char* FOUT = "sort.out";
	const char* inFile = argc > 1 ? argv[1] : FIN;
	ifstream cin(inFile);
	ofstream cout(FOUT);

	int n;
	cin >> n;
	vector<int> arr(n);
	vector<int> sortArr(n);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		sortArr[i] = arr[i];
	}
	unordered_map<int, int> mapPos;
	sort(sortArr.begin(), sortArr.end());
	for (int i = 0; i < n; ++i) {
		mapPos[sortArr[i]] = i;
	}
	int curMax = 0-mapPos[arr[0]];
	for (int i = 1; i < n; ++i) {

		if (i - mapPos[arr[i]] > curMax) {
			curMax = i - mapPos[arr[i]];
		}
	}
	cout << (curMax + 1) << endl;
	

	return 0;
}