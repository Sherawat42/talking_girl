#include "Execute.h"
#include "Win.h"

//#include <unistd.h>
#include <iostream>
#include <cstdlib>

Execute::Execute():
m_Mutex()
{
}

void  Execute::follow_order(Win *caller)
{
	Glib::Threads::Mutex::Lock lock(m_Mutex);
//	execl(prog,"","",NULL);
	std::cout<<prog<<std::endl;
	system(prog);
	lock.release();
	caller->notify();
}
