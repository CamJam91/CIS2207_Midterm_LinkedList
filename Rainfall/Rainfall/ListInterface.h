/*Cameron Murphy | CIS 2207N02 | 3/9/2025
* Interface for the ADT list
*/
#pragma once
/** Interface for the ADT list*/
template<class T>
class ListInterface {
public:
		//getters
	virtual bool isEmpty() const = 0;
	virtual int getLength() const = 0;
	virtual T getEntry(int position) = 0;
	virtual void setEntry(int position, const T& newEntry) = 0;

		//setters
	virtual bool insert(int newPosition, const T& newEntry) = 0;
	virtual bool remove(int position) = 0;
	virtual void clear() = 0;
};
