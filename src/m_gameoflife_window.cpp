#include "m_gameoflife_window.h"

#include <iostream>

using namespace GameOfLife;

namespace {
    const std::string TITLE = "Game Of Life";
    const int WIDTH = 1600, HEIGHT = 1000;
}

Window::Window()
: d_settings()
, d_window(sf::VideoMode(WIDTH, HEIGHT),
		   TITLE,
           sf::Style::Resize | sf::Style::Close,
           d_settings)
{
    d_settings.antialiasingLevel = 8;

    d_window.setVerticalSyncEnabled(true);

    if (!d_font.loadFromFile("font/arial.ttf")) {
        std::cout << "Error loading font\n";
    }
}

void Window::run()
{
	while (d_window.isOpen()) {
		sf::Event event;
		while (d_window.pollEvent(event)) {
			treatEvent(event);
        }

        updateDisplay();
    }
}

void Window::treatEvent(const sf::Event& event)
{
	if (event.type == sf::Event::Closed) {
		handleWindowClosing();
	}

	if (event.type == sf::Event::KeyPressed) {

		if (event.key.code == sf::Keyboard::Key::H) {
			std::cout << "the Left key was pressed\n";

		} else if (event.key.code == sf::Keyboard::Key::L) {
			std::cout << "the right key was pressed\n";

		}

		if (event.key.code == sf::Keyboard::Key::J) {
			std::cout << "the down key was pressed\n";

		} else if (event.key.code == sf::Keyboard::Key::K) {
			std::cout << "the up key was pressed\n";
		}
	}

	if (event.key.code == sf::Keyboard::Space) {
		std::cout << "the space key was pressed\n";

	}

	if (event.type == sf::Event::KeyReleased) {
		if (event.key.code == sf::Keyboard::RControl ||
			event.key.code == sf::Keyboard::LControl) {
			std::cout << "the control key was released\n";

		}
	}

	if (event.key.code == sf::Keyboard::RShift ||
		event.key.code == sf::Keyboard::LShift) {
		std::cout << "the shift key was released\n";

	}

	if (event.key.code == sf::Keyboard::Key::P) {
		std::cout << "the P key was released\n";

	}

	if (event.key.code == sf::Keyboard::Key::Z) {
		std::cout << "the Z key was released\n";

	}

	if (event.key.code == sf::Keyboard::Key::I) {
		std::cout << "the I key was released\n";

	}

	if (event.key.code == sf::Keyboard::Key::S) {
		std::cout << "the S key was released\n";

	}
}

void Window::updateDisplay()
{
	d_window.clear(sf::Color::Black);

	sf::Text speedTxt;
	speedTxt.setFont(d_font);
	std::string text("\nInitialise (i)");
	speedTxt.setString(text);

	speedTxt.setCharacterSize(24); // in pixels, not points!
	speedTxt.setFillColor(sf::Color(128, 249, 165));
	d_window.draw(speedTxt);

	d_window.display();
}

void Window::handleWindowClosing()
{
	d_window.close();
}

