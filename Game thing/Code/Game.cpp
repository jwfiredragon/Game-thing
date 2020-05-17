#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Game.h"

Game::Game() : mWindow(sf::VideoMode(1027,768), "Game thing"), mPlayer()
{
	mPlayer.setRadius(20.f);
	mPlayer.setPosition(100.f, 100.f);
	mPlayer.setFillColor(sf::Color::Cyan);
}

void Game::run()
{
	while (mWindow.isOpen())
	{
		processEvents();
		update();
		render();
	}
}

void Game::processEvents()
{
	sf::Event event;
	while (mWindow.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::MouseButtonPressed:
			handleInputMouse(event.mouseButton.button, true);
			break;
		case sf::Event::MouseButtonReleased:
			handleInputMouse(event.mouseButton.button, true);
			break;
		case sf::Event::Closed:
			mWindow.close();
			break;

		}
	}
}

void Game::update()
{

}

void Game::render()
{
	mWindow.clear();
	mWindow.draw(mPlayer);
	mWindow.display();
}

void Game::handleInputMouse(sf::Mouse::Button button, bool bIsPressed)
{
	if (button == sf::Mouse::Left)
	{
		mPlayer.setPosition(sf::Mouse::getPosition(mWindow).x, sf::Mouse::getPosition(mWindow).y);
	}
}