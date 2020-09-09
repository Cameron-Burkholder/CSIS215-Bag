/*	ABag.h

	Purpose: implement the bag abstract data type using an array

	Author: Cameron Burkholder
	Created on 09/08/2020
*/

#include <memory>			// For using Smart Pointers
#include "bagADT.h"			// For inheriting from the ADT

const size_t BAG_SIZE = 10;

#pragma once
template <typename E>
class ABag : protected Bag<E> {
private:
	int maxSize;
	int top;
	E* bag;
public:

	ABag(size_t size = BAG_SIZE) {
		maxSize = size;
		top = 0;
		bag = new E[maxSize];
	}
	~ABag() {
		delete[] bag;
	}

	// Insert a new item into the bag -- return false if fails and true if
	// successful
	bool addItem(const E& item) {
		if (top != maxSize) {
			bag[top++] = item;
			return true;
		}
		else {
			return false;
		}
	}

	// Looks for 'item' in the bag and if found updates 'item' with the 
	// bag value and returns true.  Otherwise 'item' is left unchanged
	// and the method returns false.
	bool remove(E& item) {
		bool isFound = false;
		for (int i = 0; i < top; i++) {
			if (bag[i] == item) {
				item = bag[i];
				isFound = true;
				for (int j = i + 1; j < top; j++) {
					bag[i] = bag[j];
				}
				top--;
				break;
			}
		}
		return isFound;
	}

	// Removes the top record from the bag, puts it in returnValue, and
	// returns true if the bag is not empty.  If the bag is empty the 
	// function returns false and returnValue remains unchanged.
	bool removeTop(E& returnValue) {
		if (top != 0) {
			returnValue = bag[--top];
			return true;
		}
		else {
			return false;
		}
	}

	// Finds the record using returnValue and if the record is found updates
	// returnValue based on the contents of the bag and returns true.  If the
	// record is not found the function returns false.  Works just like remove()
	// except that the found record is not removed from the bag.
	bool find(E& returnValue) const {
		bool isFound = false;
		for (int i = 0; i < top; i++) {
			if (bag[i] == returnValue) {
				returnValue = bag[i];
				isFound = true;
				break;
			}
		}
		return isFound;
	}

	// Inspect the top of the bag.  If the bag is empty return
	// false and leave 'item' unchanged; otherwise, return true and update 
	// 'item' with the contents of the bag.
	bool inspectTop(E& item) const {
		if (top != 0) {
			item = bag[top - 1];
			return true;
		}
		else {
			return false;
		}
	}
	

	// empties the bag
	void emptyBag() {
		top = 0;
	}

	// use the += operator to add an item to the bag
	bool operator+=(const E& addend) {
		return addItem(addend);
	}

	// get the number of items in the bag
	int size() const {
		return top;
	}

	// get the capacity of the bag (size of your bag's array)
	int bagCapacity() const {
		return maxSize;
	}
};