//**** YOU MAY NOT MODIFY THIS DOCUMENT ****/
#ifndef SET_INTERFACE_H
#define SET_INTERFACE_H
#include <string>

/*
template<typename T1, typename T2>
struct pair
{
T1 first;
T2 second;
pair(const T1& f, const T2& s) : first(f), second(s) {}
};
*/

template<typename T>
class SetInterface
{
public:
	SetInterface() {}
	virtual ~SetInterface() {}

	/** Inserts item into the set, if the container doesn't
	already contain an element with an equivalent value.
	@return: pair.first = pointer to item
	pair.second = true if successfully inserted, else false. */
	//virtual pair<T*, bool> insert(const &T item) = 0;
	virtual bool insert(const T& item) = 0;

	/** @return: the number of elements removed from the Set. */
	virtual size_t erase(const T& item) = 0;

	/** Removes all items from the set. */
	virtual void clear() = 0;

	/** @return: the number of elements contained by the Set. */
	virtual size_t size() const = 0;

	/** @return: return 1 if contains element equivalent to item, else 0. */
	virtual size_t count(const T& item) const = 0;

	/** @return: string representation of items in Set. */
	virtual std::string toString() const = 0;
};
#endif // SET_INTERFACE_H