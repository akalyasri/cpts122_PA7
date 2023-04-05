#include "List.hpp"
#include "Data.hpp"
using std::getline;
using std::stringstream;


class Menu {

public:

	void readCourseList(void) {

		clFile.open("classList.csv");

		string line;
		getline(clFile, line);


		while (getline(clFile, line)) {

			string token;
			stringstream ss(line);

			while (getline(ss, token, ',')) {


			}


		}

		

			
		//record Number,ID,Name,Email,Units,Program,Level

		//create node

		//get each part of the input file

		//insert into recordList

		// then loop

	}




private:



	fstream clFile;

};

