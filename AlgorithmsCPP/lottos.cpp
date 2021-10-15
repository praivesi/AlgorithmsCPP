#include <string>
#include <vector>
#include <math.h>
#include <iostream>

using namespace std;

int getRank(int matchCnt);
vector<int> solution(vector<int> lottos, vector<int> win_nums);

int main() {
	vector<int> lottos{ 44,1,0,0,31,25 };
	vector<int> win_nums{ 31,10,45,1,6,19 };

	vector<int> ret = solution(lottos, win_nums);

	cout << "max : " << ret[0] << "/ min : " << ret[1] << endl;
}

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
	int availableCnt = 0;
	int matchCnt = 0;
	for (int lotto : lottos) {
		if (lotto == 0) {
			availableCnt++;
			continue;
		}

		for (int win_num : win_nums) {
			if (lotto == win_num) {
				matchCnt++;
				break;
			}
		}
	}

	int maxMatchCnt = min(matchCnt + availableCnt, 6);
	int minMatchCnt = matchCnt;

	vector<int> ret;

	ret.push_back(getRank(maxMatchCnt));
	ret.push_back(getRank(minMatchCnt));

	return ret;
}

int getRank(int matchCnt) {
	switch (matchCnt) {
	case 6:
		return 1;
	case 5:
		return 2;
	case 4:
		return 3;
	case 3:
		return 4;
	case 2:
		return 5;
	default:
		return 6;
	}
}