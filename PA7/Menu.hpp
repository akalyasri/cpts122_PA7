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

	void printMenu(void) {
		cout << "*********    MENU    *********" << endl;
		cout << "*                            *" << endl;
		cout << "*  1. Import Course List     *" << endl;
		cout << "*  2. Load Master List       *" << endl;
		cout << "*  3. Store Master List      *" << endl;
		cout << "*  4. Mark Absences          *" << endl;
		cout << "*  5. Edit Absences          *" << endl;
		cout << "*  6. Generate Report        *" << endl;
		cout << "*  7. Exit                   *" << endl;
		cout << "*                            *" << endl;
		cout << "******************************" << endl << endl << endl;


		cout << "Enter your choice: " << endl;
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
					absentLists.insertNode(recordNumInput, idInput, firstNameRef, lastNameRef, emailRef, creditRef, programRef, levelRef,numofAbsences = 0);
				}

			}


		}

		

			
		//record Number,ID,Name,Email,Units,Program,Level

		//create node

		//get each part of the input file

		//insert into recordList

		// then loop

	}

	void loadMasterList(void) {

		//read from master.csv to nodes

		mFile.open("master.csv");
		string line;

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


		string& firstNameRef = firstNameInput;
		string& lastNameRef = lastNameInput;
		string& emailRef = emailInput;
		string& creditRef = creditInput;
		string& programRef = programInput;
		string& levelRef = levelInput;
		string& dateRef = absentDate;

		while (getline(mFile, line)) {

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
					temp = temp.substr(1, temp.length());    //substr(position, up to how long you want)
					lastNameInput = temp;
					break;

				case 3:
					//first name
					temp = temp.substr(0, temp.length() - 1);
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

				case 8:
					//num of absences
					numofAbsences = stoi(temp);
					absentLists.insertNode(recordNumInput, idInput, firstNameRef, lastNameRef, emailRef, creditRef, programRef, levelRef, numofAbsences);
					break;

				case 9:
					absentDate = temp;
					absentLists.pHead->getData()->AbsenceDates.push(absentDate);
					numofAbsences++;

					while (getline(ss, temp, ',')) {
						absentDate = temp;
						
						absentLists.pHead->getData()->AbsenceDates.push(absentDate);
						numofAbsences++;
					}

					absentLists.pHead->getData()->numOfAbsences = numofAbsences;

					break;

				default:
					
					break;

				}

				fieldIndex++;

				/*if (fieldIndex == 8) {
					absentLists.insertNode(recordNumInput, idInput, firstNameRef, lastNameRef, emailRef, creditRef, programRef, levelRef, numofAbsences = 0, dateRef = "");
				}*/

			}


		}

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

		// ask for name or ID

		cout << "OPTIONS FOR SEARCHING STUDENT:" << endl << endl;
		cout << "1. Search by name" << endl;
		cout << "2. Search by ID" << endl << endl;

		int userInput = 0;
		int idInput = 0;
		string firstNameInput;
		string lastNameInput;

		int deleteInput = 0;
		int vectorIndex = 0;
		
		Node<Data>* pCur = absentLists.pHead;


		cin >> userInput;

		switch(userInput){

		case 1:

			cout << "Enter a first and last name (ex: Joe Smith)" << endl;

			cin >> firstNameInput >> lastNameInput;

			while (pCur != nullptr) {

				//locate node
				if (pCur->getData()->firstName == firstNameInput && pCur->getData()->lastName == lastNameInput) {

					//print all absent dates from that specific node's stack
					for (auto dates : pCur->getData()->AbsenceDates.getDates()) {

						//ask if user wants to edit that date
						if (dates != "") {
							system("cls");
							cout << "Would you like to delete this absence : " << dates << " ?" << endl << endl;
							cout << "Enter 1 for yes and 0 for no" << endl;
							cin >> deleteInput;

							switch (deleteInput) {

							case 0:
								//if no, skip to next date
								system("cls");
								break;


							case 1:
								//if yes, remove date and numofAbsensces - 1

								pCur->getData()->AbsenceDates.pop(vectorIndex);

								pCur->getData()->numOfAbsences--;
								break;

						

							default:
								cout << endl << "Invalid Input." << endl;
								break;

							}


						}

						vectorIndex++;
					}


				}

				pCur = pCur->getpNext();

			}



			break;

		case 2:

			cout << "Enter a student ID: " << endl;
			cin >> idInput;

			while (pCur != nullptr) {

				if (pCur->getData()->ID == idInput) {

					// iterate through the vector

					for (auto dates : pCur->getData()->AbsenceDates.getDates()) {
						if (dates != "") {

							cout << "Would you like to delete this absence : " << dates << " ?" << endl << endl;
							cout << "Enter 1 for yes and 0 for no" << endl;
							cin >> deleteInput;

							switch (deleteInput) {

							case 0:
								//if no, skip to next date
								system("cls");
								break;

							case 1:
								//if yes, remove date and numofAbsensces - 1

								pCur->getData()->AbsenceDates.pop(vectorIndex);

								pCur->getData()->numOfAbsences--;
								break;

							

							default:
								cout << endl << "Invalid Input." << endl;
								break;

							}
						}

						vectorIndex++;
					}


				}

				pCur = pCur->getpNext();
			}


			break;

		default:
			cout << endl << "Invalid Input." << endl;
			break;

		}


		
		
		

		

		

		





	}

	void generateReport(void) {

		cout << "OPTIONS:" << endl << endl;
		cout << "1. Generate report for all students" << endl;
		cout << "2. Generate report for students with absences that match or exceed a certain number. " << endl << endl;

		cout << "Enter a corresponding number (1 or 2)" << endl;

		int userInput = 0;
		int reportNum = 0;
		int printedAbsences = 0;

		Node<Data>* pCur = absentLists.pHead;

		if (pCur == nullptr) {
			cout << "Nothing to report. List empty." << endl;
			return;
		}

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
					
					printedAbsences++;
				}
				
				pCur = pCur->getpNext();
			}
			
			if (printedAbsences == 0) {
				system("cls");
				cout << "Nothing to report. No student has or exceeded " << reportNum << " absence(s)." << endl;
			}

			break;
		
		default:
			cout << "Invalid.Enter either 1 or 2." << endl;
			break;
		}

	}

	void exit(void) {
		system("cls");
		cout << "App Closing..." << endl;
		return;
	}

private:

	List<Data> absentLists;
	fstream clFile;
	fstream mFile;

};

