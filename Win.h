#ifndef WIN_H
#define WIN_H

#include <gtkmm.h>
#include "Face.h"
#include "TTS.h"

class Win : public Gtk::Window
{
	public:
	Win();
	~Win();

	protected:
	Face face;
	TTS mTTS;
	Gtk::Box box_v, box_h;
	Gtk::Entry entry;
	Gtk::Button submit;

	void on_submit();
};
#endif
