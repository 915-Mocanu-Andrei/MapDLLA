#include "Map.h"
#include "MapIterator.h"

Map::Map() {
	//TODO - Implementation
	this->elems = new TElem[10];//[1000000];
	this->next = new int[10];
	this->prev = new int[10];
	this->capacity = 10;
	this->first_empty = 0;
	this->head = 0;
	this->tail = 0;
	//
	this->next[0] = -1;
	this->prev[0] = -1;
	this->nr_elems = 0;
	//
	this->elems[0].first = -102;
	this->elems[0].first = -102;
}

Map::~Map() {
	//TODO - Implementation
}

TValue Map::add(TKey c, TValue v){
	if (this->first_empty == this->capacity - 2) {
		this->elems = this->resize_array(this->elems, this->capacity);
		this->next = this->resize_array(this->next,this->capacity);
		this->prev = this->resize_array(this->prev, this->capacity);
		this->capacity = this->capacity * 2;
	}
	if (this->isEmpty()) {
		this->nr_elems++;
		TElem elem;
		elem = TElem(c, v);
		this->elems[this->first_empty] = elem;
		this->next[this->first_empty] = -1;
		this->prev[this->first_empty] = this->tail;
		//if (this->nr_elems != 1)
		//	this->next[this->tail] = this->first_empty;
		this->tail = this->first_empty;
		this->head = this->first_empty;
		this->first_empty++;
		return NULL_TVALUE;
	}

	//TODO - Implementation
	int index = this->head;
	TElem current = this->elems[index];
	int found = 1;
	while (current.first != c) {
		index = this->next[index];
		if (index == -1) {
			found = 0;
			break;
		}
		current = this->elems[index];
	}
	if (found == 0) {
		this->nr_elems++;
		TElem elem;
		elem = TElem(c, v);
		this->elems[this->first_empty] = elem;
		this->next[this->first_empty] = -1;
		this->prev[this->first_empty] = this->tail;
		//if (this->nr_elems !=1)
		//	this->next[this->tail] = this->first_empty;
		this->tail = this->first_empty;
		this->first_empty++;
		return NULL_TVALUE;
	}
	if (found == 1) {
		//i can use the idex
		auto old_value = this->elems[index].second;
		this->elems[index].second = v;
		return old_value;
	}
	return NULL_TVALUE;
}

TValue Map::search(TKey c) const{
	//TODO - Implementation
	int index = this->head;
	TElem current = this->elems[index];
	int found = 1;
	while (current.first != c) {
		index = this->next[index];
		if (index == -1) {
			found = 0;
			break;
		}
		current = this->elems[index];
	}
	if (found == 1) {
		return this->elems[index].second;
	}
	return NULL_TVALUE;
}

TValue Map::remove(TKey c){
	//TODO - Implementation
	if (this->isEmpty()) {
		return NULL_TVALUE;
	}
	int index = this->head;
	TElem current = this->elems[index];
	int found = 1;
	while (current.first != c) {
		index = this->next[index];
		if (index == -1) {
			found = 0;
			break;
		}
		current = this->elems[index];
	}
	if (found == 1) {
		this->nr_elems--;
		if (this->head == index) {
			this->head = this->next[index];
			this->prev[this->next[index]] = -1;
			return this->elems[index].second;
		}
		if (this->tail == index) {
			this->tail = this->prev[index];
			this->next[this->prev[index]] = -1;
			return this->elems[index].second;
		}
		this->next[this->prev[index]] = this->next[index];
		this->prev[this->next[index]] = this->prev[index];
		return this->elems[index].second;
	}
	return NULL_TVALUE;
}


int Map::size() const {
	return this->nr_elems;
	//TODO - Implementation
	return 0;
}

bool Map::isEmpty() const{
	//TODO - Implementation
	if(this->nr_elems == 0)
		return true;
	return false;
}

MapIterator Map::iterator() const {
	return MapIterator(*this);
}

TElem* Map::resize_array(TElem* arr, int size_arr) {
	TElem* new_arr;
	int new_size = 2 * size_arr;
	new_arr = new TElem[new_size];
	for (int i = 0; i <= size_arr; i++) {
		new_arr[i] = arr[i];
	}
	delete[] arr;
	return new_arr;
}

int* Map::resize_array(int* arr, int size_arr) {
	int* new_arr;
	int new_size = 2 * size_arr;
	new_arr = new int[new_size];
	for (int i = 0; i <= size_arr; i++) {
		new_arr[i] = arr[i];
	}
	return new_arr;
}


