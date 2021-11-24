#include <iostream>
#include <math.h>
using namespace std;

double sigmoid(double net) {
	double a = 1 / (1 + exp(-(net)));
	return a;
}

void proceptron1() {
	bool answer;
	double net = 0;

	const int SIZE_OF_STUDY = 13;
	double w0 = -0.1, w1 = 0.2, w2 = 0.5;
	double tau = 0.1;
	double X1[SIZE_OF_STUDY] = { 3, 11, 7, 8.5, 8.3, 6.3, 12, 7.1, 4, 6, 15, 6.7, 7.5 };
	double X1_max = X1[0], X1_min = X1[0];
	double X2[SIZE_OF_STUDY] = { 10, 9.8, 9, 8.9, 8, 6.4, 6, 6, 10.1, 7, 13, 9.5, 9.8 };
	double X2_max = X2[0], X2_min = X2[0];
	double Y[SIZE_OF_STUDY] = { 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 0, 1, 1 };\

	double testX1 = 5, testX2 = 7;

	for (int i = 1; i < SIZE_OF_STUDY; i++) {
		if (X1[i] < X1_min) X1_min = X1[i];
		if (X1[i] > X1_max) X1_max = X1[i];
		if (X2[i] < X2_min) X2_min = X2[i];
		if (X2[i] > X2_max) X2_max = X2[i];
	}

	for (int i = 0; i < SIZE_OF_STUDY; i++) {
		X1[i] = (X1[i] - X1_min) / (X1_max - X1_min);
		X2[i] = (X2[i] - X2_min) / (X2_max - X2_min);
	}

	testX1 = (testX1 - X1_min) / (X1_max - X1_min);
	testX2 = (testX2 - X2_min) / (X2_max - X2_min);


	for (int i = 0; i < SIZE_OF_STUDY; i++) {
		net = w0 + (w1 * X1[i]) + (w2 * X2[i]);
		w0 += tau * sigmoid(net) * (1 - sigmoid(net)) * (Y[i] - sigmoid(net));
		w1 += tau * sigmoid(net) * (1 - sigmoid(net)) * (Y[i] - sigmoid(net)) * X1[i];
		w2 += tau * sigmoid(net) * (1 - sigmoid(net)) * (Y[i] - sigmoid(net)) * X2[i];
		//cout << "net: " << net << "  w0: " << w0 << "  w1: " << w1 << "  w2: " << w2 << endl;
	}

	net = w0 + (w1 * testX1) + (w2 * testX2);
	if (sigmoid(net) > 0.5) answer = 1;
	else answer = 0;

	cout << answer << "   sigmoid is: " << sigmoid(net) << endl;
}

void proceptron2() {
	bool answer;
	double net = 0;
	const double teta = 0.5;

	const int SIZE_OF_STUDY = 5;
	double w0 = 0.6, w1 = 0.4, w2 = 0.6, w3 = 0.3;
	double tau = 0.2;

	int X1[SIZE_OF_STUDY] = { 0, 0, 1, 1, 1};
	int X2[SIZE_OF_STUDY] = { 1, 1, 0, 0, 1 };
	int X3[SIZE_OF_STUDY] = { 0, 1, 0, 1, 0 };
	int Y[SIZE_OF_STUDY] = { 1, 1, 0, 1, 0 };
	
	double testX1 = 1, testX2 = 1, testX3 = 1;

	for (int i = 0; i < SIZE_OF_STUDY; i++) {

		cout << "net: " << net << "  w0: " << w0 << "  w1: " << w1 << "  w2: " << w2 << "  w3: " << w3 << endl;

		net = w0 + w1 * X1[i] + w2 * X2[i] + w3 * X3[i];
		(net > teta) ? (net = 1) : (net = 0);
		w0 += tau * (Y[i]-net);
		w1 += tau * (Y[i] - net) * X1[i];
		w2 += tau * (Y[i] - net) * X2[i];
		w3 += tau * (Y[i] - net) * X3[i];
	}

	net = w0 + (w1 * testX1) + (w2 * testX2) + (w3 * testX3);
	(net > teta) ? (answer = 1) : (answer = 0);

	cout << "w0: " << net << endl;
	cout << "answer: " << answer << endl;

}

int main()
{

	//proceptron2();
	char stroka[3];
	cin >> stroka;
	cout << stroka;

	return 0;
}

