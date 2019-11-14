#include <iostream>
#include <stdio.h>
#include <algorithm>

#define RAND_UP 100
#define RAND_DOWN 50
#define DSIZE 5
#define STRSIZE 256
#define IN 1
#define OUT 2
#define END 3

typedef char STR[STRSIZE];

void printArray (int* array_ptr, int size);
void fillArray (int* arrayPtr, int startIndex, int endIndex);
int mrand (int up, int down);
bool checkFib (int n);
template<typename T> int linearSearch (T* set, T key, int setSize);
void printMatrix (int** matrix, const int m, const int n);
void matrixVerticalSort (int** matrix, const int m, const int n, const int col);
bool isKeyChar (const char c);
void getsWrap (char* strBuf, int size);
int getState (char c);

// const char keychars[] = {'у', 'е', 'ы', 'а', 'о', 'э', 'я', 'и', 'ю'};
static const char keychars[] = {'e', 'y', 'u', 'i', 'o', 'a'};

int main () {
	using namespace std;
    
    srand(time(NULL));
	setlocale(0, "russian");

	cout << "Лабораторная работа №4. Вариант 6." << endl;
	cout << "Формирование одномерного массива" << endl;

	int* rndArray = new int[DSIZE];
	fillArray (rndArray, 0, DSIZE - 1);
	printArray(rndArray, DSIZE);

	cout << "Удаление всех чисел Фибоначчи" << endl;

	int* noFib = new int[DSIZE];
	int i, j;
	for (i = 0, j = 0; i < DSIZE; i++)
		if (!checkFib(rndArray[i]))
			noFib[j++] = rndArray[i];
	printArray(noFib, j);
	delete[] rndArray;
	delete[] noFib;
    
    cout << "Создание двумерного массива" << endl;
	int** matrix = new int*[DSIZE];
	
	for (int i = 0; i < DSIZE; i++) {
		matrix[i] = new int[DSIZE];
		fillArray(matrix[i], 0, DSIZE - 1);
	}

	printMatrix(matrix, DSIZE, DSIZE);
	
	cout << "Сортировка столбцов матрицы" << endl;
	
	for (int i = 0; i < DSIZE; i++)
	    matrixVerticalSort (matrix, DSIZE, DSIZE, i);
	printMatrix(matrix, DSIZE, DSIZE);

	// matrix is being magically deleted here

	cout << "Удаление всех слов на (латинскую) гласную букву" << endl;
	cout << "Введите строку (латиницей)" << endl;

	STR input;
	STR output;
	getsWrap(input, STRSIZE);

	int index = 0;
	int writeIndex = 0;

	int state = OUT;
	int cstate;

	bool shouldSkip = false;

	while (1) {
		cstate = getState(input[index]);
		if (cstate == END)
			break;

		if (state == IN && cstate == OUT)
			shouldSkip = false;
		else if (state == OUT && cstate == IN) {
			if (isKeyChar(input[index]))
				shouldSkip = true;
		}
		state = cstate;

		if (!shouldSkip)
			output[writeIndex++] = input[index];
		index++;
	}
	output[writeIndex] = '\0';

	cout << "Результат" << '\n' << output << endl;
}

int getState (char c) {
	if (c == '\0')
		return END;
	else if ((c >= 32 && c <= 47) || (c >= 58 && c <= 64))
		return OUT;
	else
		return IN;
}

bool checkFib (const int n) {
	if (n < 0)
		return false;
	if (n == 0)
		return true;

	static int cachedFib[DSIZE * 10] = {0, 1};
	static int cFib = 2;

	if (linearSearch<int>(cachedFib, n, cFib + 1) >= 0)
		return true;
	
	int n1 = cachedFib[cFib - 2],
		n2 = cachedFib[cFib - 1],
		n3 = 0;

	while (n3 < n) {
		n3 = n1 + n2;
		cachedFib[cFib++] = n3;
		if (n3 == n)
			return true;
		n1 = n2;
		n2 = n3;
	}

	return false;
}

template<typename T> int linearSearch (T* set, T key, int setSize) {
	for (int i = 0; i < setSize; i++) {
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
    std::cout << "Результат:" << std::endl;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)
			std::cout << matrix[i][j] << "\t";
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void matrixVerticalSort (int** matrix, const int m, const int n, const int col) {
    int* column = new int[m];
    for (int i = 0; i < m; i++)
        column[i] = matrix[i][col];
    std::sort(column, column + m);
    // std::qsort(column, m, sizeof(int), compare);
    for (int i = 0; i < m; i++)
        matrix[i][col] = column[m - i - 1];
}

void getsWrap (char* strBuf, int size) {
	std::fgets(strBuf, size, stdin);
}

bool isKeyChar (const char c) {
    for (int i = 0; i < sizeof(keychars); i++)
    	if (keychars[i] == c)
    		return true;
    return false;
}