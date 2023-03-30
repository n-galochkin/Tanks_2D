#include "ContentManager.h"


bool ContentManager::TryLoadFiles()
{
    if (!T_LightTank.loadFromFile("Content/LightTank.png"))
    {
        return false;
    }

    return true;
}
