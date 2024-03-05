#include <iostream>
#include "sqlite3.h"
#include "DBManager.h"

using EmployeeDB::DBManager;

int main() {
	DBManager& db = DBManager::instance();

	const char* createQueryString = "CREATE TABLE IF NOT EXISTS Employee("
		"ID				INT		PRIMARY KEY     NOT NULL,"
		"NAME           TEXT    NOT NULL,"
		"AGE            INT     NOT NULL,"
		"ADDRESS        CHAR(50),"
		"SALARY         REAL );";

	db.executeQuery(createQueryString);

	//const char* insertQueryString = "INSERT INTO Employee (ID, NAME, AGE, ADDRESS, SALARY) "
	//	"VALUES (1, 'Raj Patel', 17, 'Valsad, Gujarat, India', 50000.0 ); "
	//	"INSERT INTO Employee (ID, NAME, AGE, ADDRESS, SALARY) "
	//	"VALUES (2, 'Rishi Gandhi', 34, 'Surat, Gujarat, India', 50000.0 );";

	//db.executeQuery(insertQueryString);

	const char* selectQueryString = "Select * from Employee";

	db.executeSelectQuery(selectQueryString);

	std::cout << db.getResultString();

	return 0;
}