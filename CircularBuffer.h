#ifndef CIRCULARBUFFER_H
#define CIRCULARBUFFER_H
#include <stdint.h>
#include <queue>
#include <memory>
#include <string>
#include <iostream>
#include <algorithm>

class CircularBuffer{

private:
	//CircularBuffer(int capacity);
	//int capacity;
	//std::queue <int16_t> buffer;
	int16_t first;
	int16_t *data;
	int _size;
	int _capacity;
	
	
public:
	explicit CircularBuffer(int capacity);
	int size();
	bool isEmpty();
	bool isFull();
	void enqueue(int16_t x);
	int16_t dequeue();
	int16_t peek();
	
};
#endif

