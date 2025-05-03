#include "../include/Game.hpp"

Game::Game()
{
    InitWindow(1600, 1000, "Runestone");
    InitComponents();
}

Game::~Game()
{
    CloseWindow();
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
    SetTargetFPS(60);
}

void Game::Update()
{
    ClearBackground(BLACK);
}

void Game::Events()
{

}
