#include <gtkmm/application.h>
#include <gtkmm/window.h>
#include <sys/types.h>
#include "Win.h"

int main(int argc, char *argv[])
{
	auto app = Gtk::Application::create(argc, argv, "Talking Girl");

/*	Face face;
	TTS mTTS;	
	Gtk::Window window;
	window.set_title("Talking Girl");
	window.add(face);
	window.show_all_children();
*/
	TTS mTTS;
	Win window;
	
	int pid = fork();
	if (pid==0)
		mTTS.speak("Hello Sir! How may I help you");
	else
		app->run(window);
	return 0;
}
