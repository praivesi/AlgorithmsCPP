#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> computers);

int main() {
	int n = 3;
	//vector<vector<int>> computers{ {1,1,0}, {1,1,0}, {0,0,1} };
	vector<vector<int>> computers{ {1,1,0}, {1,1,1}, {0,0,1} };

	int result = solution(n, computers);

	cout << "result : " << result << endl;
}

int solution(int n, vector<vector<int>> computers) {
	bool *visited = new bool[n];

	for (int i = 0; i < n; i++) {
		visited[i] = false;
	}

	int networkCnt = 0;

	for (int i = 0; i < n; i++) {
		if (visited[i]) continue;

		queue<int> q;
		q.push(i);

		while (!q.empty()) {
			int curComputer = q.front();
			q.pop();

			visited[curComputer] = true;

			for (int j = 0; j < n; j++) {
				if (visited[j]) continue;
				if (computers[curComputer][j] == 0) continue;

				q.push(j);
			}
		}

		networkCnt++;
	}

	return networkCnt;
}