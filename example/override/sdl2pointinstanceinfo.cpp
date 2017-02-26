#include "sdl2pointinstanceinfo.h"

#include "../../spriterengine/global/settings.h"

namespace SpriterEngine
{

	SDL2PointInstanceInfo::SDL2PointInstanceInfo(SDL_Renderer *validRenderWindow) :
		renderWindow(validRenderWindow)
//		circle(10)
	{
//		circle.setFillColor(sf::Color::Red);
//		circle.setOrigin(5, 5);
	}

	void SDL2PointInstanceInfo::render()
	{
		if (Settings::renderDebugPoints)
		{
//			circle.setPosition(getPosition().x, getPosition().y);
//			circle.setRotation(toDegrees(getAngle()));
//			renderWindow->draw(circle);
		}
	}

}
