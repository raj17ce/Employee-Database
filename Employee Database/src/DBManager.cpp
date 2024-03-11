#include <iostream>
#include <iomanip>
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

int DBManager::callback(void* notUsed, int argc, char** argv, char** azColName) {
	std::cout << "|--------------------|----------------------------------------|\n";
	int i;
	for (i = 0; i < argc; i++) {
		std::cout << "|" << std::setw(20) << std::left << azColName[i] << "|" << std::setw(40) << std::left << (argv[i] ? argv[i] : "NULL") << "|\n";
	}
	std::cout << "|--------------------|----------------------------------------|\n";
	std::cout << std::endl;
	return 0;
}

int DBManager::executeSelectQuery(const char* queryString, int (*callback)(void*, int, char**, char**), void* arg) {
	m_ResultCode = sqlite3_exec(m_DB, queryString, callback, arg, &m_ErrorMessage);

	if (m_ResultCode == SQLITE_OK) {
		std::cout << "Successfully executed Query" << '\n';
	}
	else {
		throw std::runtime_error{ m_ErrorMessage };
	}

	return m_ResultCode;
}