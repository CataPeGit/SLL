// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <assert.h>
#include "SortedMultiMap.h"
#include "SMMIterator.h"
#include "ShortTest.h"
#include "ExtendedTest.h"

bool relation(TKey cheie1, TKey cheie2) {
	if (cheie1 <= cheie2) {
		return true;
	}
	else {
		return false;
	}
}

int main()
{


    //cout << endl; cout << endl; cout << endl; cout << endl; cout << endl; cout << endl; cout << endl; cout << endl;
	/*
    SortedMultiMap smm = SortedMultiMap(relation);
	std::cout << "empty trebe 1 " << smm.isEmpty();
	std::cout << std::endl;
	smm.add(1, 2);
	smm.add(1, 3);
	std::cout << "empty trebe 0 " << smm.isEmpty();
	std::cout << std::endl;
	std::cout << "remove trebe 1 " << smm.remove(1, 2);
	std::cout << std::endl;
	std::cout << "empty trebe 1 " << smm.isEmpty();
	std::cout << std::endl;
	std::cout << "remove trebe 1 " << smm.remove(1, 3);
	std::cout << std::endl;
	std::cout << "empty trebe 1 " << smm.isEmpty();
	std::cout << std::endl;

	std::cout << "remove trebe 0 " << smm.remove(2, 1);
	std::cout << std::endl;
	std::cout << "empty trebe 1 " << smm.isEmpty();
	std::cout << std::endl << "pana aici fac" << std::endl;

	*/
    testAll();
    std::cout << "Passed ShortTest!" << std::endl;	
	


    testAllExtended();
    std::cout << "Hello World!\n";
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
