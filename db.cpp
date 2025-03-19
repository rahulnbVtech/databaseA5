#include "db.h"

Database* Database::instance = nullptr;


/*
* resetting the instance
*/
void Database::resetInstance() {
	if (instance != nullptr) {
		delete instance;
		instance = nullptr;
	}
}