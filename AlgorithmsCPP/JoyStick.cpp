#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int getMoveCnt(vector<char>& arr, int needMoveCharCnt, bool isLeft);
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

	int leftCnt = getMoveCnt(arr, needMoveCharCnt, true);
	int rightCnt = getMoveCnt(arr, needMoveCharCnt, false);

	return min(leftCnt, rightCnt);
}

int getMoveCnt(vector<char> &arr, int needMoveCharCnt, bool isLeft) {
	int cnt = 0;

	cnt += getMoveCnt(arr[0]);

	if (arr[0] != 'A') {
		needMoveCharCnt--;
	}

	for (int i = 1; i < arr.size(); i++) {
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