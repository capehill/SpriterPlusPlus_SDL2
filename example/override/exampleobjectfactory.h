#ifndef EXAMPLEOBJECTFACTORY_H
#define EXAMPLEOBJECTFACTORY_H

#include <SDL_system.h>
#include "../../spriterengine/override/objectfactory.h"

namespace SpriterEngine
{

	class ExampleObjectFactory : public ObjectFactory
	{
	public:
		ExampleObjectFactory(SDL_Renderer *validRenderer);
		
		PointInstanceInfo *newPointInstanceInfo() override;

		BoxInstanceInfo *newBoxInstanceInfo(point size) override;

		BoneInstanceInfo *newBoneInstanceInfo(point size) override;

	private:
		SDL_Renderer *renderWindow;
	};

}

#endif // EXAMPLEOBJECTFACTORY_H
