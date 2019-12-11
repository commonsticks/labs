#include "lab6.h"
#define MIN_AGE 25

const char* Generator::names[] = {"クコンデル", "John Smith", "Иван Иванычь"};
const int Generator::namesCount = 3;


bool iter (Person p) {
	using namespace std;
	cout << "Name: " << p.name << "; Age: " << p.age << endl;
	return true;
}

bool ageFilter (Person p) {
	return p.age > MIN_AGE;
}

int main () {
	using namespace std;

	setlocale(0, "russian");

	cout << "Лабораторная работа 6. Вариант 6." << endl;
	cout << "Динамический массив структур:" << endl;

	ImmuteContainer ic(5, *new Generator);
	ic.iterate(*iter);

	cout << "\nПоиск указанных элементов:" << endl;	
	ImmuteContainer filtered = ic.filter(*ageFilter);
	filtered.iterate(*iter);

	cout << "\nДинамический массив строк:" << endl;

	Generator generator;
	int c = 3;
	char** strings = new char*[c];
	for (int i = 0; i < c; i++) {
		strings[i] = generator.randomString();
		cout << strings[i] << endl;
	}

	cout << "\nУдаление первой строки:" << endl;
	for (int i = 1; i < c; i++)
		cout << strings[i] << endl;

	return 0;
}