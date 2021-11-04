#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> prices) {
	vector<int> ret;
	queue<int> q;
	int seconds = 0;
	int prevPrice = -1;

	int minusCnt = 0;

	for (int i = 0; i < prices.size(); i++)
	{
		if (prevPrice > prices[i]) 
		{
			while (!q.empty()) {
				ret.push_back(q.front() + seconds + 1);
				q.pop();
			}

			seconds = 1;

			minusCnt = 0;
			q.push(minusCnt);

			continue;
		}

		q.push(minusCnt);
		prevPrice = prices[i];
		minusCnt--;
		seconds++;
	}

	while (!q.empty()) {
		ret.push_back(q.front() + seconds + 1);
		q.pop();
	}

	return ret;
}