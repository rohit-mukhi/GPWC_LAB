#include <SFML/Graphics.hpp>
using namespace sf;

int main() {
    VideoMode vm(1920, 1080);
    RenderWindow window(vm, "Timber!!");
    Texture textureBackground;
    textureBackground.loadFromFile("graphics/background.png");
    Sprite spriteBackground;
    spriteBackground.setTexture(textureBackground);
    spriteBackground.setPosition(0, 0);

    Texture textureTree;
    textureTree.loadFromFile("graphics/tree.png");
    Sprite spriteTree;
    spriteTree.setTexture(textureTree);
    spriteTree.setPosition(810, 0);

    Texture textureBee;
    textureBee.loadFromFile("graphics/bee.png");
    Sprite spriteBee;
    spriteBee.setTexture(textureBee);
    spriteBee.setPosition(10, 800);


    while(window.isOpen()) {
        Event event;
        while(window.pollEvent(event)) {
            if(event.type == Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(spriteBackground);
        window.draw(spriteTree);
        window.draw(spriteBee);
        window.display();
    }
    return 0;
}