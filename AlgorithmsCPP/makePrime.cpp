#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

bool isPrime[3001];

void makePrimeSet();
int solution(vector<int> nums);

int main() {
	vector<int> nums{ 1,2,7, 6, 4 };

	int ret = solution(nums);
}

int solution(vector<int> nums) {
	makePrimeSet();

	int primeCnt = 0;
	for (int i = 0; i < nums.size() - 2; i++) {
		for (int j = i + 1; j < nums.size() - 1; j++) {
			for (int k = j + 1; k < nums.size(); k++) {
				int curSum = nums[i] + nums[j] + nums[k];

				if (isPrime[curSum]) {
					primeCnt++;
				}
			}
		}
	}

	return primeCnt;
}

void makePrimeSet() {
	for (int i = 0; i < 3001; i++) {
		isPrime[i] = true;
	}

	isPrime[0] = false;
	isPrime[1] = false;

	for (int i = 2; i < sqrt(3000); i++) {
		int curNum = i;

		if (!isPrime[curNum]) { continue; }

		while (curNum <= 3000) {
			curNum += i;

			if (curNum > 3000) { break; }

			isPrime[curNum] = false;
		}
	}
}
