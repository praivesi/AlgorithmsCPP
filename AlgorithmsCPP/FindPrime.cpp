#include <string>
#include <vector>
#include <iostream>

using namespace std;

#define FILTER_SIZE 10000000

bool filter[FILTER_SIZE];

int solution(string numbers);
void makeFilter();
int findPrimeCnt(int acc, int idx, vector<char>& pieces, vector<bool>& used);

int main() {
	int ret = solution("011");

	std::cout << ret << std::endl;
}

int solution(string numbers) {
	makeFilter();

	vector<char> pieces;

	for (int i = 0; i < numbers.length(); i++) {
		pieces.push_back(numbers[i]);
	}

	int primeCnt = 0;
	for (int i = 0; i < pieces.size(); i++) {
		vector<bool> used(numbers.length(), false);

		primeCnt += findPrimeCnt(0, i, pieces, used);
	}

	return primeCnt;
}

void makeFilter() {
	for (int i = 0; i < FILTER_SIZE; i++) {
		filter[i] = true;
	}
	filter[0] = false;
	filter[1] = false;

	for (int i = 2; i < sqrt(FILTER_SIZE); i++) {
		if (!filter[i]) { continue; }

		int iter = i + i;

		while (iter < FILTER_SIZE) {
			if (!filter[iter]) { break; }

			filter[iter] = false;
			iter += i;
		}
	}
}

int findPrimeCnt(int acc, int idx, vector<char>& pieces, vector<bool>& used) {
	cout << "acc : " << acc << " / idx : " << idx << endl;

	if (idx == pieces.size()) {
		if (filter[acc]) {
			cout << " FFFFF " << acc << " FFFFFFFFFFFF / ";
			return 1;
		}
		else {
			cout << " NNNNN " << acc << " NNNNNNNNNNNN / ";
			return 0;
		}
	}

	//if (idx == pieces.size() - 1) {
	//	for (int i = 0; i < used.size(); i++) {
	//		if (used[i]) { continue; }

	//		acc += pieces[i] - '0';

	//		if (filter[acc]) {
	//			return 1;
	//		}
	//		else { 
	//			return 0; 
	//		}
	//	}

	//	return 0;
	//}

	int primeCnt = 0;
	bool usedDigit[10]{ false, };

	for (int i = 0; i < pieces.size(); i++) {
		if (used[i]) { continue; }
		used[i] = true;

		int curDigit = pieces[i] - '0';
		cout << " curDigit : " << curDigit << " / ";


		if (usedDigit[curDigit]) { continue; }
		usedDigit[curDigit] = true;

		cout << "use : " << curDigit << " / usd idx : " << i << " / ";

		int powed = pow(10, pieces.size() - idx - 1);
		cout << "powed : " << powed << " / ";

		primeCnt += findPrimeCnt(acc + curDigit * pow(10, pieces.size() - idx - 1), idx + 1, pieces, used);

		used[i] = false;
	}

	return primeCnt;
}