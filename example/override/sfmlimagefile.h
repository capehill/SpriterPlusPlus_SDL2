#ifndef SFMLIMAGEFILE_H
#define SFMLIMAGEFILE_H

#include "../../spriterengine/override/imagefile.h"
#include <SDL_image.h>

namespace SpriterEngine
{
	class SfmlImageFile : public ImageFile
	{
	public:
		SfmlImageFile(std::string initialFilePath, point initialDefaultPivot, SDL_Renderer *validRenderWindow);

		void renderSprite(UniversalObjectInterface *spriteInfo) override;

		void setAtlasFile(AtlasFile *initialAtlasFile, atlasframedata initialAtlasFrameData) override;

	private:
		SDL_Renderer *renderWindow;
		SDL_Texture *texture;
		SDL_Rect frame_rect;

		void initializeFile();
	};

}

#endif // SFMLIMAGEFILE_H
