#include "Stack.hpp"


class Data {

public:

	Data(int idInput, string& nameInput, string& emailInput, int creditInput, string& programInput, string& levelInput, int absenceNum, string& dateOfAbsence) {

		ID = idInput;
		name = nameInput;
		email = emailInput;
		credits = creditInput;
		program = programInput;
		level = levelInput;
		numOfAbsences = absenceNum;
		
		AbsenceDates.push(dateOfAbsence);

	}

	~Data() {


	}


	void markAbsence(void) { // use only when the user say yes to "is student absent today?"

		//got code from online
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


	}

	void editAbsence(string nameInput) { // bonus



	}
	



private:

	int ID;
	string name;
	string email;
	int credits;
	string program;
	string level;
	int numOfAbsences;
	
	Stack AbsenceDates;

	

};
