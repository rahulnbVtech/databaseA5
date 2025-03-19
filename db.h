#ifndef DATABASE
#define DATABASE

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

	/*
	* this is the constructor for the database
	*/
	Database(const std::string& database, const std::string& username, const std::string& password)
		: db(database), username(username), password(password) {

	}

public:

	/*
	* destructor
	*/
	~Database() {
		if (connected) {
			disconnect();
		}
	}


	/*
	* method that creates and returns an instance of the database
	*/
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

	/*
	* function that sets connect to true
	*/
	void connect() {
		connected = true;
	}

	/*
	* function that sets connect to false
	*/
	void disconnect() {
		connected = false;
	}

	/*
	* function that returns the value of connected
	*/
	bool isConnected() const {
		return connected;
	}

	/*
	function that sets username
	*/
	void set_username(const std::string& newUsername) {
		username = newUsername;
	}

	/*
	function that gets username
	*/
	std::string get_username() const{
		return username;
	}

	/*
	function that sets password
	*/
	void set_password(const std::string& newPassword) {
		password = newPassword;
	}

	/*
	function that gets password
	*/
	std::string get_password() const {
		return password;
	}

	/*
	* method overloading the new operator
	*/
	void* operator new(size_t size) {
		std::cout << "overloaded new ";

		void* pointer = malloc(size);
		if (!pointer) {
			throw std::bad_alloc();
		}

		return pointer;
	}

	/*
	* method overloading the delete operator
	*/
	void operator delete(void* pointer) {
		std::cout << "overloaded delete ";
		free(pointer);
	}

	/*
	* resetting the instance 
	*/
	static void resetInstance();
		

};

#endif