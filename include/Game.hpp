#include "Lib.hpp"
#pragma once


enum Scene {
    MENU,
    LEVELS,
    IN_GAME,
    PAUSE
};

struct Text {
    std::string content;
    int size;
    Color color;
};

class Game {
    public:
        Game();
        ~Game();
        void Loop();
    private:
        Scene scene;

        // Menu
        Texture2D menu_back;
        std::vector<Text> menu_options;

        void InitComponents();
        void Update();
        void Events();
        void DrawMenu();
        void MenuEvents();
        bool PointContains(Vector2 origin, Vector2 size, Vector2 point);
};
