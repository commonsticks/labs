#include <iostream>

#define RAND_UP 100
#define RAND_DOWN 1

void printMatrix (int** matrix, const int m, const int n);
void printArray (int* array_ptr, int size);
void fillArray (int* arrayPtr, int startIndex, int endIndex);
int mrand (int up, int down);

int main () {
	using namespace std;

	srand(time(NULL));
	setlocale(0, "russian");

	cout << "Лабораторная работа №5. Вариант 6." << endl;
	cout << "Формирование динамического одномерного массива" << endl;

	int N, K, len;

	cout << "Введите целые N > 0, K > 0: \n";

	cin >> N;
	cin >> K;
	len = (N + K) * 2;

	int* rnd = new int[len];
	int* nrnd = new int[len - N];

	fillArray(rnd, 0, len - 1);
	printArray(rnd, len);

	cout << "Удаление N элементов с номера K" << endl;

	for (int i = 0, j = 0; i < len; i++) {
		if (i >= K - 1 && i < N + K - 1)
			continue;
		nrnd[j++] = rnd[i];
	}
	delete [] rnd;
	len -= N;

	printArray(nrnd, len);

	cout << "Создание динамического двумерного массива" << endl;
	int** matrix = new int*[N];

	for (int i = 0; i < N; i++) {
		matrix[i] = new int[N];
		fillArray(matrix[i], 0, N - 1);
	}

	printMatrix(matrix, N, N);

	cout << "Добавление столбца к матрице" << endl;
	for (int i = 0; i < N; i++) {
		int* biggerArray = new int[N + 1];
		biggerArray[0] = mrand(RAND_UP, RAND_DOWN);
		for (int j = 1; j < N + 1; j++)
			biggerArray[j] = matrix[i][j - 1];
		delete [] matrix[i];
		matrix[i] = biggerArray;
	}

	printMatrix(matrix, N, N + 1);

	return 0;
}

int mrand (int up, int down) {
	return rand() % up - down;
}

void fillArray (int* arrayPtr, int startIndex, int endIndex) {
	for (int i = startIndex; i <= endIndex; i++)
		arrayPtr[i] = mrand(RAND_UP, RAND_DOWN);
}

void printArray (int* array_ptr, int size) {
	std::cout << "Результат:" << std::endl;
	for (int i = 0; i < size; i++)
		std::cout << array_ptr[i] << " ";
	std::cout << std::endl;
}

void printMatrix (int** matrix, const int m, const int n) {
    std::cout << "Результат:" << std::endl;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)
			std::cout << matrix[i][j] << "\t";
		std::cout << std::endl;
	}
	std::cout << std::endl;
}