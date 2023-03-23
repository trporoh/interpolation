#include <iostream>
#include <vector>

using namespace std;

vector<pair<double,double>> inputXnY(int n, vector<pair<double,double>> XnY) {

	int x = 0, y = 0;
	vector<pair<double, double>> input;

	cout << "inpit data" << endl << "|x  y|" << endl;

	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		input.push_back(make_pair(x, y));
	}

	XnY = input;

	system("clear");

	return XnY;
}

double Lagrange(vector<pair<double,double>> XnY, double x) {

	double P;
	double resoult = 0;
	for (long unsigned int i = 0; i <= XnY.size(); i++) {
		P = 1;
		for (long unsigned int j = 0; j <= XnY.size(); j++) {
			if (i != j) {
				P *= (x - XnY[j].first) / (XnY[i].first - XnY[j].first);
			}
		}
		resoult += XnY[i].second * P;
	}

	return resoult;
}

int main() {

	int n;
	double Lagr;
	vector<pair<double, double>> XnY;

	cout << "enter the number of points: ";
	cin >> n;

	system("clear");

	XnY = inputXnY(n, XnY);
	Lagr = Lagrange(XnY, 2.5);
	
	cout << "| " << Lagr << " | " << endl;

	return 0;
}