#include "DialogManager.hpp"

DialogManager::DialogManager(string title) {
	dialogTitle = title;
}

void DialogManager::message(string message) {
	tinyfd_messageBox(dialogTitle.c_str(), message.c_str(), "ok", "info", 1);
}

void DialogManager::error(string message) {
	tinyfd_messageBox(dialogTitle.c_str(), message.c_str(), "ok", "error", 1);
}
