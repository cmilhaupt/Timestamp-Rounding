#include "headers.hpp"

using namespace std;

double getR(vector<double> * x, vector<double> * y) {
	if(x->size() != y->size()) {
		cout << "x length does not equal y length." << endl;
		exit(1);
	}
	int n = x->size();
	double sumxy = 0;
	double sumx = 0;
	double sumy = 0;
	double sumx2 = 0;
	double sumy2 = 0;
	for(int i = 0; i < n; i++) {
		sumx += (*x)[i];
		sumx2 += (*x)[i] * (*x)[i];
		sumy += (*y)[i];
		sumy2 += (*y)[i] * (*y)[i];
		sumxy += (*x)[i] * (*y)[i];
	}
	double rtop = (n * sumxy) - (sumx * sumy);
	double rbot1 = sqrt((n * sumx2) - (sumx * sumx));
	double rbot2 = sqrt((n * sumy2) - (sumy * sumy));
	double r = rtop / (rbot1 * rbot2);
	//cout << "sum(x) = " << sumx << endl;
	//cout << "sum(x^2) = " << sumx2 << endl;
	return r; 
}

double getR2(vector<double> * x, vector<double> * y) {
	if(x->size() != y->size()) {
		cout << "x length does not equal y length." << endl;
		exit(1);
	}
	int n = x->size();
	double sumxy = 0;
	double sumx = 0;
	double sumy = 0;
	double sumx2 = 0;
	double sumy2 = 0;
	for(int i = 0; i < n; i++) {
		sumx += (*x)[i];
		sumx2 += (*x)[i] * (*x)[i];
		sumy += (*y)[i];
		sumy2 += (*y)[i] * (*y)[i];
		sumxy += (*x)[i] * (*y)[i];
	}
	double rtop = ((n * sumxy) - (sumx * sumy));
	double rbot1 = (n * sumx2) - (sumx * sumx);
	double rbot2 = (n * sumy2) - (sumy * sumy);
	double r = (rtop * rtop) / (rbot1 * rbot2);
	return r;
}
