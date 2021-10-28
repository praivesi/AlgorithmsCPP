#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
	bool* saved = new bool[people.size()];

	for (int i = 0; i < people.size(); i++) {
		saved[i] = false;
	}

	sort(people.begin(), people.end());
	reverse(people.begin(), people.end());

	int boatCnt = 0;

	int rear = people.size() - 1;
	for (int i = 0; i < people.size(); i++) {
		if (people[i] <= limit / 2)
		{
			int remainedPeople = people.size() - i;

			boatCnt += remainedPeople % 2 == 0 ? remainedPeople / 2 : remainedPeople / 2 + 1;

			break;
		}

		if (saved[i]) 
		{
			boatCnt++;

			break; 
		}

		if (people[i] + people[rear] <= limit) {
			saved[i] = true;
			saved[rear] = true;

			rear--;
		}

		boatCnt++;
	}

	return boatCnt;
}

int main() {

}