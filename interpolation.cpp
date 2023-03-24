#include <iostream>
#include <vector>

using namespace std;

vector<pair<double,double>> inputXnY(int n, vector<pair<double,double>> XnY) {

	double x = 0, y = 0;
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

double Eitkin(vector<pair<double,double>> XnY, double x) {

	vector<vector<double>> scheme(XnY.size());
	double P;
	
	for (long unsigned int i = 0; i <= XnY.size() - 1; i++) {
		P = 1;
		for (long unsigned int j = 0; j <= XnY.size() -1 ; j++) {
			if (i != j) {
				P *= (x - XnY[j].first) / (XnY[i].first - XnY[j].first);
			}
		}
		scheme[i].push_back(XnY[i].second * P);
		cout << scheme[i].at(0) << "   ";
	}
	cout << endl;
		
	for (int j = 1; j < (int)XnY.size(); j++) {

		for (int i = 0; i < (int)XnY.size() - j; i++) {

			scheme.at(i).push_back((scheme.at(i).at(j - 1) * (x - XnY.at(i + j).first) - scheme.at(i + 1).at(j - 1) * (x - XnY.at(i).first)) / (XnY.at(i).first - XnY.at(i + j).first));
			cout << scheme.at(i).at(j) << "   ";
		}
		cout << endl;
	}
	
	return scheme.at(0).at(XnY.size() - 1);
}

int main() {

	int n, var;
	double Lagr, Eitk;

	vector<pair<double, double>> XnY;

	cout << "enter the number of points: ";
	cin >> n;

	system("clear");

	XnY = inputXnY(n, XnY);

	cout << "press 1 for Lagr, 2 for Eitken: " << endl;
	cin >> var;

	switch (var) {
	case 1:
		Lagr = Lagrange(XnY,2);
		cout << "| " << Lagr << " | ";
		break;
	case 2:
		Eitk = Eitkin(XnY, 2);
		cout << "| " << Eitk << " | ";
		break;
	}

	return 0;
}