#include "Node.hpp"


template <typename T>
class List {

public:

	List() {
		pHead = nullptr;
	}
	 

	// for import records feature
	bool insertNode(int recordNumInput, int idInput, string& firstNameInput,string& lastNameInput, string& emailInput, string& creditInput, string& programInput, string& levelInput, int absenceNum, string& dateOfAbsence) { // for import records feature

		Node<T>* newNode;

		newNode = new Node<T>(recordNumInput,idInput,firstNameInput,lastNameInput,emailInput,creditInput,programInput,levelInput, absenceNum, dateOfAbsence);

		if (newNode == nullptr) {
			return false;
		}

		if (pHead == nullptr) {
			pHead = newNode;

			return true;

		}
		else {

			Node<T>* temp = pHead;
			pHead = newNode;
			newNode->setpNext(temp);

			return true;
		}



	}

	//search with name
	bool search(int idInput, Node<T> * matchingNode) { 

		Node<T>* pCur = pHead;

		while (pCur != nullptr) {

			if (pCur->singleData.lastName == matchingNode->singleData.lastName) {
				
				return true;
			}

			pCur = pCur->getpNext();

		}

		return false;
	}





private:

	Node<T> * pHead;

	friend class Menu;
	
};
