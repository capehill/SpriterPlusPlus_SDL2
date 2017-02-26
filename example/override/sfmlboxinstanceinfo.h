#ifndef SFMLBOXINSTANCEINFO_H
#define SFMLBOXINSTANCEINFO_H


#include "../../spriterengine/objectinfo/boxinstanceinfo.h"
#include <SDL_render.h>

namespace SpriterEngine
{

	class SfmlBoxInstanceInfo : public BoxInstanceInfo
	{
	public:
		SfmlBoxInstanceInfo(point initialSize, SDL_Renderer *validRenderWindow);

		void render() override;

	private:
		SDL_Renderer *renderWindow;

		SDL_Rect rectangle;
	};

}

#endif // SFMLBOXINSTANCEINFO_H
