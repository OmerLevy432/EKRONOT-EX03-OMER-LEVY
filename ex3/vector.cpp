#include "vector.h"
#include <iostream>

using std::cout;


Vector::Vector(int n)
{
	// checks if the size of the vector is valid (bigger/equal to SMALLEST_VECTOR_SIZE)
	if (n < SMALLEST_VECTOR_SIZE)
	{
		n = SMALLEST_VECTOR_SIZE;
	}

	this->_capacity = n;
	this->_resizeFactor = n;
	this->_size = 0;
	this->_elements = new int[n];
}

Vector::Vector(const Vector& other)
{
	this->_capacity = other.capacity();
	this->_resizeFactor = other.capacity();
	this->_size = other.size();
	this->_elements = other.copyElements();
}

Vector Vector::operator=(const Vector& other)
{
	this->_capacity = other.capacity();
	this->_resizeFactor = other.capacity();
	this->_size = 0;
	this->_elements = other.copyElements();

	return *this;
}

Vector::~Vector()
{
	this->_capacity = 0;
	this->_resizeFactor = 0;
	this->_size = 0;
	delete[] this->_elements;
	this->_elements = nullptr;
}

int Vector::operator[](const int index) const
{
	// if the index is out of bound
	if (index < 0 || index >= this->_capacity)
	{
		std::cerr << "Index out of bound. index: " << index << ", vector's length: " << this->_capacity << "\n";
	}
	return this->_elements[index];
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

int* Vector::copyElements() const
{
	int* elementsCopy = new int[this->_capacity];
	int i = 0;

	// copies the elements
	for (i = 0; i < this->_capacity; i++)
	{
		elementsCopy[i] = this->_elements[i];
	}
	return elementsCopy;
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
	int item = this->_elements[--this->_size];
	this->_elements[this->_size] = 0;

	return item;
}

void Vector::reserve(int n)
{
	// checks if n is bigger than the current capacity
	if (n > this->_capacity)
	{
		int arraySize = ((n - this->_capacity) / this->_resizeFactor) * this->_resizeFactor + (((n % this->_resizeFactor) != 0) * this->_resizeFactor);
		int* newArray = new int[arraySize];
		int i = 0;

		// copies the old array into the new one
		for (i = 0; i < this->_capacity; i++)
		{
			newArray[i] = this->_elements[i];
		}

		// sets the new array
		this->_capacity = arraySize;
		delete this->_elements;
		this->_elements = newArray;
		newArray = nullptr;
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

void Vector::resize(int n)
{
	// checks if the size of the vector is reduced
	if (n < this->_capacity)
	{
		// creates a new array for the elements
		int* newArray = new int[n];
		int i = 0;

		// moves the elements to the new array
		for (i = 0; i < n; i++)
		{
			newArray[i] = this->_elements[i];
		}

		// sets the new array
		delete this->_elements;
		this->_elements = newArray;
		newArray = nullptr;
		this->_size = n;
	}
	else
	{
		this->reserve(n);
	}
}

void Vector::resize(int n, const int& val)
{
	int oldCapacity = this->_capacity;
	this->resize(n);

	// checks if the size of the vector got bigger
	if (n > oldCapacity)
	{
		int i = 0;
		
		// fills the new valeus with given variable val
		for (i = oldCapacity; i < this->_capacity; i++)
		{
			this->_elements[i] = val;
		}
	}
}