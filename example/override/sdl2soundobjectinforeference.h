#ifndef SFMLSOUNDOBJECTINFOREFERENCE_H
#define SFMLSOUNDOBJECTINFOREFERENCE_H

#include "../../spriterengine/override/soundobjectinforeference.h"

namespace SpriterEngine
{
	
	class SDL2SoundObjectInfoReference : public SoundObjectInfoReference
	{
	public:
//		SDL2SoundObjectInfoReference(sf::SoundBuffer &buffer);

		void playTrigger() override;

	private:
		void setPlaybackVolume() override;
		void setPlaybackPanning() override;

//		sf::Sound sound;
	};

}

#endif // SFMLSOUNDOBJECTINFOREFERENCE_H
