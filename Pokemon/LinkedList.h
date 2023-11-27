#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include "LinkedListInterface.h"
using namespace std;
template<typename T>
class LinkedList : public LinkedListInterface<T> {
private:
	struct Node {
		T data;
		Node* next;
		Node(T data) : next(NULL) { this->data = data; }
		Node(T data, Node* n) { this->data = data; this->next = next; }

	};
	Node* head;
public:
	LinkedList() {
		this->head = NULL;
	}
	~LinkedList() {
		clear();
	}
	virtual bool insertHead(T value) {
		if (head == NULL) {
			head = new Node(value);
			return true;
		}
		Node* ptr = head;
		while (1) {
			if (ptr->data == value) return false;
			if (ptr->next == NULL) break;
			ptr = ptr->next;
		}
		Node* oldhead = head;
		head = new Node(value);
		head->next = oldhead;
		return true;

	}

	virtual bool insertTail(T value) {
		if (head == NULL) {
			head = new Node(value);
			return true;
		}
		Node* ptr = head;
		while (1) {
			if (ptr->data == value) return false;
			if (ptr->next == NULL) break;
			ptr = ptr->next;
		}
		ptr->next = new Node(value);
		return true;
	}

	virtual bool insertAfter(T matchNode, T node) {
		if (find(matchNode) == false) {
			return false;
		}
		if (find(node)) {
			return false;
		}
		Node* ptr = head;
		while (ptr->data != matchNode) {
			ptr = ptr->next;
		}
		Node* oldvalue = ptr->next;
		ptr->next = new Node(node);
		ptr->next->next = oldvalue;
		return true;
	}
	//Node(node)->next = new Node(matchNode);

	virtual bool remove(T value) {
		if (head == NULL) {
			return false;
		}
		if (head->data == value) {
			Node* temp = head;
			head = head->next;
			delete temp;
		}
		if (find(value) == true) {
			Node* ptr = head;
			while (ptr->next->data != value) {
				ptr = ptr->next;
			}
			Node* temp = ptr->next;
			ptr->next = ptr->next->next;
			delete temp;
			return true;
		}
		else {
			return false;
		}
	}

	virtual bool clear() {
		if (head == NULL) {
			return true;
		}
		else {
			while (head != NULL) {
				Node* temp = head;
				head = head->next;
				delete temp;

			}
			head = NULL;
			return true;
		}
	}
	virtual T at(int index) {
		int count = 0;
		Node* current = head;
		if (index < 0) {
			throw out_of_range("out of Bounds");
		}
		else if (head == NULL) {
			throw out_of_range("out of Bounds");
		}
		else {
			while (current != NULL) {
				if (count == index) {
					return current->data;
				}
				++count;
				current = current->next;
			}
			throw out_of_range("out of Bounds");
		}
	}
	virtual int size() {
		int count = 0;
		Node* current = head;
		while (current != NULL)
		{
			count++;
			current = current->next;
		}
		return count;
	}
	virtual string toString() const {
		Node * current;
		stringstream out;

		current = head;
		if (current == NULL) {
			out << " Empty";
		}
		else {
			out << " ";
			while (current != NULL)
			{
				out << current->data << " ";
				current = current->next;
			}
		}
		return out.str();
	}
	bool find(T value) const {
		Node* tmp = head;
		while (tmp != NULL) {
			if (tmp->data == value) {
				return true;
			}
			tmp = tmp->next;
		}
		return false;
	}

};

#endif