#include <iostream>
//#include <string.h>
// #include <stdlib.h>
#include <algorithm>

#define RAND_UP 100
#define RAND_DOWN 50
#define DSIZE 10

void printArray (int* array_ptr, int size);
void fillArray (int* arrayPtr, int startIndex, int endIndex);
int mrand (int up, int down);
bool checkFib (int n);
template<typename T> int linearSearch (T* set, T key, int setSize);
void printMatrix (int** matrix, const int m, const int n);

void test (int& n) {
	int a = 10;
	n = a;
}

int main () {
	using namespace std;

	setlocale(0, "russian");

	cout << "Лабораторная работа №4. Вариант 6." << endl;
	cout << "Формирование одномерного массива" << endl;

	int* rndArray = new int[DSIZE];
	fillArray (rndArray, 0, DSIZE - 1);
	printArray(rndArray, DSIZE);

	cout << "Удаление всех чисел Фибоначчи" << endl;

	int* noFib = new int[DSIZE];
	for (int i = 0, j = 0; i < DSIZE; i++)
		if (!checkFib(rndArray[i]))
			noFib[j++] = rndArray[i];
	std::sort(noFib, noFib + DSIZE);
	printArray(noFib, DSIZE);

	int** matrix = new int*[DSIZE];
	for (int i = 0; i < DSIZE; i++) {
		matrix[i] = new int[DSIZE];
		fillArray(matrix[i], 0, DSIZE - 1);
		// std::sort(matrix[i], matrix[i] + sizeof(int)*DSIZE);
		std::sort(matrix[i], matrix[i] + DSIZE);

	}

	printMatrix(matrix, DSIZE, DSIZE);

	// system("pause");
}

bool checkFib (const int n) {
	if (n < 0)
		return false;
	if (n == 0)
		return true;

	static int cachedFib[DSIZE * 2] = {0, 1};
	static int cFib = 2;
	
	/*std::cout << "cached nums:" << std::endl;
	for (int i = 0; i < cFib; i++)
		std::cout << cachedFib[i] << std::endl;*/

	if (linearSearch<int>(cachedFib, n, cFib + 1) >= 0)
		return true;
	
	int n1 = cachedFib[cFib - 2],
		n2 = cachedFib[cFib - 1],
		n3 = 0;

	while (n3 < n) {
		// std::cout << n3 << std::endl;
		n3 = n1 + n2;
		cachedFib[cFib++] = n3;
		if (n3 == n)
			return true;
		// else cachedFib[cFib++] = n3;
		n1 = n2;
		n2 = n3;
	}

	return false;
}

template<typename T> int linearSearch (T* set, T key, int setSize) {
	for (int i = 0; i < setSize; i++) {
		// std::cout << "set " << ":" << i << std::endl;
		if (set[i] == key)
			return i;
	}
	return -1;
}

void printArray (int* array_ptr, int size) {
	std::cout << "Результат:" << std::endl;
	for (int i = 0; i < size; i++)
		std::cout << array_ptr[i] << " ";
	std::cout << std::endl;
}

int mrand (int up, int down) {
	return rand() % up - down;
}

void fillArray (int* arrayPtr, int startIndex, int endIndex) {
	for (int i = startIndex; i <= endIndex; i++)
		arrayPtr[i] = mrand(RAND_UP, RAND_DOWN);
}

void printMatrix (int** matrix, const int m, const int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
}


