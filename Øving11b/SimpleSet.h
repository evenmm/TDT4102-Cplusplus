#pragma once
#include <iostream>
#include <string>
using namespace std;
template<class T>
class SimpleSet{
    public:
        /** Construct empty set **/
        SimpleSet();
        /** Destructor */
		~SimpleSet();
		/** Insert i into set, return true if the element was inserted, else false **/
        bool insert(T i);
        /** Returns true if i is in the set **/
        bool exists(T i);
        /** Removes i from the set, return true if an element was removed **/
        bool remove(T i);
		friend ostream& operator<<(ostream& os, const SimpleSet& rhs) {
			for (int i = 0; i < rhs.currentSize; i++) {
				os << rhs.data[i] << endl;
			}
			return os;
		}
    private:
        /** Dynamic array containing set elements **/
        T* data;
        /** Current number of elements **/
        int currentSize;
        /** Max capasity of data **/
        int maxSize;       
        
        /** Returns the index where i may be found, else an invalid index. **/
        int find(T i);
        /** Resizes data, superflous elements are dropped. **/
        void resize(int n); 
};

template<class T>
SimpleSet<T>::SimpleSet() : currentSize(0), maxSize(200) {
	data = new T[maxSize];
}
template<class T>
SimpleSet<T>::~SimpleSet() { delete[] data; data = nullptr; }

template<class T>
bool SimpleSet<T>::exists(T i) {
	for (int j = 0; j < currentSize; j++) {
		if (data[j] == i) { return true; }
	}
	return false;
}
template<class T>
bool SimpleSet<T>::insert(T i) {
	for (int j = 0; j < currentSize; j++) {
		if (data[j] == i) { return false; }
	}
	if (currentSize < maxSize) {
		data[currentSize++] = i;
		return true;
	}
	return false;
}
template<class T>
bool SimpleSet<T>::remove(T i) {
	for (int j = 0; j < currentSize; j++) {
		if (data[j] == i) {
			data[j] = data[currentSize - 1];
			data[currentSize--] = 0;
			return true;
		}
	}
	return false;
}
template<class T>
int SimpleSet<T>::find(T i) {
	for (int j = 0; j < currentSize; j++) {
		if (data[j] == i) { return j; }
	}
	return maxSize+1;
}
/** Resizes data, superflous elements are dropped. **/
template<class T>
void SimpleSet<T>::resize(int n) {
	T* newData = new T[n];
	for (int i = 0; i < n; i++) {
		newData[i] = data[i];
	}
	delete[] data;
	data = newData;
	maxSize = n;
}
