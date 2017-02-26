#include "sfmlatlasfile.h"

#include "../../spriterengine/global/settings.h"

namespace SpriterEngine {

    SfmlAtlasFile::SfmlAtlasFile(SDL_Renderer *r, std::string initialFilePath) :
            AtlasFile(initialFilePath), m_loaded(false), renderer(r) {
        initializeFile();
    }

    const SDL_Texture *SfmlAtlasFile::getTexture() const {
        return texture;
    }

    void SfmlAtlasFile::initializeFile() {
        texture = IMG_LoadTexture(renderer, path().c_str());

        if (texture != nullptr) {
            m_loaded = true;
        } else {
            m_loaded = false;
            Settings::Settings::error(
                    "SfmlAtlasFile::initializeFile - sfml texture unable to load file from path \"" + path() + "\"");
        }
    }

    void SfmlAtlasFile::renderSprite(UniversalObjectInterface *spriteInfo, const atlasframedata data) {
    }

}
