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
	int tempResultCode = sqlite3_open(EmployeeDB::Config::DbFilePath, &m_DB);

	if (tempResultCode == SQLITE_OK) {
		std::cerr << "Successfully opened DB connection" << '\n';
	}
	else {
		m_ErrorMessage = const_cast<char*>("Error opening DB Connection");
		throw std::runtime_error{ "Error opening DB Connection" };
	}
	m_ResultCode = tempResultCode;
	return tempResultCode;
}

int DBManager::closeConnection() {
	int tempResultCode = sqlite3_close(m_DB);

	if (tempResultCode == SQLITE_OK) {
		std::cerr << "Successfully closed DB connection" << '\n';
	}
	else {
		m_ErrorMessage = const_cast<char*>("Error opening DB Connection");
		throw std::runtime_error{ "Error closing DB Connection" };
	}
	m_ResultCode = tempResultCode;
	return tempResultCode;
}