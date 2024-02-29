#include "CircularBuffer.h"
#include <iostream>
#include <queue>
#include <memory>
#include <string>
#include <stdint.h>
#include <stdexcept>
#include <exception>
	
CircularBuffer::CircularBuffer(int capacity) {
// std::cout << "Capacity: " << capacity << std::endl;
if(capacity < 1) {
throw std::invalid_argument("CircularBuffer constructor: capacity must be greater than zero.");
}
_size = 0;
first = 0;
_capacity = capacity;
data = new int16_t[_capacity];
}

int CircularBuffer::size() {
// std::cout << "size: " << buffer.size() << std::endl;
return _size;
}

bool CircularBuffer::isEmpty() {
// std::cout << "isEmpty: " << buffer.empty() << std::endl;
return _size == 0;
}

bool CircularBuffer::isFull() {
return _size == _capacity;
}

void CircularBuffer::enqueue(int16_t x) {
if(isFull()) {
throw std::runtime_error("enqueue: can't enqueue to a full ring");
}	
data[(first + _size) % _capacity] = x;
_size++;
}

int16_t CircularBuffer::dequeue() {
int temp;
if(isEmpty()) {
throw std::runtime_error("dequeue: can't dequeue to a empty ring");
}
_size--;
temp = first;
first = (first + 1) % _capacity;
return data[temp];
}

int16_t CircularBuffer::peek() {
if(isEmpty()) {
throw std::runtime_error("peek: can't be empty");
}
return data[first];
}






