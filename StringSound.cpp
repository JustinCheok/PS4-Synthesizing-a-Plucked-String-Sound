#include "StringSound.h"
#include "CircularBuffer.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include <stdexcept>
#include <exception>
#include <math.h>

// constructor
StringSound::StringSound(double frequency) {
_time = 0;
if(frequency <= 0) {
throw std::invalid_argument("StringSound constructor - Capacity needs to be greater than 0");
} else {
int size = ceil(44100 / frequency);  // 44,100 frequence sample rate
_cb = new CircularBuffer(size);
while(!_cb->isFull()) {
_cb->enqueue(0);
}
}
}


StringSound::StringSound(std::vector<sf::Int16> init) {
int i = 0;
_time = 0;
if(init.size() <= 0) {
throw std::invalid_argument("StringSound: Capacity must be greater than 0");
} else {
_cb = new CircularBuffer(init.size());
while(!_cb->isFull()) {
_cb->enqueue(init[i]);
i++;
}
}
}


StringSound::~StringSound() {
}


void StringSound::pluck() {
if(_cb->isFull()) {
for(int i = 0; i < _cb->size(); i++) {
_cb->dequeue();
}
}
while(!_cb->isFull()) {
_cb->enqueue((sf::Int16)(rand() * 0xffff));
}
}


void StringSound::tic() {
sf::Int16 t = 0.5 * 0.99 * (_cb->dequeue() + _cb->peek());
_cb->enqueue(t);
_time++;
}


sf::Int16 StringSound::sample() {
return _cb->peek();
}


int StringSound::time() {
return _time;
}

		
