#pragma once


#define SMALLEST_VECTOR_SIZE 2


class Vector
{

private:
	int* _elements;
	int _size;
	int _capacity;
	int _resizeFactor;

public:
	Vector(int n);
	~Vector();
	int size() const;
	int capacity() const;
	int resizeFactor() const;
	bool empty() const;

};
