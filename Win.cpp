#include "Win.h"
#include <string>
#include <stdlib.h>

Win::Win():
box_v(Gtk::ORIENTATION_VERTICAL),
box_h(Gtk::ORIENTATION_HORIZONTAL),
submit("Submit"),
worker(),
m_Dispatcher(),
worker_thread(nullptr)
{
	set_title("Talking Girl");
	
	add(box_v);

	box_v.pack_start(face);
	box_v.pack_start(box_h);
	box_h.pack_start(entry);
	box_h.pack_start(submit);

	submit.signal_clicked().connect(sigc::mem_fun(*this, &Win::on_submit));
	m_Dispatcher.connect(sigc::mem_fun(*this, &Win::on_message_from_worker));
	
	submit.set_can_default();
	submit.grab_default();
	
	show_all_children();
}

Win::~Win()
{
}

void Win::on_submit()
{
	std::string command, program;
	command = entry.get_text();
	int beg = 0, space, status;
	space = command.find(" ");
	
	std::string temp =command.substr(0, space);
	if (temp.compare("open")==0 || temp.compare("Open")==0)
	{
		program = command.substr(space+1, command.length()-space);
		mTTS.speak("Opening"+program);
	
		if (program.compare("terminal")==0 || program.compare("Terminal")==0)
		{	program = "x-terminal-emulator";
			system(program.c_str());}
			
		const char *prog = program.c_str();
		if (worker_thread)
			mTTS.speak("Cannot start a new thread");
		else
		{
			worker.set_prog(prog);
			worker_thread = Glib::Threads::Thread::create(sigc::bind(sigc::mem_fun(worker, &Execute::follow_order), this));
		}
	}		
	
	else if (temp.compare("exit")==0)
	{
		if (worker_thread)
			worker_thread->join();
		mTTS.speak("Bye! Have a nice day!");
		hide();
	}
}

void Win::notify()
{
	m_Dispatcher.emit();
}

void Win::on_message_from_worker()
{
	worker_thread->join();
	worker_thread = nullptr;
}	
