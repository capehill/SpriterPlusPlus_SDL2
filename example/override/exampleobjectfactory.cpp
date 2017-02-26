#include "exampleobjectfactory.h"

#include "sfmlpointinstanceinfo.h"
#include "sfmlboxinstanceinfo.h"
#include "sfmlboneinstanceinfo.h"
#include "sfmlsoundobjectinforeference.h"

namespace SpriterEngine
{

	ExampleObjectFactory::ExampleObjectFactory(SDL_Renderer *validRenderer) :
		renderWindow(validRenderer)
	{
	}

	PointInstanceInfo * ExampleObjectFactory::newPointInstanceInfo()
	{
		return new SfmlPointInstanceInfo(renderWindow);
	}

	BoxInstanceInfo * ExampleObjectFactory::newBoxInstanceInfo(point size)
	{
		return new SfmlBoxInstanceInfo(size, renderWindow);
	}

	BoneInstanceInfo * ExampleObjectFactory::newBoneInstanceInfo(point size)
	{
		return new SfmlBoneInstanceInfo(size, renderWindow);
	}

}