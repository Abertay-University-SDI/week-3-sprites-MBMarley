#include "Duck.h"

Duck::Duck()
{
	if (!tex.loadFromFile("gfx/coolDuck.png")) std::cout << "Failed to load duck Texture";
	setTexture(&tex);
	setSize({ 1159,1172 });
	setOrigin(580,586);
	setPosition(1080,486);
	brightness = 0;
	setRotation(45);
}

void Duck::setDrawCol(sf::Color _col)
{
	setFillColor(_col);
}

void Duck::update(float dt)
{
	if (brightness < 255)
	{
		brightness += brightRamp;
		brightRamp += ((brightRamp * brightRamp)/2 + 0.1)*dt*5;
	}
	else brightness = 255;
	if (getRotation() < 90 || getRotation() > 325) rotate(-brightRamp);
	else move(-3 * dt, 0);
	//std::cout << getRotation() << ", ";
	setDrawCol(sf::Color(brightness,brightness,brightness));
}

float Duck::getBrightRamp()
{
	return brightRamp;
}
