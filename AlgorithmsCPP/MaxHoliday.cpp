#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(int leave, string day, vector<int> holidays);
int getHolidayCnt(int start, int leave, vector<int>& holidays, int dayNum);
int getDayNum(string& day);

int main() {
	int leave = 4;
	string day = "FRI";
	vector<int> holidays{ 6, 21, 23, 27, 28 };

	int ret = solution(leave, day, holidays);

	cout << ret << endl;
}

int solution(int leave, string day, vector<int> holidays) {
	int holidayCnt = holidays.size();
	int maxHolidayCnt = holidayCnt;

	int dayNum = getDayNum(day);

	for (int i = 0; i < 30; i++) {
		int candHolidayCnt = getHolidayCnt(i, leave, holidays, dayNum);

		maxHolidayCnt = max(candHolidayCnt, maxHolidayCnt);
	}

	return maxHolidayCnt;
}

int getHolidayCnt(int start, int leave, vector<int>& holidays, int dayNum) {
	bool* isHoliday = new bool[30];

	for (int i = 0; i < 30; i++) {
		if (dayNum == 5 || dayNum == 6) {
			isHoliday[i] = true;
		}
		else {
			isHoliday[i] = false;
		}

		dayNum++;
		dayNum %= 7;
	}

	for (int h : holidays) {
		isHoliday[h - 1] = true;
	}

	int holidayCnt = 0;
	for (int i = start; i < 30; i++) {
		if (isHoliday[i]) {
			holidayCnt++;
			continue;
		}

		if (leave == 0) {
			break;
		}

		holidayCnt++;
		leave--;
	}

	return holidayCnt;
}

int getDayNum(string& day) {
	if (day == "MON") return 0;
	if (day == "TUE") return 1;
	if (day == "WED") return 2;
	if (day == "THU") return 3;
	if (day == "FRI") return 4;
	if (day == "SAT") return 5;
	if (day == "SUN") return 6;

	return -1;
}