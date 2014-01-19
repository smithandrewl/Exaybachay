#include <gtkmm.h>
#include <string>
#include <vector>

#include "textgenerator.h"

using std::string;

using Glib::RefPtr;
using Gtk::ApplicationWindow;
using Gtk::TextView;
using Gtk::FileChooserButton;
using Gtk::TextBuffer;
using Gtk::Button;
using Gtk::Application;
using Gtk::Builder;
using Gtk::SpinButton;

TextGenerator generator;

// --------- Widgets ----------------
ApplicationWindow* pWindow       = 0;
TextView*          textView      = 0;
FileChooserButton* chooseButton  = 0;
SpinButton*        spinButton    = 0;
Button*            executeButton = 0;	
// ----------------------------------

// --------- Event Handlers --------
void execute() {
	string output;

	auto   buffer        = textView->get_buffer();
	int    numberOfWords = spinButton->get_value_as_int();

	for(string word : generator.generate(numberOfWords))
		output.append(word + ' ');

	buffer->set_text(output);
}

void fileSelected() {
	string filename = chooseButton->get_filename();

	executeButton->set_sensitive(true);
	generator.init(filename);
}
// ---------------------------------

int main(int argc, char** argv) {

	RefPtr<Application> app        = Application::create(argc, argv, "");
	RefPtr<Builder>     refBuilder = Builder::create();

	refBuilder->add_from_file("gui.glade");
	refBuilder->get_widget("applicationwindow", pWindow);

	if(pWindow) {
		refBuilder->get_widget("executeButton", executeButton);
		refBuilder->get_widget("chooseButton",  chooseButton);
 		refBuilder->get_widget("textView",      textView);
 		refBuilder->get_widget("spinButton",    spinButton);
		
		executeButton->signal_clicked().connect(sigc::ptr_fun(execute));
		chooseButton->signal_file_set().connect(sigc::ptr_fun(fileSelected));

		app->run(*pWindow);
	}

	delete pWindow;
	
	return 0;	
}