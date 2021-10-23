#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(int n);

int main() {
	string ret = solution(10);

	cout << ret << endl;
}

string solution(int n) {

	string ret = "";


	int k = 1;
	int cnt = 0;
	while (k < n) {
		k *= 3;
		cnt++;
	}

	k /= 3;
	n -= k;


	return ret;
}