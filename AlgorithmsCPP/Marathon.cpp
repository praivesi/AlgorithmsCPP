#include <string>
#include <vector>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	vector<string>* pMap = new vector<string>[26];
	vector<string>* cMap = new vector<string>[26];

	for (string& p : participant) {
		pMap[p[0] - 'a'].push_back(p);
	}

	for (string& c : completion) {
		cMap[c[0] - 'a'].push_back(c);
	}

	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < pMap[i].size(); j++) {
			bool find = false;

			for (int k = 0; k < cMap[i].size(); k++) {
				if (pMap[i][j] == cMap[i][k]) {
					cMap[i][k] = "";
					find = true;

					break;
				}
			}

			if (!find) {
				return pMap[i][j];
			}
		}
	}

	return "";
}