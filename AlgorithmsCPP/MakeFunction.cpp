#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	int finishedJobNum = -1;
	vector<int> deployCnts;

	for (int i = 0; i < progresses.size(); i++) {
		for (int j = 0; j < progresses.size(); j++) {
			progresses[i] += speeds[i];
		}

		int deployCnt = 0;
		for (int j = 0; j < progresses.size(); j++) {
			if (j <= finishedJobNum) { continue; }

			if (progresses[j] >= 100) {
				deployCnt++;
				finishedJobNum++;
			}

		}

		deployCnts.push_back(deployCnt);
	}
}