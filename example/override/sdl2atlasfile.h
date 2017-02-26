#ifndef SFMLATLASFILE_H
#define SFMLATLASFILE_H

#include "../../spriterengine/override/atlasfile.h"
#include <SDL_image.h>
#include <string>

namespace SpriterEngine
{
	class SDL2AtlasFile : public AtlasFile
	{
	public:
		SDL2AtlasFile(SDL_Renderer *renderer, std::string initialFilePath);

		const SDL_Texture *getTexture() const;

		bool loaded() {return m_loaded;}

	private:
		SDL_Renderer *renderer;
		SDL_Texture *texture;

		void initializeFile();

		void renderSprite(UniversalObjectInterface *spriteInfo, const atlasframedata data) override;

		bool m_loaded;
	};

}

#endif // SFMLATLASFILE_H
