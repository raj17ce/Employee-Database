#ifndef __DBManager_H__
#define __DBManager_H__

#include "sqlite3.h"

namespace EmployeeDB {
	class DBManager {
	public:
		DBManager() {
			openConnection();
		}

		~DBManager() {
			closeConnection();
		}

		static DBManager& instance();
		int openConnection();
		int closeConnection();
	private:
		sqlite3* m_DB;
		int m_ResultCode;
		char* m_ErrorMessage;
	};
}
#endif