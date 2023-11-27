#ifndef MYARRAY_H
#define MYARRAY_H
enum myMode { SEQUENTIAL, PRIME, COMPOSITE, FIB };
#define MAX_ARRAY_SIZE	1000
#include <sstream>
#include <string>

using namespace std;
template<typename T>
class MyArray
{
private:
	T * array;
	int size;
	myMode mode;
	int index = 0;
public:
	MyArray(const int array_size)
	{
		array = (T*)malloc(sizeof(T) * array_size);
	};

	~MyArray()
	{
		free(array);
	};

	void push_back(T item)
	{

		if (size != MAX_ARRAY_SIZE)
		{
			array[size] = item;
			size++;
		}
	};

	class Iterator
	{
	private:
		int newIndex;
		int newSize;
		myMode arrayMode;
		T* pointer;

	public:
		Iterator(T* ptr, int index, int size)
		{
			pointer = ptr;
			arrayMode = SEQUENTIAL;
			newSize = size;

		};
		Iterator(T* ptr, int index, int size, myMode mode)
		{
			pointer = ptr;
			newIndex = index;
			arrayMode = mode;
			newSize = size;

			if (arrayMode == PRIME)
			{
				while (!IsPrime(pointer[newIndex]))
				{
					++newIndex;
					if (newIndex > newSize - 1)
						break;
				}
			}

			if (arrayMode == COMPOSITE)
			{
				while (IsPrime(pointer[newIndex]))
				{
					++newIndex;
					if (newIndex > newSize - 1)
						break;
				}
			}

			if (arrayMode == FIB)
			{

				while (!IsFIB())
				{
					++newIndex;
					if (newIndex > newSize - 1)
						break;
				}

			}

		};

		bool IsPrime(int number)
		{
			int i;
			if (number < 2)
			{
				return false;
			}
			for (i = 2; i < number; i++)
			{
				if (number % i == 0)
				{
					return false;
				}
			}
			return true;
		}

		bool IsFIB()
		{
			if (newIndex == 0 || newIndex == 1)
			{
				return false;
			}
			if ((pointer[newIndex - 2] + pointer[newIndex - 1]) == pointer[newIndex])
			{
				return true;
			}
			else
			{
				return false;
			}
		}


		bool operator!=(const Iterator& other) const
		{
			if (newIndex != other.newIndex)
			{
				return true;
			}
			else
			{
				return false;
			}
		};
		void operator++()
		{
			if (arrayMode == SEQUENTIAL)
			{
				++newIndex;
			}
			else if (arrayMode == PRIME)
			{
				do
				{
					++newIndex;
					if (newIndex > newSize - 1)
						break;
				} while (!IsPrime(pointer[newIndex]));

			}

			else if (arrayMode == COMPOSITE)
			{
				do
				{
					++newIndex;
					if (newIndex > newSize - 1)
						break;
				} while (IsPrime(pointer[newIndex]));
			}

			else if (arrayMode == FIB)
			{
				do
				{
					++newIndex;
					if (newIndex > newSize - 1)
						break;
				} while (!IsFIB());
			}

		};

		T& operator*() const
		{
			return pointer[newIndex];
		};

		T& operator[](int j)
		{
			
			return pointer[newIndex + j];

		};

		std::string toString() const
		{
			stringstream out;
			out << "size = " << newSize << " index= " << newIndex << " mode= " << arrayMode;
			return out.str();
		};

		friend std::ostream& operator<< (std::ostream& os, const Iterator& iter)
		{
			os << iter.toString();
			return os;
		};
	};

	Iterator begin()
	{
		index = 0;
		return Iterator(array, 0, size);
	};

	Iterator begin(myMode mode)
	{
		mode = mode;
		return Iterator(array, 0, size, mode);
	};

	Iterator end()
	{
		
		return Iterator(&array[size], size, size, SEQUENTIAL);
	};

	std::string toString() const
	{
		stringstream out;
		for (int i = 0; i < size; i++)
		{
			out << array[i] << ' ';
		}
		return out.str();
	};
	friend std::ostream& operator<< (std::ostream& os, const MyArray<T>& myArray)
	{
		os << myArray.toString();
		return os;
	};
};
#endif