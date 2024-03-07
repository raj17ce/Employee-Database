#ifndef __DBManager_H__
#define __DBManager_H__

#include <iostream>
#include "sqlite3.h"

namespace EmployeeDB {
	class DBManager {
	public:

		static DBManager& instance();
		int executeQuery(const char*);
		int executeSelectQuery(const char*, int (*)(void*, int, char**, char**) = DBManager::callback, void* = 0);

		static std::string getResultString() {
			return m_ResultString;
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
		static int callback(void*, int, char**, char**);
		sqlite3* m_DB;
		int m_ResultCode;
		char* m_ErrorMessage;
		static inline std::string m_ResultString{""};
	};
}
#endif