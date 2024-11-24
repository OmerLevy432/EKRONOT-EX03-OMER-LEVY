#pragma once
#include <string>


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
	// constructors
	Vector(int n);
	Vector(const Vector& other);
	
	// destructor
	~Vector();

	// operators
	Vector operator=(const Vector& other);
	int operator[](const int index) const;

	// getters
	int size() const;
	int capacity() const;
	int resizeFactor() const;
	int* copyElements() const;
	bool empty() const;

	// methods
	void push_back(const int& val);
	int pop_back();
	void reserve(const int n);
	void resize(const int n);
	void resize(const int n, const int& val);
};
