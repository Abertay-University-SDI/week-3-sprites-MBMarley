#pragma once
#include "Framework/GameObject.h"
#include <iostream>

class Player : public GameObject
{
public:
	Player();
	~Player();
	void handleInput(float dt);
	void update(float dt);

private:
	float accel;
	float decel;
	float maxSpeed;
	sf::Texture tex;
};