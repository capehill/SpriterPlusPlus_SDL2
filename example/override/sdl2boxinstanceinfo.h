#ifndef SFMLBOXINSTANCEINFO_H
#define SFMLBOXINSTANCEINFO_H


#include "../../spriterengine/objectinfo/boxinstanceinfo.h"
#include <SDL_render.h>

namespace SpriterEngine
{

	class SDL2BoxInstanceInfo : public BoxInstanceInfo
	{
	public:
		SDL2BoxInstanceInfo(point initialSize, SDL_Renderer *validRenderWindow);

		void render() override;

	private:
		SDL_Renderer *renderWindow;

		SDL_Rect rectangle;
	};

}

#endif // SFMLBOXINSTANCEINFO_H
