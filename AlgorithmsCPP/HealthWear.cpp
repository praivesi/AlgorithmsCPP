#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve);

int main() {
	int n = 5;
	vector<int> lost{ 2, 4 };
	vector<int> reserve{ 1,3,5 };

	int result = solution(n, lost, reserve);

	cout << "result : " << result << endl;
}

int solution(int n, vector<int> lost, vector<int> reserve) {
	int* clothes = new int[n];

	for (int i = 0; i < n; i++) {
		clothes[i] = 1;
	}

	for (int lo : lost) {
		clothes[lo - 1] -= 1;
	}

	for (int re : reserve) {
		clothes[re - 1] += 1;
	}

	int canPlayCnt = 0;
	for (int i = 0; i < n; i++) {
		if (clothes[i] >= 1) {
			clothes[i] -= 1;
			canPlayCnt++;

			continue;
		}

		if (i != 0 && clothes[i - 1] == 1) {
			clothes[i - 1] -= 1;
			canPlayCnt++;

			continue;
		}

		if (i != n - 1 && clothes[i + 1] == 2) {
			clothes[i + 1] -= 1;
			canPlayCnt++;
		}
	}

	return canPlayCnt;
}