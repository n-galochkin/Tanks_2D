﻿#pragma once

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

    void processInput() const;

    void initialize();

    void update(float deltaTime) const;

    void render(sf::RenderWindow& window) const;

    void add_object(GameObject* object) { objects_.push_back(object); }

private:
    Game();
    
    ContentManager* content{};

    GameField* field_;

    Player* player_{};

    vector<GameObject*> objects_;
};
