#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> deployCnts;

	int pivot = 0;
	int workCnt = 0;
	while (pivot < progresses.size()) {
		for (int i = pivot; i < progresses.size(); i++) {
			progresses[i] += speeds[i];
		}

		workCnt++;

		int curDeployCnt = 0;
		for (int i = pivot; i < progresses.size(); i++) {
			if (progresses[i] < 100) {
				break;
			}

			curDeployCnt++;
			pivot++;
		}

		if (curDeployCnt != 0) {
			deployCnts.push_back(curDeployCnt);
		}
	}

	return deployCnts;
}