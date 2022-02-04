#include "ExtendedTest.h"
#include "ShortTest.h"
#include "MapIterator.h"
#include "Map.h"
#include <assert.h>

#include <iostream>
using namespace std;


int main() {
	testAll();
	cout << "End short test!";
	cout << "\n";
	testAllExtended();
	Map m;
	m.add(5, 5);
	m.add(2, 111);
	m.add(10, 110);
	m.add(7, 7) ;
	m.add(1, 1);
	m.add(8, 10);
	m.add(-3, -3);
	m.add(4, 4);
	MapIterator mi = m.iterator();
	int i = 0;
	while (mi.valid()) {
		TElem e = mi.getCurrent();
		if (i == 0) {
			assert(e.first == 5);
		}
		if (i == 1) {
			assert(e.first == 10);
		}
		if (i == 2) {
			assert(e.first == 1);
		}
		if (i == 3) {
			assert(e.first == -3);
		}
		i++;
		mi.jumpForward(2);
	}
	MapIterator mi2 = m.iterator();
	mi2.first();
	assert(mi2.valid() == true);
	mi2.jumpForward(20);
	//invalidate iterator
	assert(mi2.valid() == false);
	mi2.first();
	assert(mi2.valid() == true);
	//throw exception
	try {
		mi2.jumpForward(-2);
	}
	catch(exception){
		assert(true);
	}
	cout << "That's all!" << endl;
	system("pause");
	return 0;
}


