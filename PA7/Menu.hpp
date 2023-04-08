//#include "List.hpp"
//#include "Data.hpp"
using std::getline;
using std::stringstream;
using std::endl;

class Menu {

public:

	Menu() {

	}

	~Menu() {

		clFile.close();
		mFile.close();

	}


	void readCourseList(void) {

		clFile.open("classList.csv");

		string line;

		//get first line
		getline(clFile, line); 

		int recordNumInput;
		int idInput;
		string firstNameInput;
		string lastNameInput;
		string emailInput;
		string creditInput;
		string programInput;
		string levelInput;
		string absentDate;

		int numofAbsences;


		while (getline(clFile, line)) {

			string temp;	
			stringstream ss(line);
			int fieldIndex = 0;

			while (getline(ss, temp, ',')) {


				switch (fieldIndex) {

				case 0:
					//record num
					recordNumInput = stoi(temp);
					break;

				case 1:
					//ID
					idInput = stoi(temp);
					break;

				case 2: 
					//last name
					temp = temp.substr(1,temp.length());    //substr(position, up to how long you want)
					lastNameInput = temp;
					break;

				case 3:
					//first name
					temp = temp.substr(0,temp.length() - 1);
					firstNameInput = temp;
					break;

				case 4:
					//email
					emailInput = temp;
					
					break;

				case 5:
					//credits
					creditInput = temp;
				
					break;

				case 6:
					//program
					programInput = temp;
					break;

				case 7:
					//level
					levelInput = temp;
					break;

				default:
					break;

				}

				string& firstNameRef = firstNameInput;
				string& lastNameRef = lastNameInput;
				string& emailRef = emailInput; 
				string& creditRef = creditInput;
				string& programRef = programInput;
				string& levelRef = levelInput;
				string& dateRef = absentDate;


				fieldIndex++;

				if (fieldIndex == 8) {
					absentLists.insertNode(recordNumInput, idInput, firstNameRef, lastNameRef, emailRef, creditRef, programRef, levelRef,numofAbsences = 0,dateRef = "");
				}

			}


		}

		

			
		//record Number,ID,Name,Email,Units,Program,Level

		//create node

		//get each part of the input file

		//insert into recordList

		// then loop

	}

	
	void storeMasterList(void) {

		mFile.open("master.csv", std::ios::out);


		Node<Data>* pCur = absentLists.pHead;

		while (pCur != nullptr) {


			mFile << pCur->getData()->recordNum << ","
				<< pCur->getData()->ID << ","
				<< "\"" << pCur->getData()->lastName << ","
				<< pCur->getData()->firstName << "\"" << ","
				<< pCur->getData()->email << ","
				<< pCur->getData()->credits << ","
				<< pCur->getData()->program << ","
				<< pCur->getData()->level << ","
				<< pCur->getData()->numOfAbsences;

				// iterate through the vector

			for (auto dates : pCur->getData()->AbsenceDates.getDates()) {
				if (dates != "") {
					mFile << "," << dates;
				}
			}

			mFile << endl;


			pCur = pCur->getpNext();
		}


	}



private:

	List<Data> absentLists;
	fstream clFile;
	fstream mFile;

};

