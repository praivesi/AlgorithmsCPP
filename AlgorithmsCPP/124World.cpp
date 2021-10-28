#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(int n);

int main() {
	string ret = solution(15);

	cout << ret << endl;
}

string solution(int n) {
	if (n == 1) { return "1"; }
	if (n == 2) { return "2"; }
	if (n == 3) { return "4"; }

	int quotient = 0;
	int remainder = 0;

	vector<int> remainders;

	while (n > 3) {
		quotient = n / 3;
		remainder = n % 3;

		if (remainder == 0) {
			quotient--;
			remainder += 3;
		}

		remainders.push_back(remainder);

		n = quotient;
	}

	remainders.push_back(quotient);

	reverse(remainders.begin(), remainders.end());

	char* chars = new char[remainders.size() + 1];

	for (int i = 0; i < remainders.size(); i++)
	{
		switch (remainders[i]) {
		case 1:
			chars[i] = '1';
			break;
		case 2:
			chars[i] = '2';
			break;
		case 3:
			chars[i] = '4';
			break;
		}
	}

	chars[remainders.size()] = '\0';

	return string(chars);
}
