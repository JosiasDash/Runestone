#include "Lib.hpp"
#pragma once

enum Scene {
    MENU,
    LEVELS,
    IN_GAME,
    PAUSE
};

class Game {
    public:
        Game();
        ~Game();
        void Loop();
    private:
        Scene scene;

        void InitComponents();
        void Update();
        void Events();
};
