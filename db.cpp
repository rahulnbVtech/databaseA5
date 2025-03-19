#include "db.h"

Database* Database::instance = nullptr;

void Database::resetInstance() {
	if (instance != nullptr) {
		delete instance;
		instance = nullptr;
	}
}