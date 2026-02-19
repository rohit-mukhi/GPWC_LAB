#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

int main() {
    auto windows = sf::RenderWindow(sf::VideoMode(600, 600), "My First Game");
    sf::CircleShape Shape(50.f);
    Shape.setFillColor(sf::Color::Red);
    Shape.setPosition(375.f, 275.f);

    while(windows.isOpen()) {
        Event event;
        while(windows.pollEvent(event)) {
            if(event.type == sf::Event::Closed) {
                windows.close();
            }
        }

        windows.clear(sf::Color::Red);
        windows.draw(Shape);
        windows.display();
    }

    return 0;
}