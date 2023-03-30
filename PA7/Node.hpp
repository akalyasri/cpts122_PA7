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

	Node<T>* getpNext(void) {
		return pNext;
	}

	void setpNext(Node<T>* newNode) {
		pNext = newNode;
	}


private:

	Node <T> * pNext; 

	T Data;
	
};

