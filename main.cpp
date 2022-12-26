#include "SDL2/SDL.h"
#include "headers/Game.hpp"

int main() {
    Game::Init();

    SDL_SetRenderDrawColor(Game::GetRenderer(), 255, 0, 0, 255);

    SDL_RenderClear(Game::GetRenderer());
    SDL_RenderPresent(Game::GetRenderer());

    while (Game::GetGameStatus() == GAME_STATUS::RUNNING) {
        while (SDL_PollEvent(&Game::GetEvent())) {
            if (Game::GetEvent().type == SDL_QUIT) {
                Game::SetGameStatus(GAME_STATUS::STOP);
            }
        }
    }

    Game::Destroy();
}
