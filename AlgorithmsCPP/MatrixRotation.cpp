#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

void printMatrix(vector<vector<int>>& matrix);
int rotate(int x1, int y1, int x2, int y2, vector<vector<int>>& matrix);
vector<int> solution(int rows, int columns, vector<vector<int>> queries);

int main() {
	int rows = 3;
	int columns = 3;
	vector<vector<int>> queries{ {1,1,2,2}, {1,2,2,3}, {2,1,3,2}, {2,2,3,3} };

	vector<int> ret = solution(rows, columns, queries);
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
	vector<int> ret;

	vector<vector<int>> matrix;

	int index = 1;
	for (int i = 0; i < rows; i++) {
		vector<int> row;

		for (int j = 0; j < columns; j++) {
			row.push_back(index++);
		}

		matrix.push_back(row);
	}

	for (vector<int> query : queries) {
		//printMatrix(matrix);

		int minValue = rotate(query[0] - 1, query[1] - 1, query[2] - 1, query[3] - 1, matrix);

		ret.push_back(minValue);
	}

	return ret;
}

void printMatrix(vector<vector<int>> &matrix) {
	cout << "=======================================================" << endl;

	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[i].size(); j++) {
			cout << setw(4) << matrix[i][j] << " ";
		}
		cout << endl;
	}

	cout << "=======================================================" << endl;
}

int rotate(int x1, int y1, int x2, int y2, vector<vector<int>>& matrix) {
	int minValue = 123456789;
	int stash = matrix[x1][y1];

	for (int curX = x1; curX < x2; curX++) {
		matrix[curX][y1] = matrix[curX + 1][y1];

		minValue = min(matrix[curX][y1], minValue);
	}

	for (int curY = y1; curY < y2; curY++) {
		matrix[x2][curY] = matrix[x2][curY + 1];

		minValue = min(matrix[x2][curY], minValue);
	}

	for (int curX = x2; curX > x1; curX--) {
		matrix[curX][y2] = matrix[curX - 1][y2];

		minValue = min(matrix[curX][y2], minValue);
	}

	for (int curY = y2; curY > y1; curY--) {
		matrix[x1][curY] = matrix[x1][curY - 1];

		minValue = min(matrix[x1][curY], minValue);
	}

	matrix[x1][y1 + 1] = stash;
	minValue = min(matrix[x1][y1 + 1], minValue);

	return minValue;
}
