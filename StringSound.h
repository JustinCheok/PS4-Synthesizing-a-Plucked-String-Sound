#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include "CircularBuffer.h"


class StringSound {
 public:
	explicit StringSound(double frequence);
 	explicit StringSound(std::vector<sf::Int16> init);
 	//StringSound(const StringSound &obj) {}; //no copy const
 	~StringSound();
 	void pluck();
 	void tic();
 	sf::Int16 sample();
 	int time();
 private:
 	CircularBuffer* _cb;
 	int _time;
};

