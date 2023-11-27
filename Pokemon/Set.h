#ifndef SET_H
#define SET_H
#include"SetInterface.h"
#include "MapInterface.h"
#include "LinkedListInterface.h"
#include "LinkedList.h"



template<typename T>
class Set
{
private:
	LinkedList<T> list;
public:
	Set() {}
	virtual ~Set() {}
	
	virtual bool insert(const T& item) {
		return list.insertHead(item);
	}
	
	virtual size_t erase(const T& item) {
		return list.remove(item);
	}

	virtual void clear() {
		list.clear();
	}

	virtual size_t size() {
		return list.size();
	}

	virtual size_t count(const T& item) {
		if (list.find(item)) {
			return 1;
		}
		else {
			return 0;
		}
	}

	virtual std::string toString() const {
		return list.toString();
	}

	friend std::ostream& operator<< (ostream& os, const Set<T>& set)
	{
		os << set.toString();
		return os;
	}
};
#endif

