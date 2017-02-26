
#include <SDL.h>
#include <SDL_ttf.h>
#include "override/exampleobjectfactory.h"
#include "override/examplefilefactory.h"
#include "../spriterengine/spriterengine.h"
#include "../spriterengine/global/settings.h"

const static int SCREEN_WIDTH = 1000;
const static int SCREEN_HEIGHT = 1000;

int main() {
    SpriterEngine::Settings::setErrorFunction(SpriterEngine::Settings::simpleError);

    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        SDL_Log("SDL_Init");
        return 1;
    }

    //Setup our window and renderer
    SDL_Window *window = SDL_CreateWindow("Spriter SDL2 test", 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        SDL_Log("CreateWindow");
        SDL_Quit();
        return 1;
    }
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == nullptr) {
        SDL_Log("CreateRenderer");
        SDL_Quit();
        return 1;
    }

    // load Spriter file into SpriterModel object using our custom factories
//	SpriterEngine::SpriterModel scmlModel("./GreyGuy/player.scml", new SpriterEngine::ExampleFileFactory(renderer), new SpriterEngine::ExampleObjectFactory(renderer));
    SpriterEngine::SpriterModel scmlModel("./GreyGuy/player.scon", new SpriterEngine::ExampleFileFactory(renderer),
                                          new SpriterEngine::ExampleObjectFactory(renderer));
//	SpriterEngine::SpriterModel scmlModel("./GreyGuyAtlas/GreyGuy.scml", new SpriterEngine::ExampleFileFactory(renderer), new SpriterEngine::ExampleObjectFactory(renderer));
    std::vector<SpriterEngine::EntityInstance *> instances;

    SDL_Event e;
    bool quit = false;
    while (!quit) {
        //Event Polling
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
            if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE) {
                quit = true;
            }
        }

        // add more instances until there are 100
        if (instances.size() < 100) {
            // create an instance of the entity named "Player"
            instances.push_back(scmlModel.getNewEntityInstance("Player"));
            SpriterEngine::EntityInstance *inst = instances.back();

            if (inst) {
                // set the instance's animation to "walk"
                inst->setCurrentAnimation("walk");

                // set the instance's scale, position, and angle to something random
                SpriterEngine::real scale = ((rand() % 1500) + 500) / 1000.0;
                inst->setScale(SpriterEngine::point(scale, scale));

                inst->setPosition(SpriterEngine::point(rand() % SCREEN_WIDTH, rand() % SCREEN_HEIGHT));

                inst->setAngle(SpriterEngine::toRadians(rand() % 360));
            }

            // update the object count text with the total number of instances
        }

        SDL_SetRenderDrawColor(renderer, 0, 80, 0, 255);
        SDL_RenderClear(renderer);

        for (auto &it : instances) {
            if (it) {
                it->setTimeElapsed(10);
                it->render();
                // it->playSoundTriggers();
            }
        }

        TTF_Font *Sans = TTF_OpenFont("./PT-Sans/PTC55F.ttf", 16);
        SDL_Color White = {255, 255, 255};
        SDL_Surface *surfaceMessage = TTF_RenderText_Solid(Sans, "put your text here", White);
        SDL_Texture *Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
        SDL_Rect Message_rect = {0, 0, 100, 30};
        SDL_RenderCopy(renderer, Message, NULL, &Message_rect);

        SDL_RenderPresent(renderer);
    }

    for (auto &it : instances) {
        delete it;
    }
    SDL_Quit();

    return 0;
}


