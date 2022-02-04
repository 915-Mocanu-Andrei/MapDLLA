#include "Map.h"
#include "MapIterator.h"
#include <exception>
using namespace std;


MapIterator::MapIterator(const Map& d) : map(d)
{
	//TODO - Implementation
	this->index = this->map.head;
}


void MapIterator::first() {
	//TODO - Implementation
	this->index = this->map.head;
}


void MapIterator::next() {
	//TODO - Implementation
	if (!this->valid()) {
		throw exception();
	}
	this->index = this->map.next[this->index];
}


TElem MapIterator::getCurrent(){
	//TODO - Implementation
	if (!this->valid()) {
		throw exception();
	}
	return this->map.elems[index];
}


bool MapIterator::valid() const {
	//TODO - Implementation
	if (this->index == -1 || this->map.isEmpty())
		return false;
	return true;
}

void MapIterator::jumpForward(int k) {
	//Best case: Theta(1) --when k<=0 or k>map.size()
	//Worst case: Theta(k)  
	//Average case: Theta(k) --when k== n where n is the size of the map
	//Overall complexity: O(k)  
	if (k <= 0 || !this->valid()) {
		//throws exception if k is zero or negative or the it is invalid
		throw exception();
	}
	if (k > this->map.size()) {
		//makes the iterator invalid if there are less than k elements left in the Map.
		this->index = -1;
		return;
	}
	while (k != 0) {
		//moves the current element from the iterator k steps forward
		if (!this->valid()) {
			break;
		}
		this->index = this->map.next[this->index];
		k--;
	}
}



