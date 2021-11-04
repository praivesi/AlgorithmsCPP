#include <string>
#include <vector>

#define UNDEFINED -1
#define MAX_N 100

using namespace std;

int solution(int n, vector<vector<int>> costs) {
	int costMap[MAX_N][MAX_N];
	vector<bool> visited(n);

	for (int i = 0; i < n; i++) {
		visited[i] = false;

		for (int j = 0; j < n; j++) {
			costMap[i][j] = UNDEFINED;
		}
	}

	for (int i = 0; i < costs.size(); i++) {
		costMap[costs[i][0]][costs[i][1]] = costs[i][2];
		costMap[costs[i][1]][costs[i][0]] = costs[i][2];
	}

	int totalCost = 0;

	for(int traverse = 0; traverse < n; traverse++){
		if (visited[traverse]) { continue; }
		visited[traverse] = true;

		int minCost = 987654321;
		int minCostVertex = UNDEFINED;

		for (int j = 0; j < n; j++) {
			if (costMap[traverse][j] == UNDEFINED) { continue; }

			if (costMap[traverse][j] < minCost) {
				minCost = costMap[traverse][j];
				minCostVertex = j;

			}
		}

		if (minCostVertex == UNDEFINED) { continue; }

		visited[minCostVertex] = true;
		totalCost += minCost;

		costMap[traverse][minCostVertex] = UNDEFINED;
		costMap[minCostVertex][traverse] = UNDEFINED;
	}

	return totalCost;
}

int main() {
	int n = 5;
	//int n = 4;
	//vector<vector<int>> costs{ {0,1,1},{0,2,2},{1,2,5},{1,3,1},{2,3,8} }; // n = 4
	//vector<vector<int>> costs{ {0,1,5},{1,2,3},{2,3,3},{1,3,2},{0,3,4} }; // n = 4
	vector<vector<int>> costs{ {0,1,1},{3,4,1},{1,2,2},{2,3,4} }; // n = 5

	int ret = solution(n, costs);

	return ret;
}