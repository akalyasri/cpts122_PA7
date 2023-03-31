#include "Stack.hpp"
//#include "List.hpp"



template<typename T>
class Node;


class Data {

public:

	Data(int recordNumInput, int idInput, string& nameInput, string& emailInput, int creditInput, string& programInput, string& levelInput, int absenceNum, string& dateOfAbsence) {

		recordNum = recordNumInput;
		ID = idInput;
		name = nameInput;
		email = emailInput;
		credits = creditInput;
		program = programInput;
		level = levelInput;
		numOfAbsences = absenceNum;
		
		AbsenceDates.push(dateOfAbsence);

	}

	Data() {

	}

	~Data() {


	}


	void markAbsence(void) { // use only when the user say yes to "is student absent today?"

		//got the following 9 lines of code from online
		auto now = std::chrono::system_clock::now();
		std::time_t current_time = std::chrono::system_clock::to_time_t(now);
		std::tm* time_info = std::localtime(&current_time);
		int year = time_info->tm_year + 1900;
		int month = time_info->tm_mon + 1;
		int day = time_info->tm_mday;
		std::stringstream date_stream;
		date_stream << year << "-" << month << "-" << day;


		string current_date = date_stream.str();

		AbsenceDates.push(current_date);

		numOfAbsences++;

	}


	void editAbsence(int idInput) { // bonus

		for (int i = 0; i < AbsenceDates.vecSize(); i++) {

			if (ID == idInput) {

				// go through each absence date 

				//ask user is they would like to change from absent to present 

					// if yes 

						// minus 1 for num of absences
						
						// remove from stack

					
					// if no
						
						// move to next date

			}

		}

	}

	void editAbsence(string nameInput) { // bonus

		for (int i = 0; i < AbsenceDates.vecSize(); i++) {

			if (name == nameInput) {

				// go through each absence date 

				//ask user is they would like to change from absent to present 

					// if yes 

						// minus 1 for num of absences

						// remove from stack


					// if no

						// move to next date

			}

		}

	}

	
	//							nvm using friend function for code simplicity

	// setter & getter      
	//int getRecordNum(void) {
	//	return recordNum;
	//}

	//void setID(int newID) {
	//	ID = newID;
	//}

	//int getID(void) {
	//	return ID;
	//}

	//void setName(string newName) {
	//	name = newName;
	//}

	//string getName(void) {
	//	return name;
	//}

	//void setEmail(string newEmail) {
	//	email = newEmail;
	//}

	//string getEmail(void) {
	//	return email;
	//}

	//void setCredits(int newCredits) {
	//	credits = newCredits;
	//}

	//int getCredits(void) {
	//	return credits;
	//}

	//void setProgram(string newProgram) {
	//	program = newProgram;
	//}

	//string getProgram(void) {
	//	return program;
	//}

	//void setLevel(string newLevel) {
	//	level = newLevel;
	//}

	//string getLevel(void) {
	//	return level;
	//}

	//void setNumAbsences(int newNum) {
	//	numOfAbsences = newNum;
	//}

	//int getNumAbsences(void) {
	//	return numOfAbsences;
	//}




private:

	int recordNum;
	int ID;
	string name;
	string email;
	int credits;
	string program;
	string level;
	int numOfAbsences;
	
	Stack AbsenceDates;
	
	//template <typename T>
	//friend class List;

	friend class Menu;

	template <typename T>
	friend class Node;



};
