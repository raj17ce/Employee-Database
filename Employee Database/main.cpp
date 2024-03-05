#include <iostream>
#include "sqlite3.h"

int main() {
	sqlite3* db;
	int status = 0;
	char* errMsg = 0;

	status = sqlite3_open("Employee.db", &db);

	if (status) {
		std::cerr << "Error creating DB file" << sqlite3_errmsg(db) << '\n';
		return -1;
	}
	else {
		std::cout << "Created database file successfully" << '\n';
	}

	const char* createQueryString = "CREATE TABLE Employee("
		"ID				INT		PRIMARY KEY     NOT NULL,"
		"NAME           TEXT    NOT NULL,"
		"AGE            INT     NOT NULL,"
		"ADDRESS        CHAR(50),"
		"SALARY         REAL );";

	status = sqlite3_exec(db, createQueryString, 0, 0, &errMsg);

	if (status != SQLITE_OK) {
		std::cerr << "SQL error: " << errMsg << std::endl;
		sqlite3_free(errMsg);
	}
	else {
		std::cout << "Table created successfully" << std::endl;
	}

	const char* insertQueryString = "INSERT INTO Employee (ID, NAME, AGE, ADDRESS, SALARY) "
		"VALUES (1, 'Raj Patel', 17, 'Valsad, Gujarat, India', 50000.0 ); "
		"INSERT INTO COMPANY (ID, NAME, AGE, ADDRESS, SALARY) "
		"VALUES (2, 'Rishi Gandhi', 34, 'Surat, Gujarat, India', 50000.0 );";

	status = sqlite3_exec(db, insertQueryString, 0, 0, &errMsg);

	if (status != SQLITE_OK) {
		std::cerr << "SQL error: " << errMsg << std::endl;
		sqlite3_free(errMsg);
	}
	else {
		std::cout << "Records inserted successfully" << std::endl;
	}

	sqlite3_close(db);
	return 0;
}