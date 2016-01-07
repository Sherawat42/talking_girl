#include "Win.h"
#include <string>
#include <stdlib.h>

Win::Win():
box_v(Gtk::ORIENTATION_VERTICAL),
box_h(Gtk::ORIENTATION_HORIZONTAL),
submit("Submit")
{
	set_title("Talking Girl");
	
	add(box_v);

	box_v.pack_start(face);
	box_v.pack_start(box_h);
	box_h.pack_start(entry);
	box_h.pack_start(submit);

	submit.signal_clicked().connect(sigc::mem_fun(*this, &Win::on_submit));
	
	submit.set_can_default();
	submit.grab_default();
	
	show_all_children();
}

Win::~Win()
{
}

void Win::on_submit()
{
	std::string command;
	mTTS.speak("Opening terminal");
	
	system("x-terminal-emulator");
}
	
