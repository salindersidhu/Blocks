#ifndef DIALOGMANAGER_HPP
#define DIALOGMANAGER_HPP

#include <string>
#include "tinyfiledialogs.h"
using namespace std;

class DialogManager {
	public:
        // Constructor and destructor
		DialogManager(string);
		virtual ~DialogManager() {};
		void message(string);
		void error(string);
	private:
		string dialogTitle;
};

#endif
