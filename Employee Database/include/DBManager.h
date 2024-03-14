#ifndef __DBManager_H__
#define __DBManager_H__

#include <iostream>
#include "sqlite3.h"

namespace EmployeeDB {
	class DBManager {
	public:
		static DBManager& instance();
		int executeQuery(const char* queryString);
		int executeSelectQuery(const char* queryString, int (*callback)(void*, int, char**, char**) = DBManager::callback, void* arg = 0);
		static void executeCascadeQuery();

		char* getErrorMessage() const {
			return m_ErrorMessage;
		}
	private:
		DBManager() {
			openConnection();
		}
		~DBManager() {
			closeConnection();
		}
		int openConnection();
		int closeConnection();
		static int callback(void* arg, int argc, char** argv, char** azColName);
		sqlite3* m_DB;
		int m_ResultCode;
		char* m_ErrorMessage;
	};
}
#endif