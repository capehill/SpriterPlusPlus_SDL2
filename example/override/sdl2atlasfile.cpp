#include "sdl2atlasfile.h"

#include "../../spriterengine/global/settings.h"

namespace SpriterEngine {

    SDL2AtlasFile::SDL2AtlasFile(SDL_Renderer *r, std::string initialFilePath) :
            AtlasFile(initialFilePath), m_loaded(false), renderer(r) {
        initializeFile();
    }

    const SDL_Texture *SDL2AtlasFile::getTexture() const {
        return texture;
    }

    void SDL2AtlasFile::initializeFile() {
        texture = IMG_LoadTexture(renderer, path().c_str());

        if (texture != nullptr) {
            m_loaded = true;
        } else {
            m_loaded = false;
            Settings::Settings::error(
                    "SDL2AtlasFile::initializeFile - sfml texture unable to load file from path \"" + path() + "\"");
        }
    }

    void SDL2AtlasFile::renderSprite(UniversalObjectInterface *spriteInfo, const atlasframedata data) {
    }

}
