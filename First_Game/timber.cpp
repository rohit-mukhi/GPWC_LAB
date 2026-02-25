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

    Texture textureCloud;
    textureCloud.loadFromFile("graphics/cloud.png");
    Sprite spriteCloud;
    spriteCloud.setTexture(textureCloud);
    spriteCloud.setPosition(0, 400);
    float cloudSpeed = 15;
    float cloudSpeedPerSec = 1920/cloudSpeed;
    Time dt;
    Clock ct;

    while(window.isOpen()) {
        Event event;
        while(window.pollEvent(event)) {
            if(event.type == Event::Closed)
                window.close();
        }

        dt = ct.restart();


        if(spriteCloud.getPosition().x > 1920) {
            spriteCloud.setPosition(0, 400);
        } else {
            spriteCloud .setPosition(spriteCloud.getPosition().x+dt.asSeconds() * cloudSpeedPerSec, 500);
        }

        window.clear();
        window.draw(spriteBackground);
        window.draw(spriteTree);
        window.draw(spriteBee);
        window.draw(spriteCloud);
        window.display();
    }
    return 0;
}
