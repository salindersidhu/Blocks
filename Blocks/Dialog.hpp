#ifndef DIALOG_HPP
#define DIALOG_HPP

#include <string>
#include "tinyfiledialogs.h"
using namespace std;

class Dialog {
	public:
		Dialog(string); // Constructor
		virtual ~Dialog() {}; // Destructor
		void messageDialog(string);
		void errorDialog(string);
	private:
		string dialogTitle;
};

#endif