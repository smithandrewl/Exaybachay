#include <gtkmm.h>
#include <string>
#include <vector>

using std::string;

using Glib::RefPtr;
using Gtk::ApplicationWindow;
using Gtk::TextView;
using Gtk::FileChooserButton;
using Gtk::TextBuffer;
using Gtk::Button;
using Gtk::Application;
using Gtk::Builder;

// --------- Widgets ---------------
ApplicationWindow* pWindow      = 0;
TextView*          textView     = 0;
FileChooserButton* chooseButton = 0;
// ---------------------------------

// --------- Event Handlers --------
void execute() {}
void fileSelected() {}
// ---------------------------------

int main(int argc, char** argv) {
	Button* executeButton = 0;	

	RefPtr<Application> app        = Application::create(argc, argv, "");
	RefPtr<Builder>     refBuilder = Builder::create();

	refBuilder->add_from_file("henley.glade");
	refBuilder->get_widget("applicationwindow", pWindow);

	if(pWindow) {
		refBuilder->get_widget("executeButton", executeButton);
		refBuilder->get_widget("chooseButton",  chooseButton);
 		refBuilder->get_widget("textView",      textView);

		executeButton->signal_clicked().connect(sigc::ptr_fun(execute));
		chooseButton->signal_file_set().connect(sigc::ptr_fun(fileSelected));

		app->run(*pWindow);
	}

	delete pWindow;
	
	return 0;	
}