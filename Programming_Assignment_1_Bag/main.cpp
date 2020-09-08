// Programming_Assignment_1_Bag.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <string>
#include "ABag.h"
#include "../kvpair.h";

int main()
{
    std::cout << "Cameron Burkholder - CSIS215 - Lab 1" << std::endl;

    std::cout << std::endl;
    std::cout << "SUITE: ABag.h" << std::endl;
    {
        KVpair<int, std::string> pair = KVpair<int, std::string >(1, "Cameron Burkholder");
        ABag<KVpair<int, std::string>> testBag = ABag<KVpair<int, std::string>>(10);

        std::cout << "TEST: addItem" << std::endl;
        std::cout << "\tShould be 1: " << testBag.addItem(pair) << std::endl;

        std::cout << "TEST: removeTop" << std::endl;
        KVpair<int, std::string> removedPair;
        cout << "\tShould be 1: " << testBag.removeTop(removedPair) << std::endl;
        cout << "\tKey: " << removedPair.key() << std::endl;
        cout << "\tValue: " << removedPair.value() << std::endl;

        std::cout << "TEST: emptyBag" << std::endl;
        testBag.emptyBag();
        std::cout << "\tShould be 0: " << testBag.inspectTop(pair) << std::endl;

        std::cout << "TEST: inspectTop" << std::endl;
        std::cout << "\tShould be 0: " << testBag.inspectTop(pair) << std::endl;

    }
    std::cout << std::endl;
    
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
