#ifndef SFMLSOUNDFILE_H
#define SFMLSOUNDFILE_H

#include "../../spriterengine/override/soundfile.h"

namespace SpriterEngine
{

	class SDL2SoundFile : public SoundFile
	{
	public:
		SDL2SoundFile(std::string initialFilePath);

		SoundObjectInfoReference * newSoundInfoReference();

	private:
//		sf::SoundBuffer buffer;

		void initializeFile();
	};

}

#endif // SFMLSOUNDFILE_H
