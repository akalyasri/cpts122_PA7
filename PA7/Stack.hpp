#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>
#include <ctime>
#include <sstream>

using std::cin;
using std::cout;

using std::ifstream;
using std::ofstream;
using std::fstream;
using std::string;
using std::vector;


class Stack {
public:

	void push(string dateInput) {

		//inserting

		dates.push_back(dateInput); // insert at back of the vector

	} 

	string peek(void) {

		//get top of stack without deleting - the top is now the back of a vector

		return dates.back();

	}

	string pop(void) {
		
		// deleteing pTop from stack and returning

		dates.pop_back(); //removes the last element of a stack

		// dates.erase(dates.begin()); // removes the first element of a stack

	}

	bool isEmpty(void) {

		//return true for empty stack

		return dates.empty();

	} 

	size_t vecSize(void) {

		return dates.size();
	}


private:

	vector<string> dates;

};
