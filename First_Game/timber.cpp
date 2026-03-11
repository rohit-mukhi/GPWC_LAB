#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include <unistd.h>

using namespace sf;

int main()
{
    VideoMode vm(1920, 1080);
    RenderWindow window(vm, "Timber!!!");

    View view (FloatRect(0,0,1920,1080));
    window.setView(view);

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
    spriteBee.setPosition(0, 800);
    bool beeActive = false;
    float beeSpeed = 0.0f;

    Texture textureCloud;
    textureCloud.loadFromFile("graphics/cloud.png");
    Sprite spriteCloud1, spriteCloud2, spriteCloud3;
    spriteCloud1.setTexture(textureCloud);
    spriteCloud2.setTexture(textureCloud);
    spriteCloud3.setTexture(textureCloud);
    spriteCloud1.setPosition(0, 0);
    spriteCloud2.setPosition(0, 250);
    spriteCloud3.setPosition(0, 500);
    spriteCloud3.setScale(0.5f, 0.5f);
    bool cloudActive1 = false;
    bool cloudActive2 = false;
    bool cloudActive3 = false;
    float cloudSpeed1 = 0.0f;
    float cloudSpeed2 = 0.0f;
    float cloudSpeed3 = 0.0f;

    Texture texturePlayer;
    texturePlayer.loadFromFile("graphics/player.png");
    Sprite spritePlayer;
    spritePlayer.setTexture(texturePlayer);
    spritePlayer.setPosition(580, 720);

    Texture textureRIP;
    textureRIP.loadFromFile("graphics/rip.png");
    Sprite spriteRIP;
    spriteRIP.setTexture(textureRIP);
    spriteRIP.setPosition(600, 860);

    Texture textureAxe;
    textureAxe.loadFromFile("graphics/axe.png");
    Sprite spriteAxe;
    spriteAxe.setTexture(textureAxe);
    spriteAxe.setPosition(700, 830);

    const float AXE_POSITION_LEFT = 700;
    const float AXE_POSITION_RIGHT = 1075;

    Texture textureLog;
    textureLog.loadFromFile("graphics/log.png");
    Sprite spriteLog;
    spriteLog.setTexture(textureLog);
    spriteLog.setPosition(810, 720);

    RectangleShape timeBar;
    float timeBarStartWidth = 400;
    float timeBarHeight = 80;
    timeBar.setSize(Vector2f(timeBarStartWidth, timeBarHeight));
    timeBar.setFillColor(Color::Red);
    timeBar.setPosition((1920 / 2) - timeBarStartWidth / 2, 980);
    Time gameTimeTotal;
    float timeRemaining = 6.0f;
    float timeBarWidthPerSecond = timeBarStartWidth / timeRemaining;

    bool paused = true;
    bool acceptInput = false;

    int score = 0;
    Text messageText;
    Text scoreText;

    Font font;
    font.loadFromFile("font/KOMIKAP_.ttf");
    messageText.setFont(font);
    scoreText.setFont(font);
    messageText.setString("Please Enter to Start");
    scoreText.setString("Score = 0");
    messageText.setCharacterSize(75);
    scoreText.setCharacterSize(100);
    messageText.setFillColor(Color::Green);
    scoreText.setFillColor(Color::Red);

    FloatRect textRect = messageText.getLocalBounds();

    messageText.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
    messageText.setPosition(1920 / 2.0f, 1080 / 2.0f);

    scoreText.setPosition(20, 20);

    Clock clock;
    Time dt;

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        if (Keyboard::isKeyPressed(Keyboard::Escape))
        {
            window.close();
        }

        if (event.type == Event::KeyReleased && !paused)
        {
            acceptInput = true;

            spriteAxe.setPosition(2000, spriteAxe.getPosition().y);
        }

        if (Keyboard::isKeyPressed(Keyboard::Return))
        {
            paused = false;
            score = 0;
            timeRemaining = 6.0f;

            spriteRIP.setPosition(675, 2000);

            spritePlayer.setPosition(580, 720);

            acceptInput = true;
        }

        if (!paused)
        {
            dt = clock.restart();

            timeRemaining -= dt.asSeconds();
            timeBar.setSize(Vector2f(timeBarWidthPerSecond * timeRemaining, timeBarHeight));

            if (timeRemaining <= 0.0f)
            {
                paused = true;
                acceptInput = false;
            }
        }

        if (acceptInput)
        {
            if (Keyboard::isKeyPressed(Keyboard::Right))
            {
                score++;
                timeRemaining += (2 / score) + 0.15;
                if (timeRemaining >= 6.0f)
                {
                    timeRemaining = 6.0f;
                }

                spriteAxe.setPosition(AXE_POSITION_RIGHT, spriteAxe.getPosition().y);

                spritePlayer.setPosition(1200, 720);

                acceptInput = false;
            }
            if (Keyboard::isKeyPressed(Keyboard::Left))
            {
                score++;
                timeRemaining += (2 / score) + 0.15;
                if (timeRemaining >= 6.0f)
                {
                    timeRemaining = 6.0f;
                }

                spriteAxe.setPosition(AXE_POSITION_LEFT, spriteAxe.getPosition().y);

                spritePlayer.setPosition(580, 720);

                acceptInput = false;
            }
            
        }
        
        if (!beeActive)
        {
            srand((int)time(0));
            beeSpeed = (rand() % 200) + 200;
            srand((int)time(0) * 10);
            float height = (rand() % 500) + 500;
            spriteBee.setPosition(2000, height);
            
            beeActive = true;

        }
        else 
        {
            spriteBee.setPosition(spriteBee.getPosition().x - (beeSpeed * dt.asSeconds()), spriteBee.getPosition().y);

            if (spriteBee.getPosition().x < -100)
            {
                beeActive = false;
            }
        }

        if (!cloudActive1)
        {
            srand((int)time(0) * 10);
            cloudSpeed1 = (rand() % 200) + 75;
            srand((int)time(0) * 10);
            float height = (rand() % 150);
            spriteCloud1.setPosition(-200, height);
            cloudActive1 = true;
        }
        else
        {
            spriteCloud1.setPosition(spriteCloud1.getPosition().x + (cloudSpeed1 * dt.asSeconds()), spriteCloud1.getPosition().y);
            if (spriteCloud1.getPosition().x > 1920)
            {
                cloudActive1 = false;
            }
        }

        if (!cloudActive2)
        {
            srand((int)time(0) * 20);
            cloudSpeed2 = (rand() % 200) + 75;
            srand((int)time(0) * 20);
            float height = (rand() % 300) - 150;
            spriteCloud2.setPosition(-200, height);
            cloudActive2 = true;
        }
        else
        {
            spriteCloud2.setPosition(spriteCloud2.getPosition().x + (cloudSpeed2 * dt.asSeconds()), spriteCloud2.getPosition().y);
            if (spriteCloud2.getPosition().x > 1920)
            {
                cloudActive2 = false;
            }
        }

        if (!cloudActive3)
        {
            srand((int)time(0) * 30);
            cloudSpeed3 = (rand() % 200) + 75;
            srand((int)time(0) * 30);
            float height = (rand() % 450) - 150;
            spriteCloud3.setPosition(-200, height);
            cloudActive3 = true;
        }
        else
        {
            spriteCloud3.setPosition(spriteCloud3.getPosition().x + (cloudSpeed3 * dt.asSeconds()), spriteCloud3.getPosition().y);
            if (spriteCloud3.getPosition().x > 1920)
            {
                cloudActive3 = false;
            }
            std::stringstream ss;
            ss << "Score = " << score;
            scoreText.setString(ss.str());
        }

        window.clear();
        window.draw(spriteBackground);
        window.draw(spriteCloud1);
        window.draw(spriteCloud2);
        window.draw(spriteCloud3);
        window.draw(spriteTree);

        window.draw(spritePlayer);
        window.draw(spriteAxe);
        window.draw(spriteLog);
        window.draw(spriteRIP);
        window.draw(spriteBee);
        window.draw(scoreText);
        window.draw(timeBar);
        if (paused) {
            window.draw(messageText);
        }
        window.display();
    }

    return 0;
}
