#include <iostream>
#include <cmath>

using namespace std;

void o (int in) {cout<<in<<endl;}
// void o (string in) {cout << in << endl;}
void o (bool in) {
	if (in)
		cout<<"true"<<endl;
	else
		cout<<"false"<<endl;
}

void checkTwoN () {
	int m, n;
	cout << "enter m, n" << endl;
	cin >> m; 
	cin >> n;

	cout << "m-++n" << endl;
	o(m - (n+1));
	cout << endl;

	cout << "m++>--n" << endl;
	o(m > (n-1));
	cout << endl;

	cout << "m--<++n" << endl;
	o(m < (n+1));
	cout << endl;
}

void circleCheck () {
	double x, y;

	cout << "enter x, y" << endl;
	cin >> x;
	cin >> y;
	o(x <= 1 && x >= -1 && y <= 0 && y >= -1 && x*x + y*y <= 1);
	cout << endl;
}

int main () {
	setlocale(0, "russian");
	cout << "Вариант 6." << endl;

	checkTwoN();
	checkTwoN();

	circleCheck();
	circleCheck();

	cout << "Вычисление выражения с использованием float:" << endl;
	float af = 100, bf = 0.001;
	cout << (pow(af + bf, 3) - pow(af, 3)) / (pow(bf, 3) + 3*af*pow(bf, 7) + 3*bf*pow(af, 7)) << endl;
	
	cout << "Вычисление выражения с использованием double:" << endl;
	double ab = 100, bb = 0.001;
	cout << (pow(ab + bb, 3) - pow(ab, 3)) / (pow(bb, 3) + 3*ab*pow(bb, 7) + 3*bb*pow(ab, 7)) << endl;
	
	system("pause");
	return 0;
}