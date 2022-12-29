#ifndef GAME_HPP
#define GAME_HPP

#include "SDL2/SDL.h"
#include "GAME_STATUS.hpp"

class Game {
    public:
        static Game* GetInstance();

        // Delete the copy constructor so that it can remain a single instance.
        Game(const Game&) = delete;

        // Initializes the SDL window, renderer, and event.
        static void Init();

        // Cleans up memory and destroys SDL window, renderer, and other objects.
        static void Destroy();

        // Getter for window.
        static SDL_Window* GetWindow();

        // Getter for renderer.
        static SDL_Renderer* GetRenderer();

        // Getter for the lvalue reference of event.
        static SDL_Event& GetEvent();

        // Getter for game_status.
        static GAME_STATUS::GAME_STATUS GetGameStatus();

        // Setter for game_status.
        static void SetGameStatus(GAME_STATUS::GAME_STATUS status);

    private:
        Game() = default;
        ~Game() = default;

        // inline keyword makes it so that the static variables do not need to be
        // defined outside the class.
        static inline Game* game_instance;

        static inline SDL_Window* window;
        static inline SDL_Renderer* renderer;
        static inline SDL_Event event;

        static inline GAME_STATUS::GAME_STATUS game_status;
};

#endif
