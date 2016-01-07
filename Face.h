#ifndef FACE_H
#define FACE_H

#include <gtkmm/drawingarea.h>
#include <gdkmm/pixbuf.h>

class Face : public Gtk::DrawingArea
{
	public:
	Face();
	~Face();

	protected:
	bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr) override;
	
	Glib::RefPtr<Gdk::Pixbuf> mImage;
};
#endif
