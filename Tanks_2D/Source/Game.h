#pragma once

#include "ContentManager.h"
#include "GameField.h"
#include "GameObject.h"
#include "SFML/Graphics/RenderWindow.hpp"

class Game
{
public:

    static Game& instance()
    {
        static Game* instance = new Game();
        return *instance;
    }
    
    ContentManager& get_content_manager() const { return *content; }

    void handleInput();

    void init();

    void update(float deltaTime);

    void render(sf::RenderWindow& window);

    void add_object(GameObject* object) { objects.push_back(object); }

private:
    Game();
    
    ContentManager* content{};

    GameField* field;

    Player* player{};

    vector<GameObject*> objects;
};
