#ifndef M_GAMEOFLIFE_GRAPHICS_H
#define M_GAMEOFLIFE_GRAPHICS_H

#include <string>

#include <SFML/Graphics.hpp>
// #include <SFML/Keyboard.hpp>

namespace GameOfLife {

class Window {
    public:
        Window();
        void run();

    private:
        sf::ContextSettings d_settings;
        sf::Font            d_font;
        sf::RenderWindow    d_window;

        void treatEvent(const sf::Event& event);
        void updateDisplay();
        void handleWindowClosing();
};

} // closing project namespace

#endif

