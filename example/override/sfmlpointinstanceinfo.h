#ifndef SFMLPOINTINSTANCEINFO_H
#define SFMLPOINTINSTANCEINFO_H

#include "../../spriterengine/objectinfo/pointinstanceinfo.h"
#include <SDL_render.h>

namespace SpriterEngine
{

	class SfmlPointInstanceInfo : public PointInstanceInfo
	{
	public:
		SfmlPointInstanceInfo(SDL_Renderer *validRenderWindow);

		void render() override;

	private:
		SDL_Renderer *renderWindow;

//		sf::CircleShape circle;
	};

}

#endif // SFMLPOINTINSTANCEINFO_H
