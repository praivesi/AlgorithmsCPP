#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>

using namespace std;

string solution(vector<string> registered_list, string new_id);
string makeNewId(string prefix, int postfix);
bool alreadyExist(vector<string>& registered_list, string& new_id);
string getPrefix(string id);
int getPostfix(string id, string prefix);

int main() {
	vector<string> registered_list{ "bird99", "bird98", "bird101", "gotoxy" };
	string new_id = "bird98";

	string ret = solution(registered_list, new_id);

	cout << "ret: " << ret << endl;
}

string solution(vector<string> registered_list, string new_id) {
	string prefix = getPrefix(new_id);
	int postfix = getPostfix(new_id, prefix);

	while (true)
	{
		bool exist = alreadyExist(registered_list, new_id);

		if (!exist) {
			return new_id;
		}



		new_id = makeNewId(prefix, postfix + 1);
	}
}

string makeNewId(string prefix, int postfix) {
	//char buf[10];

	//_itoa_s(postfix, buf, 10);

	vector<int> tmp;

	while (postfix != 0) {
		tmp.push_back(postfix % 10);

		postfix /= 10;
	}

	char* buf = new char[tmp.size() + 1];
	for (int i = 0; i < tmp.size(); i++) {
		buf[tmp.size() - 1 - i] = tmp[i] + '0';
	}
	buf[tmp.size()] = '\0';

	prefix += buf;

	return prefix;
}

bool alreadyExist(vector<string> & registered_list, string & new_id) {
	bool exist = false;
	for (string& registered : registered_list) {
		if (registered == new_id) {
			exist = true;
			break;
		}
	}

	return exist;
}

string getPrefix(string id) {
	string prefix = "";

	for (int i = 0; i < id.length(); i++) {
		char curChar = id.at(i);
		if (curChar >= 'a' && curChar <= 'z') {
			prefix += curChar;
		}
		else {
			break;
		}
	}

	return prefix;
}

int getPostfix(string id, string prefix) {
	if (id == prefix) {
		return 0;
	}

	string postfixStr = id.substr(prefix.size(), id.size() - prefix.size());

	return stoi(postfixStr);
}
