#ifndef TTS_H
#define TTS_H

#include <string>
#include <festival/festival.h>

class TTS
{
	int heap_size = 210000;
	int load_init_files = 1;
	
	public:
	TTS();
	~TTS();
	void speak(string s);
};

#endif
