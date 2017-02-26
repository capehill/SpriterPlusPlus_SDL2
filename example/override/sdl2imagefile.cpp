#include "sdl2imagefile.h"

#include "../../spriterengine/global/settings.h"

#include "../../spriterengine/objectinfo/universalobjectinterface.h"

#include "sdl2atlasfile.h"

namespace SpriterEngine {

    SDL2ImageFile::SDL2ImageFile(std::string initialFilePath, point initialDefaultPivot,
                                 SDL_Renderer *validRenderWindow) :
            ImageFile(initialFilePath, initialDefaultPivot),
            renderWindow(validRenderWindow) {
        initializeFile();
    }

    void SDL2ImageFile::initializeFile() {
        texture = IMG_LoadTexture(renderWindow, path().c_str());

        if (texture == nullptr) {
            Settings::Settings::error(
                    "SDL2ImageFile::initializeFile - sfml texture unable to load file from path \"" + path() + "\"");
            return;
        }

        int texture_width, texture_height;
        SDL_QueryTexture(texture, NULL, NULL, &texture_width, &texture_height);
        frame_rect = {0, 0, texture_width, texture_height};
    }

    void SDL2ImageFile::renderSprite(UniversalObjectInterface *spriteInfo) {
        if (atlasFile) {
            // Adding of transformations is in the reverse order you would expect.
            if (atlasFrameData.rotated) {
                SDL_Rect source_rect = {
                        frame_rect.x,
                        frame_rect.y,
                        frame_rect.w,
                        frame_rect.h
                };
                real dest_scale_w = frame_rect.w * spriteInfo->getScale().x;
                real dest_scale_h = frame_rect.h * spriteInfo->getScale().y;
                SDL_Point anchor = {
                        int(spriteInfo->getPivot().x * dest_scale_w),
                        int(spriteInfo->getPivot().y * dest_scale_h)
                };
                SDL_Rect destination_rect = {
                        int(spriteInfo->getPosition().x - anchor.x),
                        int(spriteInfo->getPosition().y - anchor.y),
                        int(dest_scale_w),
                        int(dest_scale_h)
                };
                real angle_radiants = spriteInfo->getAngle();
                real destination_angle = toDegrees(angle_radiants) - 90;

                SDL_SetTextureAlphaMod(texture, (Uint8) (255 - spriteInfo->getAlpha()));
                SDL_RenderCopyEx(renderWindow,
                                 texture,
                                 &source_rect,
                                 &destination_rect,
                                 destination_angle,
                                 &anchor,
                                 SDL_FLIP_NONE
                );
            } else {
                SDL_Rect source_rect = {
                        frame_rect.x,
                        frame_rect.y,
                        frame_rect.w,
                        frame_rect.h
                };
                real dest_scale_w = frame_rect.w * spriteInfo->getScale().x;
                real dest_scale_h = frame_rect.h * spriteInfo->getScale().y;
                SDL_Point anchor = {
                        int(spriteInfo->getPivot().x * dest_scale_w),
                        int(spriteInfo->getPivot().y * dest_scale_h)
                };
                SDL_Rect destination_rect = {
                        int(spriteInfo->getPosition().x - anchor.x),
                        int(spriteInfo->getPosition().y - anchor.y),
                        int(dest_scale_w),
                        int(dest_scale_h)
                };
                real angle_radiants = spriteInfo->getAngle();
                real destination_angle = toDegrees(angle_radiants);

                SDL_SetTextureAlphaMod(texture, (Uint8) (255 - spriteInfo->getAlpha()));
                SDL_RenderCopyEx(renderWindow,
                                 texture,
                                 &source_rect,
                                 &destination_rect,
                                 destination_angle,
                                 &anchor,
                                 SDL_FLIP_NONE
                );
            }
        } else {
            SDL_Rect source_rect = {
                    int(atlasFrameData.spriteSourcePosition.x),
                    int(atlasFrameData.spriteSourcePosition.y),
                    frame_rect.w,
                    frame_rect.h
            };
            real dest_scale_w = frame_rect.w * spriteInfo->getScale().x;
            real dest_scale_h = frame_rect.h * spriteInfo->getScale().y;
            SDL_Point anchor = {
                    int(spriteInfo->getPivot().x * dest_scale_w),
                    int(spriteInfo->getPivot().y * dest_scale_h)
            };
            SDL_Rect destination_rect = {
                    int(spriteInfo->getPosition().x - anchor.x),
                    int(spriteInfo->getPosition().y - anchor.y),
                    int(dest_scale_w),
                    int(dest_scale_h)
            };
            real angle_radiants = spriteInfo->getAngle();
            real destination_angle = toDegrees(angle_radiants);

            SDL_SetTextureAlphaMod(texture, (Uint8) (255 - spriteInfo->getAlpha()));
            SDL_RenderCopyEx(renderWindow,
                             texture,
                             &source_rect,
                             &destination_rect,
                             destination_angle,
                             &anchor,
                             SDL_FLIP_NONE
            );
        }
    }

    // Overwritten so we can create the sprite from the texture.
    void SDL2ImageFile::setAtlasFile(AtlasFile *initialAtlasFile, atlasframedata initialAtlasFrameData) {
        ImageFile::setAtlasFile(initialAtlasFile, initialAtlasFrameData);

        // atlasFile should be a SDL2AtlasFile
        if (atlasFile && static_cast<SDL2AtlasFile *>(atlasFile)->loaded()) {
            const SDL_Texture *atlasTexture = static_cast<SDL2AtlasFile *>(atlasFile)->getTexture();
            texture = (SDL_Texture *) atlasTexture;
            if (atlasFrameData.rotated) {
                // When rotated, the atlasdata framesize are relative to the original. Not the frame
                frame_rect = {
                        int(atlasFrameData.framePosition.x),
                        int(atlasFrameData.framePosition.y),
                        int(atlasFrameData.frameSize.y),
                        int(atlasFrameData.frameSize.x)
                };
            } else {
                frame_rect = {
                        int(atlasFrameData.framePosition.x),
                        int(atlasFrameData.framePosition.y),
                        int(atlasFrameData.frameSize.x),
                        int(atlasFrameData.frameSize.y)
                };
            }
        }
    }
}
