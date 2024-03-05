#include <iostream>
#include <exception>
#include "Config.h"
#include "DBManager.h"

using EmployeeDB::DBManager;

DBManager& DBManager::instance() {
	static DBManager dbManager;
	return dbManager;
}

int DBManager::openConnection() {
	m_ResultCode = sqlite3_open(EmployeeDB::Config::DbFilePath, &m_DB);

	if (m_ResultCode == SQLITE_OK) {
		std::cout << "Successfully opened DB connection" << '\n';
	}
	else {
		std::cerr << "Error opening DB connection" << '\n';
	}
	return m_ResultCode;
}

int DBManager::closeConnection() {
	m_ResultCode = sqlite3_close(m_DB);

	if (m_ResultCode == SQLITE_OK) {
		std::cout << "Successfully closed DB connection" << '\n';
	}
	else {
		std::cerr << "Error closing DB connection" << '\n';
	}
	return m_ResultCode;
}

int DBManager::executeQuery(const char* queryString) {
	m_ResultCode = sqlite3_exec(m_DB, queryString, 0, 0, &m_ErrorMessage);

	if (m_ResultCode == SQLITE_OK) {
		std::cout << "Successfully executed Query" << '\n';
	}
	else {
		throw std::runtime_error{ m_ErrorMessage };
	}

	return m_ResultCode;
}

int DBManager::callback(void* NotUsed, int argc, char** argv, char** azColName) {
	int i;
	for (i = 0; i < argc; i++) {
		m_ResultString += azColName[i] + std::string{ " : " } + (argv[i] ? argv[i] : "NULL") + "\n";
	}
	std::cout<<'\n';
	return 0;
}

int DBManager::executeSelectQuery(const char* queryString) {
	m_ResultCode = sqlite3_exec(m_DB, queryString, callback, 0, &m_ErrorMessage);

	if (m_ResultCode == SQLITE_OK) {
		std::cout << "Successfully executed Query" << '\n';
	}
	else {
		throw std::runtime_error{ m_ErrorMessage };
	}

	return m_ResultCode;
}