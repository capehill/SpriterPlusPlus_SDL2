#ifndef SFMLBONEINSTANCEINFO_H
#define SFMLBONEINSTANCEINFO_H

#include "../../spriterengine/objectinfo/boneinstanceinfo.h"
#include <SDL_render.h>

namespace SpriterEngine
{

	class SfmlBoneInstanceInfo : public BoneInstanceInfo
	{
	public:
		SfmlBoneInstanceInfo(point initialSize, SDL_Renderer *validRenderWindow);

		void render() override;

	private:
		SDL_Renderer *renderWindow;

//		sf::ConvexShape boneShape;
	};

}

#endif // SFMLBONEINSTANCEINFO_H
