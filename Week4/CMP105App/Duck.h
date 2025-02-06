#pragma once
#include "Framework/GameObject.h"

class Duck : public GameObject
{
public:
	Duck();
	void setDrawCol(sf::Color _col);

	void update(float dt);
	float getBrightRamp();
private:
	sf::Texture tex;
	sf::Color drawCol;
	float brightness;
	float brightRamp;
};