#ifndef GAME_HPP
#define GAME_HPP

#include "SDL2/SDL.h"

enum GAME_STATUS {
    RUNNING,
    STOP,
    PAUSE,
};

class Game {
    public:
        static inline Game* GetInstance() {
            static Game* game_instance;
            return game_instance;
        }

        // Delete the copy constructor so that it can remain a single instance.
        Game(const Game&) = delete;

        // Initializes the SDL window, renderer, and event.
        static inline void Init() {
            SDL_Init(SDL_INIT_EVERYTHING);
            window = SDL_CreateWindow("Bullet Hell Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
            renderer = SDL_CreateRenderer(window, -1, 0); 
            game_status = GAME_STATUS::RUNNING;
        }

        // Cleans up memory and destroys SDL window, renderer, and other objects.
        static inline void Destroy() {
            SDL_DestroyWindow(window);
            SDL_DestroyRenderer(renderer);  
            SDL_Quit();
        }

        // Getter for window.
        static inline SDL_Window* GetWindow() {
            return window;
        }

        // Getter for renderer.
        static inline SDL_Renderer* GetRenderer() {
            return renderer;
        }

        // Getter for the lvalue reference of event.
        static inline SDL_Event& GetEvent() {
            return event;
        }

        // Getter for game_status.
        static inline GAME_STATUS GetGameStatus() {
            return game_status;
        }

        // Setter for game_status.
        static inline void SetGameStatus(GAME_STATUS status) {
            game_status = GAME_STATUS(status);
        }

    private:
        Game() = default;
        ~Game() = default;

        // inline keyword makes it so that the static variables do not need to be
        // defined outside the class.
        static inline SDL_Window* window;
        static inline SDL_Renderer* renderer;
        static inline SDL_Event event;

        static inline GAME_STATUS game_status;
};

#endif
