#include "List.hpp"
#include "Data.hpp"
using std::getline;
using std::stringstream;


class Menu {

public:

	void readCourseList(void) {

		List<Data> absentLists;

		clFile.open("classList.csv");

		string line;
		getline(clFile, line);


		while (getline(clFile, line)) {

			string temp;	
			stringstream ss(line);

			while (getline(ss, temp, ',')) {





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

