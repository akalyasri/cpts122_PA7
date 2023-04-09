#include "Data.hpp"
#include "List.hpp"
#include "Menu.hpp"

int main(void) {

	//int recordNumInput, int idInput, string& nameInput, string& emailInput, string creditInput, string& programInput, string& levelInput, int absenceNum, string& dateOfAbsence
	//List<Data> absentLists;

	
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

	App.readCourseList();
	App.storeMasterList();
	//App.markAbsences();
	App.generateReport();
	

}

