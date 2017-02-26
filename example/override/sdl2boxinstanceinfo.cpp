#include "sdl2boxinstanceinfo.h"

#include "../../spriterengine/global/settings.h"

namespace SpriterEngine
{

	SDL2BoxInstanceInfo::SDL2BoxInstanceInfo(point initialSize, SDL_Renderer *validRenderWindow) :
		BoxInstanceInfo(initialSize),
		renderWindow(validRenderWindow),
		rectangle({0,0,int(initialSize.x), int(initialSize.y)})
	{
	}

	void SDL2BoxInstanceInfo::render()
	{
		if (Settings::renderDebugBoxes)
		{
//			rectangle.setPosition(getPosition().x, getPosition().y);
//			rectangle.setRotation(toDegrees(getAngle()));
//			rectangle.setScale(getScale().x, getScale().y);
//			rectangle.setOrigin(getPivot().x*getSize().x, getPivot().y*getSize().y);
//			renderWindow->draw(rectangle);
		}
	}

}
