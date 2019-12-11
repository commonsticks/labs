#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Person.h"

class Generator {
	private:
		const static char* names[];
		const static int namesCount;

		int mrand (int up, int down) {
			return rand() % up - down;
		}

	public:
		Generator () {
			srand(time(NULL));
		}

		Person& generate () {
			Person &p = *new Person;
			p.name = randomString();
			p.age = mrand(70, 0);

			return p;
		}

		char* randomString () {
			int name = mrand(200, 0) % namesCount;
			char *newName = new char[2];
			strcpy(newName, names[name]);

			return newName;
		}
};