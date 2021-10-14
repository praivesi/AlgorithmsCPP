// AlgorithmsCPP.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <conio.h>

using namespace std;

int solution(vector<int> numbers, int target);
void bfs(int curValue, int curIdx, vector<int>& numbers, int target);

int caseCnt;

int main()
{
	caseCnt = 0;

	vector<int> numbers;
	numbers.push_back(1);
	numbers.push_back(1);
	numbers.push_back(1);
	numbers.push_back(1);
	numbers.push_back(1);

	int target = 3;

	int result = solution(numbers, target);

	cout << result << endl;

	_getch();
}

int solution(vector<int> numbers, int target) {
	bfs(numbers[0], 1, numbers, target);
	bfs(-1 * numbers[0], 1, numbers, target);

	return caseCnt;
}

void bfs(int curValue, int curIdx, vector<int> & const numbers, int target) {
	if (curIdx == numbers.size() - 1) {
		if (curValue + numbers[curIdx] == target) {
			caseCnt++;
		}

		if (curValue - numbers[curIdx] == target) {
			caseCnt++;
		}

		return;
	}

	bfs(curValue + numbers[curIdx], curIdx + 1, numbers, target);
	bfs(curValue + (-1 * numbers[curIdx]), curIdx + 1, numbers, target);
}

