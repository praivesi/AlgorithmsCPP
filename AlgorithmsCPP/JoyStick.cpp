#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int getMoveCnt(vector<char>& arr, int & needMoveCharCnt, int span, bool isLeft);
int getMoveCnt(char c);
int solution(string name);

int main() {
	int ret = solution("JAN");
}

int solution(string name) {
	vector<char> arr;
	
	int needMoveCharCnt = 0;
	for (int i = 0; i < name.length(); i++) {
		arr.push_back(name[i]);

		if (name[i] != 'A') {
			needMoveCharCnt++;
		}
	}

	int ret = -1;
	for (int i = 0; i < arr.size(); i++) {
		int leftNeedCnt = needMoveCharCnt;
		int rightNeedCnt = needMoveCharCnt;

		int leftCnt = getMoveCnt(arr, leftNeedCnt, i, true);
		int rightCnt = getMoveCnt(arr, rightNeedCnt, i, false);

		if (leftNeedCnt == 0 || rightNeedCnt == 0) {
			ret = min(leftCnt, rightCnt);

			break;
		}
	}

	return ret;
}

int getMoveCnt(vector<char> &arr, int & needMoveCharCnt, int span, bool isLeft) {
	int cnt = 0;

	cnt += getMoveCnt(arr[0]);

	if (arr[0] != 'A') {
		needMoveCharCnt--;
	}

	for (int i = 1; i < 1 + span; i++) {
		if (needMoveCharCnt == 0) { break; }

		cnt++;

		int idx = isLeft ? arr.size() - i : i;

		cnt += getMoveCnt(arr[idx]);

		if (arr[idx] != 'A') {
			needMoveCharCnt--;
		}
	}

	return cnt;
}

int getMoveCnt(char c) {
	int num = c - 'A';
	// abcdefghijklmn opqrstuvwxyz
	return num <= 13 ? num : 26 - num;
}