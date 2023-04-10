#include "Data.hpp"
#include "List.hpp"
#include "Menu.hpp"

int main(void) {

	//int recordNumInput, int idInput, string& nameInput, string& emailInput, string creditInput, string& programInput, string& levelInput, int absenceNum, string& dateOfAbsence
	//List<Data> absentLists;

	int menuInput = 0;

	/*
	int recordNumInput = 1; 
	int idInput = 032;

	string nameInput = "Akalya"; 
	string& nameRef = nameInput;

	string emailInput = "akalya@gmail.com";
	string& emailRef = emailInput;

	string creditInput = "4";
	string& creditRef = creditInput;

	string programInput = "CPTS";
	string& programRef = programInput;

	string levelInput = "freshman";
	string& levelRef = levelInput;

	int absenceNum = 1;

	string dateOfAbsence = "01/01/01";
	string& dateRef = dateOfAbsence;

	absentLists.insertNode(recordNumInput,idInput,nameRef,emailRef,creditInput,programRef,levelRef,absenceNum,dateRef);

	*/

	Menu App;
	fstream clFile;
	fstream mFile;


	App.printMenu();
	cin >> menuInput;

	while (menuInput != 7) {


		switch (menuInput) {

		case 1:
			system("cls");

			App.readCourseList();
			cout <<endl<< "Read course list." << endl;

			system("pause");
			system("cls");

			App.printMenu();
			cin >> menuInput;

			break;
		
		case 2:
			system("cls");

			App.loadMasterList();
			cout << "Loaded master list" << endl;

			system("pause");
			system("cls");

			App.printMenu();
			cin >> menuInput;

			break;

		case 3:
			system("cls");

			App.storeMasterList();
			cout << "Stored master list." << endl;

			system("pause");
			system("cls");

			App.printMenu();
			cin >> menuInput;
			break;

		case 4:
			system("cls");

			App.markAbsences();

			system("pause");
			system("cls");

			App.printMenu();
			cin >> menuInput;
			break;

		case 5:
			system("cls");

			App.editAbsence();

			system("pause");
			system("cls");

			App.printMenu();
			cin >> menuInput;
			break;
		
		case 6:
			system("cls");

			App.generateReport();

			system("pause");
			system("cls");

			App.printMenu();
			cin >> menuInput;
			break;

		default:
			system("cls");

			cout << "Invalid Input. Try again" << endl;
			system("pause");
			system("cls");

			App.printMenu();
			cin >> menuInput;
			break;
		}
	}
	
	if (menuInput == 7) {
		
		App.exit();
		return 0;
			
	}
	


	

}

