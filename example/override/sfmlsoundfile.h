#ifndef SFMLSOUNDFILE_H
#define SFMLSOUNDFILE_H

#include "../../spriterengine/override/soundfile.h"

namespace SpriterEngine
{

	class SfmlSoundFile : public SoundFile
	{
	public:
		SfmlSoundFile(std::string initialFilePath);

		SoundObjectInfoReference * newSoundInfoReference();

	private:
//		sf::SoundBuffer buffer;

		void initializeFile();
	};

}

#endif // SFMLSOUNDFILE_H
