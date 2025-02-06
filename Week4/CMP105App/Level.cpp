#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	texture.loadFromFile("gfx/Mushroom.png");
	if (!font.loadFromFile("font/arial.ttf")) std::cout << "Error loading font from file";

	testSprite.setTexture(&texture);
	testSprite.setSize(sf::Vector2f(100, 100));
	testSprite.setPosition(100, 100);
	player.setInput(input);

	message.setFont(font);
	message.setCharacterSize(150);
	message.setFillColor(sf::Color::White);
	message.setOutlineColor(sf::Color::Black);
	message.setOutlineThickness(10.f);
	message.setPosition(-400,0);
	message.setString("Cool\nDuck");

	if (!linesTex.loadFromFile("gfx/Lines.png"))
	
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	// Close window on Escape pressed.
	if (input->isKeyDown(sf::Keyboard::Escape))
	{
		window->close();
	}
	player.handleInput(dt);
}

// Update game objects
void Level::update(float dt)
{
	player.update(dt);
	duck.update(dt);
	if (message.getPosition().x < 30) message.setPosition(message.getPosition().x + duck.getBrightRamp()*10, message.getPosition().y);
}

// Render level
void Level::render()
{
	beginDraw();
	window->clear(sf::Color(255,0,0));

	//window->draw(player);
	window->draw(duck);
	window->draw(message);
	window->draw(lines);
	endDraw();
}
