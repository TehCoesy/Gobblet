#ifndef SOUND_H
#define SOUND_H

#include "SFML/Audio.hpp"

class Sound {
public:
	Sound();

private:
	sf::Music musik;

	sf::Sound bloop;
	sf::SoundBuffer bloopBF;

};

#endif // !SOUND_H
