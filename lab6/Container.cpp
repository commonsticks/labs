#include "Generator.h"
#include "Person.h"

class ImmuteContainer {
	private:
		Generator *generator;
		Person* persons;
		int count;

		ImmuteContainer (const int icount, Person* filtered) {
			count = icount;
			persons = filtered;
		}
		
	public:
		ImmuteContainer (const int icount, Generator &igenerator) {
			count = icount;
			generator = &igenerator;

			persons = new Person[count];

			for (int i = 0; i < count; i++)
				persons[i] = generator -> generate();
		}

		void iterate (bool (*callback)(Person p)) {
			for (int i = 0; i < count; i++) {
				if (!callback(persons[i]))
					break;
			}
		}

		ImmuteContainer& filter (bool (*exteralFilter)(Person p)) {
			Person* filtered = new Person[count];
			int i, j;

			for (i = 0, j = 0; i < count; i++) {
				if (exteralFilter(persons[i])) {
					Person p;
					p = persons[i];
					filtered[j++] = p;
				}
			}

			return *new ImmuteContainer(j, filtered);
		}

		/*void null () {
			for (int i = 0; i < count; i++) {
				persons[i].age = 0;
			}
		}*/
};