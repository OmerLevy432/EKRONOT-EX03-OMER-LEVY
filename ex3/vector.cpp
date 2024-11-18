#include "vector.h"
#include <iostream>

using std::cout;


Vector::Vector(int n)
{
	// checks if the size of the vector is valid (bigger/equal to 2)
	if (n < SMALLEST_VECTOR_SIZE)
	{
		n = SMALLEST_VECTOR_SIZE;
	}

	this->_capacity = n;
	this->_resizeFactor = n;
	this->_size = 0;
	this->_elements = new int(n);
}

Vector::~Vector()
{
	this->_capacity = 0;
	this->_resizeFactor = 0;
	this->_size = 0;
	delete this->_elements;
	this->_elements = nullptr;
}

int Vector::size() const
{
	return this->_size;
}

int Vector::capacity() const
{
	return this->_capacity;
}

int Vector::resizeFactor() const
{
	return this->_resizeFactor;
}

bool Vector::empty() const
{
	return this->_size == 0;
}

int Vector::pop_back()
{
	// checks if the vector is empty
	if (this->empty())
	{
		cout << "error:: pop from empty vector\n";
		return EMPTY_VECTOR_RETURN;
	}

	// gets the last item and removes it from the vector
	int item = this->_elements[this->_size];
	this->_elements[this->_size--] = 0;

	return item;
}

void Vector::reserve(int n)
{
	// checks if n is bigger than the current capacity
	if (n > this->_capacity)
	{
		int* newArray = new int[n];
		int i = 0;

		// copies the old array into the new one
		for (i = 0; i < this->_capacity; i++)
		{
			newArray[i] = this->_elements[i];
		}
		this->_capacity = n;
	}
}

void Vector::push_back(const int& val)
{
	// if the vector is full
	if (this->_size == this->_capacity)
	{
		this->reserve(this->_capacity + this->_resizeFactor);
	}
	this->_elements[this->_size++] = val;
}