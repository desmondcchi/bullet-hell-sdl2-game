#include "SDL2/SDL.h"
#include "headers/Game.hpp"
#include "headers/MAX_FPS.hpp"

int main() {
    Game::Init();

    SDL_SetRenderDrawColor(Game::GetRenderer(), 255, 0, 0, 255);

    SDL_RenderClear(Game::GetRenderer());
    SDL_RenderPresent(Game::GetRenderer());
    
    Uint32 frame_start = 0;
    Uint32 frame_time = 0;

    while (Game::GetGameStatus() == GAME_STATUS::GAME_STATUS::RUNNING) {
        frame_start = SDL_GetTicks();

        Game::HandleEvents();
        Game::Update();
        Game::Render();

        frame_time = SDL_GetTicks() - frame_start;
        
        // Limiting the game FPS, specified in ../headers/MAX_FPS.hpp.
        if (MAX_FPS::FRAME_DELAY > frame_time) {
            SDL_Delay(MAX_FPS::FRAME_DELAY - frame_time);
        }
    }

    Game::Destroy();
}
