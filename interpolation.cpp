#include <iostream>
#include <vector>

using namespace std;

int inputXnY(int n, vector<pair<int,int>> XnY) {

	int x = 0, y = 0;
	vector<pair<int, int>> input;

	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		input.push_back(make_pair(x, y));
	}

	XnY = input;

	system("cls");

	return 0;
}

int main() {
	int n = 4;
	vector<pair<int, int>> XnY;

	inputXnY(n, XnY);

	return 0;
}