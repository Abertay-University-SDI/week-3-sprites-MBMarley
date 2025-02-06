#include "Player.h"

Player::Player()
{
	setOrigin(64,64);
	setSize({ 128,128 });
	setPosition(300,300);
	if (!tex.loadFromFile("gfx/MushroomTrans.png")) std::cout << "Error loading player sprite";
	setTexture(&tex);
	accel = 2;
	decel = 1;
	maxSpeed = 10;
}

Player::~Player()
{
}

void Player::handleInput(float dt)
{
	int hVal = input->isKeyDown(sf::Keyboard::D)-input->isKeyDown(sf::Keyboard::A);
	int vVal = input->isKeyDown(sf::Keyboard::S)-input->isKeyDown(sf::Keyboard::W);
	if (hVal != 0)
	{
		if (getVelocity().x < maxSpeed && getVelocity().x > maxSpeed * -1)setVelocity(getVelocity().x + accel * hVal * dt * 100, getVelocity().y);
		else setVelocity(maxSpeed*hVal,getVelocity().y);
	}
	else
	{
		if (getVelocity().x > 0) setVelocity(getVelocity().x - decel * dt * 100, getVelocity().y);
		else if (getVelocity().x < 0) setVelocity(getVelocity().x + decel * dt * 100, getVelocity().y);
		if (getVelocity().x < decel && getVelocity().x > decel * -1) setVelocity(0,getVelocity().y);
	}

	if (vVal != 0)
	{
		if (getVelocity().y < maxSpeed && getVelocity().y > maxSpeed * -1) setVelocity(getVelocity().x, getVelocity().y + accel * vVal * dt * 100);
		else setVelocity(getVelocity().x, maxSpeed * vVal);
	}
	else
	{
		if (getVelocity().y > 0) setVelocity(getVelocity().x, getVelocity().y - decel * dt * 100);
		else if (getVelocity().y < 0) setVelocity(getVelocity().x, getVelocity().y + decel * dt * 100);
		if (getVelocity().y < decel && getVelocity().y > decel * -1) setVelocity(getVelocity().x, 0);
	}
}

void Player::update(float dt)
{
	move(getVelocity()*dt*100.f);
}
