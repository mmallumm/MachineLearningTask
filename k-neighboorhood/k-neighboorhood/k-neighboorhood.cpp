// k-neighboorhood.cpp: определяет точку входа для приложения.
//

#include "k-neighboorhood.h"

using namespace std;

int k = 5;
double X1[] = { 3,11,7,8.5,8.3,6.3,12,7.1,4,6,15,6.7,7.5 };
double X2[] = { 10,9.8,9,8.9,8,6.4,6,6,10.1,7,13,9.5,9.8 };
bool Y[] = { 0,0,1,1,1,0,0,1,0,0,0,1,1 };

const double testX1 = 5, testX2 = 7;

double ro[13];

void FindRo() {
	for (int i = 0; i < 13; i++) {
		ro[i] = sqrt(pow(testX1 - X1[i], 2) + pow(testX2 - X2[i], 2));
	}
}

void SortRo() {
	double a = 0;
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 12; j++) {
			if (ro[j + 1] < ro[j]) {
				a = ro[j];
			}
		}
	}
}

int main()
{
	FindRo();
	SortRo();
	for (int i = 0; i < 13; i++) {
		cout << ro[i] << endl;
	}
	

	return 0;
}
