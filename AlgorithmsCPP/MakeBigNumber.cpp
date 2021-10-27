#include <string>
#include <vector>
#include <stack>

using namespace std;

string solution(string number, int k) {
	stack<char> stk;

	for (int i = 0; i < number.size(); i++) {
		if (k != 0) {
			while (!stk.empty()) {
				if (stk.top() >= number[i]) { break; }
				if (k == 0) { break; }

				stk.pop();
				k--;
			}
		}

		stk.push(number[i]);
	}

	while (k != 0) {
		stk.pop();
		k--;
	}

	int charsSize = stk.size() + 1;
	char* chars = new char[charsSize];

	int charIdx = stk.size() - 1;
	while (!stk.empty()) {
		chars[charIdx] = stk.top();
		stk.pop();

		charIdx--;
	}

	chars[charsSize - 1] = '\0';

	return string(chars);
}

int main() {
	string ret = solution("4177252841", 4);
}