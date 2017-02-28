
#include <SDL.h>
#include <SDL_ttf.h>
#include "override/exampleobjectfactory.h"
#include "override/examplefilefactory.h"
#include "../spriterengine/spriterengine.h"
#include "../spriterengine/global/settings.h"

using namespace std;
using namespace SpriterEngine;

const static int SCREEN_WIDTH = 1000;
const static int SCREEN_HEIGHT = 1000;
//const static int NUM_SPRITES_TO_SHOW = 1;
const static int NUM_SPRITES_TO_SHOW = 100;

void addSprite(vector<EntityInstance *> &spritesList, SpriterModel &model, int x, int y, real scale, real angle);

void drawFPS(int lastTime, SDL_Renderer *renderer);

int main() {
    // Init SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        SDL_Log("ERROR: SDL Initialization");
        return 1;
    }
    TTF_Init();

    // Setup our window and renderer
    SDL_Window *window = SDL_CreateWindow("Spriter SDL2 test", 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        SDL_Log("ERROR: CreateWindow");
        SDL_Quit();
        return 1;
    }
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr) {
        SDL_Log("ERROR: CreateRenderer");
        SDL_Quit();
        return 1;
    }

    // load Spriter file into SpriterModel object using our custom factories
//	SpriterEngine::SpriterModel scmlModel("./GreyGuy/player.scml", new SpriterEngine::ExampleFileFactory(renderer), new SpriterEngine::ExampleObjectFactory(renderer));
    SpriterEngine::SpriterModel scmlModel("./GreyGuy/player.scon", new SpriterEngine::ExampleFileFactory(renderer),
                                          new SpriterEngine::ExampleObjectFactory(renderer));
//	SpriterEngine::SpriterModel scmlModel("./GreyGuyAtlas/GreyGuy.scml", new SpriterEngine::ExampleFileFactory(renderer), new SpriterEngine::ExampleObjectFactory(renderer));

    vector<SpriterEngine::EntityInstance *> spritesList;

    SDL_Event e;
    bool quit = false;
    int pastTime = SDL_GetTicks();

    while (!quit) {
        // Event Polling
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
            if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE) {
                quit = true;
            }
        }

        if (spritesList.size() < NUM_SPRITES_TO_SHOW) {
            if (NUM_SPRITES_TO_SHOW == 1) {
                // just one sprite, place it nicely
                addSprite(spritesList, scmlModel, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 1.6, 0);
            } else {
                // set the instance's scale, position, and angle to something random
                SpriterEngine::real scale = ((rand() % 1500) + 500) / 1000.0;
                SpriterEngine::real angle = rand() % 360;
                int posX = rand() % SCREEN_WIDTH;
                int posY = rand() % SCREEN_HEIGHT;
                addSprite(spritesList, scmlModel, posX, posY, scale, angle);
            }
        }

        SDL_SetRenderDrawColor(renderer, 0, 80, 0, 255);
        SDL_RenderClear(renderer);

        int currentTime = SDL_GetTicks();
        int timeElapsed = currentTime - pastTime;
        pastTime = currentTime;

        for (auto &it : spritesList) {
            if (it) {
                it->setTimeElapsed(timeElapsed);
                it->render();
                // it->playSoundTriggers();
            }
        }

        drawFPS(timeElapsed, renderer);
        SDL_RenderPresent(renderer);
    }

    // Clean up
    for (auto &it : spritesList) {
        delete it;
    }
    SDL_Quit();
    TTF_Quit();

    return 0;
}

void addSprite(vector<EntityInstance *> &spritesList, SpriterModel &model, int x, int y, real scale, real angle) {
    // create an instance of the entity named "Player"
    spritesList.push_back(model.getNewEntityInstance("Player"));
    SpriterEngine::EntityInstance *inst = spritesList.back();

    if (inst) {
        inst->setCurrentAnimation("walk");
        inst->setScale(SpriterEngine::point(scale, scale));
        inst->setPosition(SpriterEngine::point(x, y));
        inst->setAngle(SpriterEngine::toRadians(angle));
    }
}

void drawFPS(int timeElapsed, SDL_Renderer *renderer) {
    static TTF_Font *textFont = TTF_OpenFont("./PT-Sans/PTC55F.ttf", 16);
    static int timeAccumulator = 0;
    static int fps = 0;
    static SDL_Surface *fpsSurface = nullptr;
    static SDL_Texture *fpsTexture = nullptr;
    static SDL_Rect fpsRect;

    timeAccumulator += timeElapsed;
    if (timeAccumulator >= 1000) {
        string text = "FPS: " + to_string(fps);
        fpsSurface = TTF_RenderText_Solid(textFont, text.c_str(), {255, 255, 255});
        fpsTexture = SDL_CreateTextureFromSurface(renderer, fpsSurface);
        fpsRect = {4, 4, fpsSurface->w, fpsSurface->h};

        timeAccumulator = 0;
        fps = 0;
    }
    fps++;

    if (fpsTexture) {
        SDL_RenderCopy(renderer, fpsTexture, NULL, &fpsRect);
    }
}