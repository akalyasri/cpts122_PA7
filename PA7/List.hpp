#include "Node.hpp"


template <typename T>
class List {

public:

	List() {
		pHead = nullptr;
	}

	bool insertNode(void) { // for import records feature

		Node<T>* newNode;

		newNode = new Node;

		if (newNode == nullptr) {
			return false;
		}

		if (pHead == nullptr) {
			pHead = newNode;

			return true;

		} else {

			Node<T>* temp = pHead;
			pHead = newNode;
			newNode->setpNext(temp);

			return true;
		}



	}

	bool search(int idInput, Node<T> * matchingNode) {


	}





private:

	Node <T> * pHead;
	

};
