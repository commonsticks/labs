#define null NULL
#include <iostream>
#include <cstdlib>
#include <ctime>

#define RAND_UP 100
#define RAND_DOWN 50

struct SearchResult {
	int resultIndex;
	int matchCount;
};

void sort (int* array, int size);
template<typename T> SearchResult* searchInSorted (T* a, int size, T key);
SearchResult* searchNeg (int* array, int size);
void printArray (int* array_ptr, int size);
void fillArray (int* array_ptr, int startIndex, int endIndex);
int lim (int* array_ptr, int size, bool max);
int mrand (int down, int up);
SearchResult* defaultSR ();

int main () {
	using namespace std;

	setlocale(0, "russian");
	srand(time(NULL));
	
	int n, k;
	cout << "Введите n: n>0 и k: 0>=k>n" << endl;
	cin >> n;
	cin >> k;

	cout << "Создание массива: " << endl;

	int *narray = new int[n];
	int* array = new int[n + k];

	fillArray(narray, 0, n - 1);
	printArray(narray, n);

	int i, j;
	for (i = 0, j = 0; i < n; i++)
		if (i == 0 || i % 2 != 0)
			array[j++] = narray[i];
	delete[] narray;
	n = j;

	cout << "Добавление k элементов в конец массива" << endl;
	fillArray(array, n, (n + k) - 1);
	printArray(array, n + k);

	cout << "Перестановка минимального и максимального значений" << endl;
	// индексы
	int max = lim(array, n + k, true);
	int min = lim(array, n + k, false);
	
	int temp = array[max];
	array[max] = array[min];
	array[min] = temp;
	printArray(array, n+k);
	 
	 SearchResult* firstRes = searchNeg(array, n+k);
	 if (firstRes -> resultIndex < 0)
		 cout << "Нет чисел <0" << "; ";
	 else
		 cout << "Первое отрицательное число: " << array[firstRes -> resultIndex] << "; ";
	 cout << "Сравнений для поиска: " << firstRes -> matchCount << endl;
	
	 cout << "Сортировка методом простого включения:" << endl;
	 sort(array, n+k);
	 printArray(array, n+k);
	
	 SearchResult* simpleSearch = searchNeg(array, n+k);
	 SearchResult* binarySearch = searchInSorted<int>(array, n + k, array[simpleSearch -> resultIndex]);
	 cout << "Простой поиск отрицательных чисел в отсортированном массиве: " << endl;
	 if (simpleSearch -> resultIndex >= 0)
		cout << "Результат: " << array[simpleSearch -> resultIndex] << endl;
	 else
		cout << "Чисел не найдено" << endl;
	 cout << "Сравнений для поиска: " << simpleSearch -> matchCount << endl;

	 cout << "Бинарный поиск в отсортированном массиве: " << endl;
	 if (binarySearch -> resultIndex >= 0)
		cout << "Результат: " << array[binarySearch -> resultIndex] << endl;
	 else
		cout << "Чисел не найдено" << endl;
	 cout << "Сравнений для поиска: " << binarySearch -> matchCount << " (тут всегда будет ноль)" << endl;
	 
	 // system("pause");

	 out: return 0;
}

void sort (int* array, int size) {
	int j, x;
	for(int i = 1; i < size; i++) {
		x = array[i];
		j = i - 1;
		while(x < array[j] && j >= 0) {
			array[j + 1] = array[j];
			j--;
		}
		array[j + 1] = x;
	}
}

SearchResult* searchNeg (int* array, int size) {
	SearchResult* r = defaultSR();
	for (unsigned int i = 0; i < size; i++) {
		r -> matchCount++;
		if (array[i] < 0) {
			r -> resultIndex = i;
			break;
		}
	}
	return r;
}

template<typename T> SearchResult* searchInSorted (T* a, int size, T key) {
	SearchResult* r = defaultSR();
	int left = 0, right = size - 1, center;
	do {
		center = (left + right) / 2;
		if (a[center] < key)
			left = center + 1;
		else
			right = center;
	}
	while (left != right);

	r -> resultIndex = a[left] == key ? left : -1;
	return r;
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

int lim (int* array_ptr, int size, bool max) {
	int temp = 0;
	for (int i = 0; i < size; i++) {
		if (max) {
			if (array_ptr[i] > array_ptr[temp])
				temp = i;
		}
		else
			if (array_ptr[i] < array_ptr[temp])
				temp = i;
	}
	return temp;
}

void fillArray (int* array_ptr, int startIndex, int endIndex) {
	for (int i = startIndex; i <= endIndex; i++)
		array_ptr[i] = mrand(RAND_UP, RAND_DOWN);
}

SearchResult* defaultSR () {
	SearchResult* ret = new SearchResult;
	ret -> resultIndex = -1;
	ret -> matchCount = 0;
	return ret;
}