#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include<iostream>

using namespace std;

template<typename T>
class DynamicArray
{
private:
	int capacity{};
	int current{};
	T **array;

public:
    ///Description
    ///Explicit constructor for object DynamicArray
	explicit DynamicArray(int size = 5);

    ///Description
    ///Destructor for object DynamicArray
	~DynamicArray();

	///Description
	void initialize(int from);

	///Description
    /// In this case: -> a new array with double capacity will be created (cap_new_arr = cap_ald_arr * 2)
    ///               -> all the data from the old array will be moved to the new array
    ///               -> the data from the old array will be deleted
    ///               -> the old array will be now the new array (same data, but double the cap)
    void resize();

    ///Description
    ///Adds a nuw element of type T to the array elements
    ///   -> If the capacity od the array is equal to the actual length of the array, it means that there is no empty
    ///      memory left for the new elem => resize the elem
    ///   -> If the actual length of the array elements is lesser than the capacity of the array, it means that there
    ///      is still empty memory for a new elem of type T
    ///   A new elem is added => length inc by 1
	void push(const T &element);

    ///Description
    ///Returns the actual length of the array elements( the size)
	const int& size()const { return this->current; }

    ///Description
    ///Removes an element from the array
    /// It moves the last element from the array ( elements[length - 1] ) to the position of the elem we want to delete
    /// The length is dec by 1
    /// Since (in this case) the order the elements were added to the array is not important, we don't need to shift
    /// everything, it's enough to move the last elem and dec the current length
    void erase(int index);

	T& operator[] (int index);
};

template<typename T>
DynamicArray<T>::DynamicArray(int size)
{
    this->capacity = size;
    this->current = 0;
    this->array = new T*[this->capacity];

    initialize(this->current);
}

template<typename T>
DynamicArray<T>::~DynamicArray()
{
    for (size_t i = 0; i < current; i++)
    {
        delete this->array[i];
    }
    delete[]this->array;
}

template<typename T>
T& DynamicArray<T>::operator[](const int index)
{
    if (index < 0 || index >= this->current)
        throw("wrong index");

    return *this->array[index];
}

template<typename T>
void DynamicArray<T>::initialize(int from)
{
    for (size_t i = from; i < capacity; i++)
    {
        this->array[i] = nullptr;
    }
}

template<typename T>
void DynamicArray<T>::resize()
{
    this->capacity *= 2;

    T **tempArray = new T*[this->capacity];

    for (size_t i = 0; i < this->current; i++)
    {
        tempArray[i] = this->array[i];
    }

    delete[]this->array;

    this->array = tempArray;

    initialize(this->current);
}

template<typename T>
void DynamicArray<T>::push(const T& element)
{
    if (this->current >= this->capacity)
    {
        this->resize();
    }

    this->array[this->current++] = new T(element);
}

template<typename T>
void DynamicArray<T>::erase(int index) {
    this->array[index] = this->array[this->current - 1];
    current --;
}

#endif //DYNAMICARRAY_H
