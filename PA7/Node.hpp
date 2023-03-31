#pragma once
#include <iostream>
#include <fstream>
#include <string>


using std::cin;
using std::cout;

using std::ifstream;
using std::ofstream;
using std::fstream;
using std::string;



template <typename T>
class Node {

public:

	Node() {
		pNext = nullptr;
	}

	Node(int recordNumInput, int idInput, string& nameInput, string& emailInput, int creditInput, string& programInput, string& levelInput, int absenceNum, string& dateOfAbsence) {

		singleData.recordNum = recordNumInput;

		singleData.name = nameInput;

		singleData.email = emailInput;

		singleData.credits = creditInput; 
		
		singleData.program = programInput; 

		singleData.level = levelInput;

		singleData.numOfAbsences = absenceNum;

		singleData.AbsenceDates.push(dateOfAbsence);

		// singleData.AbsenceDates.push(dateOfAbsence); for testing


	}

	Node<T>* getpNext(void) {
		return pNext;
	}

	void setpNext(Node<T>* newNode) {
		pNext = newNode;
	}

	T* getData(void) {

		return &singleData;

	}


private:

	Node <T> * pNext; 

	Data singleData;

	//friend class List<T>;
	
};

