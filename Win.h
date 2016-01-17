#ifndef WIN_H
#define WIN_H

#include <gtkmm.h>
#include <vector>
#include "Face.h"
#include "TTS.h"
#include "Execute.h"

class Win : public Gtk::Window
{
	public:
	Win();
	void notify();
	~Win();

	protected:
	Face face;
	TTS mTTS;
	Gtk::Box box_v, box_h;
	Gtk::Entry entry;
	Gtk::Button submit;

	void on_submit();

	private:
	Execute worker;
	Glib::Dispatcher m_Dispatcher;
	Glib::Threads::Thread *worker_thread;

	void on_message_from_worker();
};
#endif
