#include "../include/Game.hpp"

Game::Game()
{
    InitWindow(1600, 1000, "Runestone");
    InitComponents();
    scene = Scene::MENU;
}

Game::~Game()
{
    UnloadTexture(menu_back);
    CloseWindow();
    std::exit(0);
}

void Game::Loop()
{
    while (!WindowShouldClose()) {
        BeginDrawing();
        Events();
        Update();
        EndDrawing();
    }
}

// Private

void Game::InitComponents()
{
    std::string menu_back_path(std::string(ROOT) + "/assets/menu_back.jpg");
    std::vector<std::string> menu_options_tmp = {"START", "HELP", "EXIT"};
    
    SetTargetFPS(60);
    menu_back = LoadTexture(menu_back_path.c_str());
    for (auto &option: menu_options_tmp) {
        menu_options.push_back(Text{option, 45, WHITE});
    }
}

void Game::Update()
{
    ClearBackground(BLACK);
    if (scene == Scene::MENU) {
        DrawMenu();
    }
}

void Game::Events()
{
    if (scene == Scene::MENU)
        MenuEvents();
}

void Game::DrawMenu()
{
    DrawTexture(menu_back, 0, 0, WHITE);
    std::pair<int, int> position(120, 500);

    for (auto &option: menu_options) {
        DrawText(option.content.c_str(), position.first, position.second, option.size, option.color);
        position.second += 100;
    }
}

void Game::MenuEvents()
{
    Vector2 mousePos = GetMousePosition();
    Vector2 size{100, 50};
    Vector2 position{120, 500};

    for (auto &option: menu_options) {
        if (PointContains(position, size, mousePos)) {
            option.color = BLUE;
            option.size = 50;
        } else {
            option.color = WHITE;
            option.size = 45;
        }
        position.y += 100;
    }
    position = {120, 500};
    mousePos = GetMousePosition();
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        if (PointContains(position, size, mousePos)) {
            scene = Scene::LEVELS;
        }
        if (PointContains(Vector2{position.x, position.y + 200}, size, mousePos)) {
            // closed = true;
            this->~Game();
            // CloseWindow();
        }
    }
}

bool Game::PointContains(Vector2 origin, Vector2 size, Vector2 point)
{
    return (point.x >= origin.x) && (point.x <= origin.x + size.x) && (point.y >= origin.y) && (point.y <= origin.y + size.y);
}
