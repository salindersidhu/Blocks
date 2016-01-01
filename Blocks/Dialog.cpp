#include "Dialog.hpp"

Dialog::Dialog(string title) {
	dialogTitle = title;
}

void Dialog::messageDialog(string message) {
	tinyfd_messageBox(dialogTitle.c_str(), message.c_str(), "ok", "info", 1);
}

void Dialog::errorDialog(string message) {
	tinyfd_messageBox(dialogTitle.c_str(), message.c_str(), "ok", "error", 1);
}
