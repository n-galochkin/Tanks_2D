#pragma once

#include "ContentManager.h"
#include "GameField.h"
#include "GameObject.h"
#include "SFML/Graphics/RenderWindow.hpp"
#include "Tools/PerformanceMeasurer.h"

class Game
{
public:

    static Game& instance()
    {
        static Game* instance = new Game();
        return *instance;
    }
    
    ContentManager& get_content_manager() const { return *content_; }

    void processInput(RenderWindow& window);

    void initialize();

    void update() const;

    void render(sf::RenderWindow& window, const float deltaTime) const;

    void add_object(GameObject* object) { objects_.push_back(object); }

private:
    Game();
    
    ContentManager* content_{};

    PerformanceMeasurer* performance_measurer_;

    // TODO: world instead field
    GameField* field_;

    Player* player_{};

    vector<GameObject*> objects_;
    
    Keyboard::Key _lastPressedKey = Keyboard::Unknown;
};
