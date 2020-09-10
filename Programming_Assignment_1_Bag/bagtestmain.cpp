/*
* File:   bagtestmain.cpp
* Author: Prof Sipantzi -- CSIS 215 -- Programming Assignment 1 -- Bag Dictionary
*
* Created on July 14, 2012, 11:45 AM
* Updated pointers to smart pointers in ABag and BDictionary on 12/14/2018
*/

#include <string>
#include <sstream>
#include "ABag.h"
#include "BDictionary.h"

using namespace std;

const size_t DICTIONARY_SIZE = 10;

void wait(); //Used to pause screen output

/*
* Tests BDictionary with int and string objects only.
*/
int main(int argc, char** argv) {

	cout << "Cameron Burkholder -- CSIS 215 Programming Assignment 1 -- Bag Dictionary" << endl << endl;

	BDictionary<int, string> myIntStrDict(DICTIONARY_SIZE);
	BDictionary<string, int> myStrIntDict(DICTIONARY_SIZE);

	// myIntStrDict tests
	// INSERT: myIntStrDict
	cout << "Testing dictionary with <int, string> KV Pair\n";
	for (int i = 1; i <= DICTIONARY_SIZE; i++) {
		stringstream sn;
		sn << "Beth " << i * 10;
		myIntStrDict.insert(i * 10, sn.str());
	}
	cout << "INSERT: Size of myIntStrDict is " << myIntStrDict.size() << endl;

	// REMOVEANY: myIntStrDict
	string strData;
	if (myIntStrDict.removeAny(strData) == true) {
		cout << "REMOVEANY: My string data is " << strData << endl;
	}
	else {
		cout << "RemoveAny() failed -- dictionary is empty.\n";
	}
	cout << "Size of myIntStrDict is " << myIntStrDict.size() << "\n";

	// FIND: test for myIntStrDict.find
	int intKey = 40;
	if (myIntStrDict.find(intKey, strData) == true) {
		cout << "FIND: My data at key==" << intKey << " is: " << strData << "\n";
		cout << "Size of myIntStrDict is " << myIntStrDict.size() << "\n";
	}
	else {
		cout << "Could not find a record at " << intKey << "\n";
	}
	

	// REMOVE: myIntStrDict
	intKey = 60;
	if (myIntStrDict.remove(intKey, strData) == true) {
		cout << "REMOVE: Removed key " << intKey << " which was " << strData << "\n";
	}
	else {
		cout << "Could not find key " << intKey << "\n";
	}
	cout << "Size of my dictionary is " << myIntStrDict.size() << "\n";

	// CLEAR: myIntStrDict
	myIntStrDict.clear();
	cout << "CLEAR: Size of myIntStrDict is " << myIntStrDict.size() << "\n\n";

	/* end myIntStrDict tests ---------------------------------------------*/

	// myStrIntDict tests
	// INSERT: myStrIntDict
	cout << "Testing dictionary with <string, int> KV Pair\n";
	myStrIntDict.insert("Terri", 57);
	myStrIntDict.insert("Beth", 53);
	myStrIntDict.insert("Jeremy", 19);
	myStrIntDict.insert("Nathan", 17);
	myStrIntDict.insert("Zipper", 2);
	myStrIntDict.insert("Button", 1);
	myStrIntDict.insert("Kiwi", 7);
	myStrIntDict.insert("Masoala", 10);

	cout << "INSERT: Size of myStrIntDict is " << myStrIntDict.size() << endl;

	// REMOVEANY: myStrIntDict
	int intData;
	if (myStrIntDict.removeAny(intData) == true) {
		cout << "REMOVEANY: My int data is " << intData << endl;
	}
	else {
		cout << "RemoveAny() failed -- dictionary is empty.\n";
	}
	cout << "Size of myIntStrDict is " << myStrIntDict.size() << "\n";

	// FIND: myStrIntDict.find
	string strKey = "Kiwi";
	if (myStrIntDict.find(strKey, intData) == true) {
		cout << "FIND: " << strKey << "\'s age is " << intData << endl;
		cout << "Size of myStrIntDict is " << myStrIntDict.size() << "\n";
	}
	else {
		cout << "Could not find a record at " << strKey << "\n";
	}

	// REMOVE: myStrIntDict
	strKey = "Button";
	if (myStrIntDict.remove(strKey, intData) == true) {
		cout << "REMOVE: Removed key " << strKey << " which was " << intData << "\n";
	}
	else {
		cout << "Could not find key " << strKey << "\n";
	}
	cout << "Size of my dictionary is " << myStrIntDict.size() << "\n";

	// CLEAR: myStrIntDict
	myStrIntDict.clear();
	cout << "CLEAR: Size of myStrIntDict is " << myStrIntDict.size() << "\n\n";

	/* end myStrIntDict tests ---------------------------------------------*/

	/* Demonstrate any Bag functions that were not used/demonstrated in the implemention 
	of your BDictionary and ABag using a Bag of KVpairs<int, string>. */

	
	ABag<KVpair<int, string>> myBag; //Used to test bag functions not previously demonstrated
	std::cout << std::endl;
	std::cout << "SUITE: ABag.h" << std::endl;
	{
		KVpair<int, std::string> pair = KVpair<int, std::string >(1, "Cameron Burkholder");
		ABag<KVpair<int, std::string>> testBag = ABag<KVpair<int, std::string>>(10);

		/*
		std::cout << "TEST: addItem" << std::endl;
		std::cout << "\tShould be 1: " << testBag.addItem(pair) << std::endl;
		*/

		/*
		std::cout << "TEST: removeTop" << std::endl;
		KVpair<int, std::string> removedPair;
		cout << "\tShould be 1: " << testBag.removeTop(removedPair) << std::endl;
		cout << "\tKey: " << removedPair.key() << std::endl;
		cout << "\tValue: " << removedPair.value() << std::endl;
		*/

		/*
		std::cout << "TEST: emptyBag" << std::endl;
		testBag.emptyBag();
		std::cout << "\tShould be 0: " << testBag.inspectTop(pair) << std::endl;
		*/

		std::cout << "TEST: inspectTop" << std::endl;
		testBag.addItem(pair);
		KVpair<int, std::string> pair2 = KVpair<int, std::string>(2, "Other name");
		testBag.addItem(pair2);
		std::cout << "\tShould be 1: " << testBag.inspectTop(pair) << std::endl;
		std::cout << "\tShould be Other Name: " << pair.value() << std::endl;

		/*
		std::cout << "TEST: remove" << std::endl;
		testBag.addItem(pair);
		std::cout << "\tShould be 1: " << testBag.remove(pair) << std::endl;
		*/

		/*
		std::cout << "TEST: find" << std::endl;
		testBag.addItem(pair);
		KVpair<int, std::string> newPair = KVpair<int, std::string>(2, "Caleb");
		testBag.addItem(newPair);
		KVpair<int, std::string> keyPair = KVpair<int, std::string>(2, "Undefined");
		std::cout << "\tShould be 1: " << testBag.find(keyPair) << std::endl;
		std::cout << "\tShould be 'Caleb': " << keyPair.value() << std::endl;
		*/

		/*
		std::cout << "TEST: emptyBag" << std::endl;
		testBag.emptyBag();
		std::cout << "\tShould be 0: " << testBag.inspectTop(pair) << std::endl;
		*/

		std::cout << "TEST: +=" << std::endl;
		KVpair<int, std::string> pairThree = KVpair<int, std::string>(3, "Three");
		testBag += pairThree;
		std::cout << "\tShould be 1: " << testBag.inspectTop(pair) << std::endl;
		std::cout << "\tShould be 'Three': " << pair.value() << std::endl;

		/*
		std::cout << "TEST: size" << std::endl;
		std::cout << "\tShould be 1: " << testBag.size() << std::endl;
		*/

		std::cout << "TEST: bagCapacity" << std::endl;
		std::cout << "\tShould be 10: " << testBag.bagCapacity() << std::endl;

	}
	std::cout << std::endl;

	wait();

	return 0;
}

//Used to pause the screen wherever desired
void wait()
{
	//The following if-statement checks to see how many characters are in cin's buffer
	//If the buffer has characters in it, the clear and ignore methods get rid of them.
	if (cin.rdbuf()->in_avail() > 0) //If the buffer is empty skip clear and ignore
	{
		cin.clear();
		cin.ignore(256, '\n'); //Clear the input buffer 
	}
	char ch;
	cout << "Press the Enter key to continue ... ";
	cin.get(ch);
}