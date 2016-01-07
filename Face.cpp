#include "Face.h"
#include <cairomm/context.h>
#include <giomm/resource.h>
#include <gdkmm/general.h>
#include <glibmm/fileutils.h>
#include <iostream>

Face::Face()
{
	try
	{
		mImage = Gdk::Pixbuf::create_from_resource("/face.png");
	}
	catch (const Gio::ResourceError &ex)
	{
		std::cerr<<"Error : "<<ex.what()<<std::endl;
	}
	catch (const Gdk::PixbufError &ex)
	{
		std::cerr<<"Error : "<<ex.what()<<std::endl;
	}
	
	if (mImage)
	{
		set_size_request(mImage->get_width(), mImage->get_height());
	
	}
}

Face::~Face()
{
}

bool Face::on_draw(const Cairo::RefPtr<Cairo::Context>& cr)
{
	if (!mImage)
		return false;
	
	Gtk::Allocation allocation = get_allocation();
	const int width = allocation.get_width();
	const int height = allocation.get_height();

	Gdk::Cairo::set_source_pixbuf(cr, mImage, (width - mImage->get_width())/2, (height - mImage->get_height())/2);
	
	cr->paint();

	return true;
}	
