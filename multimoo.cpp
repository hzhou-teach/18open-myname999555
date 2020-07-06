/*
 * Jeffrey Chen
 * Time: 150 minutes
 * Test Cases: 3/10
 * Difficulty: 9/10
 * The first part of the problem was a recursive flood-fill, and I tried doing something similar for the second part but got timed out for a lot of the cases.
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
int n;
int arr[250][250];
int tempArr[250][250];

int recur(int xPos, int yPos, int colour) {
	if (xPos < 0 || xPos >= n || yPos < 0 || yPos >= n || arr[xPos][yPos] != colour) {
		return 0;
	}
	else {
		arr[xPos][yPos] = -1;
		int sum = 1;
		sum+=recur(xPos - 1, yPos, colour);
		sum+=recur(xPos + 1, yPos, colour);
		sum+=recur(xPos, yPos + 1, colour);
		sum+=recur(xPos, yPos - 1, colour);
		return sum;
	}
}

int recurDuo(int xPos, int yPos, int colour1, int colour2) {
	if (xPos < 0 || xPos >= n || yPos < 0 || yPos >= n || (arr[xPos][yPos] != colour1 && arr[xPos][yPos] != colour2)) {
		return 0;
	}
	else {
		arr[xPos][yPos] = -1;
		int sum = 1;
		sum += recurDuo(xPos - 1, yPos, colour1, colour2);
		sum += recurDuo(xPos + 1, yPos, colour1, colour2);
		sum += recurDuo(xPos, yPos + 1, colour1, colour2);
		sum += recurDuo(xPos, yPos - 1, colour1, colour2);
		return sum;
	}
}

int main(int argc, char* argv[]) {
	const char* FIN = "multimoo.in";
	const char* FOUT = "multimoo.out";
	const char* inFile = argc > 1 ? argv[1] : FIN;
	ifstream cin(inFile);
	ofstream cout(FOUT);

	cin >> n;
	set<int> colours;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> arr[i][j];
			tempArr[i][j] = arr[i][j];
			colours.insert(arr[i][j]);
		}
	}
	vector<int> totalColours;
	unordered_map<int, int> pos;
	set<int>::iterator itr;
	int counter = 0;
	for (itr = colours.begin(); itr != colours.end(); ++itr) {
		totalColours.push_back(*itr);
		pos[*itr] = counter;
		++counter;
	}
	vector<set<pair<int, int>>> colourPos(totalColours.size());

	int maxI = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (arr[i][j] == -1) {
				continue;
			}
			pair<int, int> p;
			p.first = i;
			p.second = j;
			colourPos[pos.at(arr[i][j])].insert(p);
			int nums = recur(i, j, arr[i][j]);
			if (nums > maxI) {
				maxI = nums;
			}
		}
	}
	int maxDuo = 0;
	for (int c1 = 0; c1 < totalColours.size(); ++c1) {
		for (int c2 = c1 + 1; c2 < totalColours.size(); ++c2) {
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) {
					arr[i][j] = tempArr[i][j];
				}
			}
			set<pair<int,int>>::iterator itr;
			for (itr = colourPos[c1].begin(); itr != colourPos[c1].end(); ++itr) {
				pair<int, int> nPos = *itr;
				if (arr[nPos.first][nPos.second] != -1) {
					int num = recurDuo(nPos.first, nPos.second, totalColours[c1], totalColours[c2]);
					if (num > maxDuo) {
						maxDuo = num;
					}
				}
			}
			for (itr = colourPos[c2].begin(); itr != colourPos[c2].end(); ++itr) {
				pair<int, int> nPos = *itr;
				if (arr[nPos.first][nPos.second] != -1) {
					int num = recurDuo(nPos.first, nPos.second, totalColours[c1], totalColours[c2]);
					if (num > maxDuo) {
						maxDuo = num;
					}
				}
			}
		}
	}
	cout << maxI << endl;
	cout << maxDuo << endl;
}