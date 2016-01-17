#ifndef EXECUTE_H
#define EXECUTE_H

#include <gtkmm.h>

class Win;

class Execute
{
	public:
	Execute();
	void follow_order(Win* caller);
	void set_prog(const char* c)
	{
		prog = c;
	}
		
	private:
	
	const char *prog;
	Glib::Threads::Mutex m_Mutex; //need to learn more about this shit
};
#endif
