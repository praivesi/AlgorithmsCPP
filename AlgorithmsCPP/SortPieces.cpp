#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands);

int main() {
	vector<int> array { 1, 5, 2, 6, 3, 7, 4 };
	vector<vector<int>> commands { {2,5,3}, {4,4,1}, {1,7,3} };

	vector<int> ret = solution(array, commands);

	for (int r : ret) {
		cout << r << " ";
	}
	cout << endl;
}

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> ret;

	for (vector<int>& command : commands) {
		vector<int> subArr;

		for (int i = command[0] - 1; i <= command[1] - 1; i++) {
			subArr.push_back(array[i]);
		}

		sort(subArr.begin(), subArr.end());

		ret.push_back(subArr[command[2] - 1]);
	}

	return ret;
}