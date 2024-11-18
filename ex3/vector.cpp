#include "vector.h"


Vector::Vector(int n)
{
	// checks if the size of the vector is valid (bigger/equal to 2)
	if (n < SMALLEST_VECTOR_SIZE)
	{
		n = SMALLEST_VECTOR_SIZE;
	}

	// sets up the attributes
	this->_capacity = n;
	this->_resizeFactor = n;
	this->_size = 0;
	this->_elements = new int(n);
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