#pragma once


#define SMALLEST_VECTOR_SIZE 2
#define EMPTY_VECTOR_RETURN -9999


class Vector
{

private:
	int* _elements;
	int _size;
	int _capacity;
	int _resizeFactor;

public:
	// constructor
	Vector(int n);
	
	// destructor
	~Vector();

	// getters
	int size() const;
	int capacity() const;
	int resizeFactor() const;
	bool empty() const;

	// methods
	void push_back(const int& val);
	int pop_back();
	void reserve(int n);
};
