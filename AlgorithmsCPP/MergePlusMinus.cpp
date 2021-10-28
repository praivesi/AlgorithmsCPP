#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> absolutes, vector<bool> signs) {
	int sum = 0;
	for (int i = 0; i < absolutes.size(); i++) {
		sum += signs[i] ? absolutes[i] : absolutes[i] * -1;
	}

	return sum;
}