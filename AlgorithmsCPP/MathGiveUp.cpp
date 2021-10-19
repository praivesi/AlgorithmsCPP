#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> answers);

int main() {
	vector<int> answers{ 1,3,2,4,2 };

	vector<int> ret = solution(answers);

	for (int r : ret) {
		std::cout << r << " ";
	}
	std::cout << std::endl;
}

vector<int> solution(vector<int> answers) {
	vector<vector<int>> givers;
	givers.push_back(vector<int>{1, 2, 3, 4, 5});
	givers.push_back(vector<int>{2, 1, 2, 3, 2, 4, 2, 5});
	givers.push_back(vector<int>{3, 3, 1, 1, 2, 2, 4, 4, 5, 5});

	vector<int> correct;
	for (int i = 0; i < givers.size(); i++) {
		correct.push_back(0);
	}

	for (int i = 0; i < answers.size(); i++) {
		for (int j = 0; j < givers.size(); j++) {
			if (givers[j][i % givers[j].size()] == answers[i]) {
				correct[j] += 1;
			}
		}
	}

	int max = 0;
	for (int c : correct) {
		max = c > max ? c : max;
	}

	vector<int> winners;
	for (int i = 0; i < correct.size(); i++) {
		if (correct[i] == max) {
			winners.push_back(i + 1);
		}
	}

	return winners;
}