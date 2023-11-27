#ifndef MAP_H
#define MAP_H
#include"SetInterface.h"
#include "MapInterface.h"
#include <sstream>
#include <ostream>
using namespace std;

template<typename K, typename V>
class Map : public MapInterface<K, V>
{
private:
	struct Node {
		K key;
		V value;
		Node* next;

		Node(const K& q, const V& r) {
			key = q;
			value = r;
			next = NULL;
		}
	};
	Node** myArray;
	static const int HashTableSize = 31;
	size_t arraySize = 31;
public:
	Map() {
		myArray = new Node*[HashTableSize];
		for (size_t i = 0; i < HashTableSize;++i) {
			myArray[i] = NULL;
		}
	}

	~Map() {
		clear();
		delete myArray;
	}

	// Runs a hash on the key
	int hash(K key) {
		int total = 0;
		int prime = 31;
		for (size_t i = 0; i < key.length(); ++i) {
			total = total + key.at(i) * prime ^ (key.length() - 1);
		}
		total = total % HashTableSize;
		return total;
	}

	// The "[]" operator goes throught the array
	V& operator[](const K& key) {
		if (myArray[hash(key)] == NULL) {
			myArray[hash(key)] = new Node(key, V());
			return myArray[hash(key)]->value;
		}
		if (myArray[hash(key)]->key == key) {
			return myArray[hash(key)]->value;
		}
		if (myArray[hash(key)]->key != key) {
			int i = 0;
			while (myArray[i] != NULL) {
				if (myArray[i]->key == key) {
					return myArray[i]->value;
				}

				++i;
			}
			if (myArray[i] == NULL) {
				myArray[i] = new Node(key, V());
				return  myArray[i]->value;
			}
		}
	}

	// Clears Memory leaks
	virtual void clear() {
		for (size_t i = 0; i < HashTableSize; ++i) {
			if (myArray[i] != NULL) {
				while (myArray[i] != NULL) {
					Node* temp;
					temp = myArray[i];
					myArray[i] = myArray[i]->next;
					delete temp;
				}
			}
		}
		return;
	}

	// Outputs the String
	std::string toString() const { 
		std::stringstream out;
		for (size_t i = 0; i < HashTableSize; ++i) {
			if (myArray[i] != NULL) {
				out << myArray[i]->key << ": " << myArray[i]->value << endl;
			}
		}
		return out.str();
	}
	friend ostream& operator<< (ostream& os, const Map<K, V>& map)
	{
		os << map.toString();
		return os;
	}
};

#endif 

