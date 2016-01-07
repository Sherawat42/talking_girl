#include "TTS.h"

TTS::TTS()
{
	festival_initialize(load_init_files, heap_size);
}

TTS::~TTS()
{
	festival_wait_for_spooler();
}

void TTS::speak(string s)
{
	const char *txt = s.c_str() ;
	EST_String speechString = EST_String(txt);
	festival_say_text(speechString);
}
