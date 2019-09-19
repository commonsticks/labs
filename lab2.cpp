#include <iostream>
#include <cmath>

using namespace  std;

int in () {
	int num;
	cin >> num;

	return num;
}

bool isOdd (int num) {
	if (num == 1 || num == -1 || num % 2 != 0)
		return true;
	return false;
}

int main () {
	setlocale(0, "russian");

	int n1, num;
	cout << "Задание 6." << endl << "Введите n" << endl;
	n1 = in();
	cout << "Введите " << n1 << " чисел " << endl;

	int oddElemsSum = 0;
	for (int i = 0; i < n1; i++) {
		num = in();
		if (isOdd(num))
			oddElemsSum += num;
	}
	cout << "Сумма нечетных элементов: " << oddElemsSum << endl << endl;

	cout << "Задание 29." << endl;
	cout << "Введите последовательность чисел, оканчивающуюся на 0" << endl;
	num = -1;

	int oddCount = 0;
	while ((num = in()) != 0) {
		if (isOdd(num))
			oddCount++;
	}
	cout << "Количество нечетных элементов: " << oddCount << endl << endl;

	cout << "Задание 40." << endl;
	cout << "Введите значение X, допустимое для sin(X), затем n" << endl;
	double X, n;
	cin >> X;
	cin >> n;

	//cout << "Выражение равно: " << ( (sin(X) + pow(sin(X), n)) * (n/2)) << endl;

	double sinSum = 0;
	for (int i = 1; i <= n; i++)
		sinSum += pow(sin(X), i);
	cout << "Выражение равно: " << sinSum << endl;

	system("pause");
	return 0;
}