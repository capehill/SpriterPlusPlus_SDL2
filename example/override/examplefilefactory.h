#ifndef EXAMPLEFILEFACTORY_H
#define EXAMPLEFILEFACTORY_H

#include "../../spriterengine/override/filefactory.h"

namespace SpriterEngine
{

	class ExampleFileFactory : public FileFactory
	{
	public:
		ExampleFileFactory(SDL_Renderer *validRenderWindow);
		
		ImageFile *newImageFile(const std::string &initialFilePath, point initialDefaultPivot, atlasdata atlasData) override;

		AtlasFile *newAtlasFile(const std::string &initialFilePath) override;

		SoundFile *newSoundFile(const std::string &initialFilePath) override;

		SpriterFileDocumentWrapper *newScmlDocumentWrapper() override;

		SpriterFileDocumentWrapper *newSconDocumentWrapper() override;

	private:
		SDL_Renderer *renderWindow;
	};

}

#endif // EXAMPLEFILEFACTORY_H
