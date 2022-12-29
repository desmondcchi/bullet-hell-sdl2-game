#include "../headers/Game.hpp"

Game* Game::GetInstance() {
    return game_instance;
}

void Game::Init() {
    SDL_Init(SDL_INIT_EVERYTHING);
    window = SDL_CreateWindow("Bullet Hell Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, 0); 
    game_status = GAME_STATUS::GAME_STATUS::RUNNING;
}

void Game::Destroy() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);  
    SDL_Quit();
}

SDL_Window* Game::GetWindow() {
    return window;
}

SDL_Renderer* Game::GetRenderer() {
    return renderer;
}

SDL_Event& Game::GetEvent() {
    return event;
}

GAME_STATUS::GAME_STATUS Game::GetGameStatus() {
    return game_status;
}

void Game::SetGameStatus(GAME_STATUS::GAME_STATUS status) {
    game_status = GAME_STATUS::GAME_STATUS(status);
}
