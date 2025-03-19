#include <iostream>
#include <stdexcept>
#include <string>

class Database {
private:
	std::string db;
	std::string username;
	std::string password;

	bool connected{ false };

	static Database* instance;


	Database(const std::string& database, const std::string& username, const std::string& password)
		: db(database), username(username), password(password) {

	}

public:
	~Database() {
		if (connected) {
			disconnect();
		}
	}

	static Database* getInstance(const std::string& databaseName, const std::string& username, const std::string& password) {
		if (instance == nullptr) {
			instance = new Database(databaseName, username, password);
		}
		else {
			if (instance->db != databaseName || instance->username != username || instance->password != password) {
				throw std::runtime_error("invalid database name, username or password");
			}
		}
		return instance;
	}

	void connect() {
		connected = true;
	}

	void disconnect() {
		connected = false;
	}

	bool isConnected() const {
		return connected;
	}

	void set_username(const std::string& newUsername) {
		username = newUsername;
	}

	std::string get_username() const{
		return username;
	}

	void set_password(const std::string& newPassword) {
		password = newPassword;
	}

	std::string get_password() const {
		return password;
	}

	void* operator new(size_t size) {
		std::count << "Overloaded new ";

		void* pointer = malloc(size);
		if (!pointer) {
			throw std::bad_alloc();
		}

		return pointer;
	}

	void operator delete(void* pointer) {
		std::cout << "Overloaded delete ";
		free(pointer);
	}

	static void resetInstance();
		

};