#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Node {
public:
	Node* parent;
	string name;
	int profit;

	Node(string name, Node* parent) {
		this->name = name;
		this->parent = parent;
		this->profit = 0;
	}
};

void earn(Node* person, int profit);
vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount);

int main() {
	vector<string> enroll{ "john", "mary", "edward", "sam", "emily", "jaimie", "tod", "young" };
	vector<string> referral{ "-", "-", "mary", "edward", "mary", "mary", "jaimie", "edward" };
	vector<string> seller{ "young", "john", "tod", "emily", "mary" };
	vector<int> amount{ 12, 4, 2, 5, 10 };

	vector<int> ret = solution(enroll, referral, seller, amount);

	cout << "=====================================" << endl;
	for (int r : ret) {
		cout << r << " ";
	}
	cout << "=====================================" << endl;
}

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
	vector<Node> people;
	
	for (string en : enroll) {
		people.push_back(Node(en, nullptr));
	}

	for (int i = 0; i < referral.size(); i++) {
		if (referral[i] == "-") {
			continue;
		}

		for (int j = 0; j < people.size(); j++) {
			if (referral[i] == people[j].name) {
				people[i].parent = &people[j];
				break;
			}
		}
	}

	for (int i = 0; i < seller.size(); i++) {
		for (int j = 0; j < people.size(); j++) {
			if (seller[i] != people[j].name) {
				continue;
			}

			earn(&people[j], amount[i] * 100);
			
			break;
		}
	}

	vector<int> profits;

	for (Node & person : people) {
		profits.push_back(person.profit);
	}

	return profits;
}

void earn(Node* person, int profit) {
	if (person == nullptr) return;

	int rest = profit % 10;
	int v = profit - rest;

	int myProfit = 0.9 * v + rest;
	int parentProfit = 0.1 * v;

	if (parentProfit < 1) {
		person->profit += profit;

		cout << person->name << " takes all ... " << profit << endl;
	}
	else {
		person->profit += myProfit;

		cout << person->name << " earns " << myProfit << endl;

		if (person->parent != nullptr) {
			cout << person->name << " toss " << parentProfit << " to " << person->parent->name << endl;
		}

		earn(person->parent, 0.1 * profit);
	}
}