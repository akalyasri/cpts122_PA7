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

	void markAbsences(void) {

		Node<Data>* pCur = absentLists.pHead;

		//cout << "Student Names: " << endl << endl;

		int userInput;

		while (pCur != nullptr) {

			//cout << pCur->getData()->firstName << " " << pCur->getData()->lastName << endl;

			cout << "Was " << pCur->getData()->firstName << " " << pCur->getData()->lastName << " absent today?" << endl << endl;

			cout << "Enter '1' for yes or '0' for no." << endl;

			cin >> userInput;

			if (userInput == 1) {

				pCur->getData()->markAbsence();
			} 
			else if (userInput != 0 && userInput != 1) {

				cout << "Invalid. Must enter either 0 or 1." << endl;
				system("pause");
			}

			
			system("cls");

			pCur = pCur->getpNext();

		}

	}


	void editAbsence(void) {
		//BONUS

	}

	void generateReport(void) {

		cout << "OPTIONS:" << endl << endl;
		cout << "1. Generate report for all students" << endl;
		cout << "2. Generate report for students with absences that match or exceed a certain number. " << endl << endl;

		cout << "Enter a corresponding number (1 or 2)" << endl;

		int userInput = 0;
		int reportNum = 0;

		Node<Data>* pCur = absentLists.pHead;

		cin >> userInput;

		switch (userInput) {
		
		case 1:

			system("cls");

			cout << "Most Recent Absence for Each Student: " << endl << endl;

			while (pCur != nullptr) {
				cout << pCur->getData()->firstName << " " << pCur->getData()->lastName << " : " << pCur->getData()->AbsenceDates.peek() << endl;

				pCur = pCur->getpNext();
			}

			break;


		case 2:

			system("cls");

			cout << "Enter a number to generate a report for students that match or exceed that number: " << endl;

			cin >> reportNum;

			while (pCur != nullptr) {

				if (pCur->getData()->numOfAbsences >= reportNum) {

					cout << pCur->getData()->firstName << " " << pCur->getData()->lastName << " : " << pCur->getData()->AbsenceDates.peek() << endl;

				}
				pCur = pCur->getpNext();
			}
			
			break;
		
		default:
			cout << "Invalid.Enter either 1 or 2." << endl;
			break;
		}

	}



private:

	List<Data> absentLists;
	fstream clFile;
	fstream mFile;

};

