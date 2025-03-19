#include "db.h"

void Database::resetInstance() {
	if (instance != nullptr) {
		delete instance;
		instance = nullptr;
	}
}