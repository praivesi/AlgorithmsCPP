#include <string>
#include <vector>
#include <queue>

using namespace std;

typedef struct Data {
public:
	int location;
	int priority;

	Data(int location, int priority) {
		this->location = location;
		this->priority = priority;
	}
} Data;

int solution(vector<int> priorities, int location) {
	queue<Data> q;
	vector<int> priorityCnt(10);

	for (int i = 0; i < 10; i++) {
		priorityCnt[i] = 0;
	}

	int curPriority = 0;
	for (int i = 0; i < priorities.size(); i++) {
		q.push(Data(i, priorities[i]));
		priorityCnt[priorities[i]]++;

		curPriority = priorities[i] > curPriority ? priorities[i] : curPriority;
	}

	int printCnt = 0;
	while (!q.empty()) {
		Data d = q.front();
		q.pop();

		if (d.priority < curPriority) {
			q.push(d);
			continue;
		}

		printCnt++;
		priorityCnt[d.priority]--;

		if (d.location == location) {
			break;
		}

		if (priorityCnt[d.priority] == 0) {
			for (int i = d.priority; i > 0; i--) {
				if (priorityCnt[i] != 0) {
					curPriority = i;
					break;
				}
			}
		}
	}

	return printCnt;
}