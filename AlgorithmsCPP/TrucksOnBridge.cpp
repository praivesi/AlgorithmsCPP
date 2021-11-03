#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	queue<int> wait;
	queue<pair<int, int>> bridge;

	for (int i = 0; i < truck_weights.size(); i++) {
		wait.push(truck_weights[i]);
	}

	int accWeights = 0;
	int moveCnt = 0;
	while (!bridge.empty() || !wait.empty()) {
		if (!bridge.empty()) {
			int mayLeaveTruckWeight = bridge.front().first;
			int mayLeaveTruckMoveCnt = bridge.front().second;
			if ((moveCnt - mayLeaveTruckMoveCnt) == bridge_length) {
				bridge.pop();

				accWeights -= mayLeaveTruckWeight;
			}
		}

		if (!wait.empty()) {
			int enterTruck = wait.front();

			if (accWeights + enterTruck <= weight) {
				accWeights += enterTruck;

				bridge.push(make_pair(enterTruck, moveCnt));
				wait.pop();
			}
		}

		moveCnt++;
	}

	return moveCnt;
}

int main() {
	int bridge_length = 2;
	int weight = 10;
	vector<int> truck_weights{ 7,4,5,6 };

	int ret = solution(bridge_length, weight, truck_weights);

	return ret;
}