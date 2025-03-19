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


	Database(const std::string& database, const std::string& username, const std::string& password);

public:
	~Database() {
		if (connected) {
			disconnect();
		}
	}

	Database* getInstance(const std::string& databaseName, const std::string& username, const std::string& password) {
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

	bool connectStatus() const {
		return connected;
	}

	void set_username(std::string username) {
		this.username = username;
	}

	std::string get_username() const{
		return username;
	}

	void set_password(std::string password) {
		this.password = password;
	}

	std::string get_password() const {
		return password;
	}

	static void resetInstance();
		

};