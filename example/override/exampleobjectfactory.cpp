#include "exampleobjectfactory.h"

#include "sdl2pointinstanceinfo.h"
#include "sdl2boxinstanceinfo.h"
#include "sdl2boneinstanceinfo.h"
#include "sdl2soundobjectinforeference.h"

namespace SpriterEngine
{

	ExampleObjectFactory::ExampleObjectFactory(SDL_Renderer *validRenderer) :
		renderWindow(validRenderer)
	{
	}

	PointInstanceInfo * ExampleObjectFactory::newPointInstanceInfo()
	{
		return new SDL2PointInstanceInfo(renderWindow);
	}

	BoxInstanceInfo * ExampleObjectFactory::newBoxInstanceInfo(point size)
	{
		return new SDL2BoxInstanceInfo(size, renderWindow);
	}

	BoneInstanceInfo * ExampleObjectFactory::newBoneInstanceInfo(point size)
	{
		return new SDL2BoneInstanceInfo(size, renderWindow);
	}

}