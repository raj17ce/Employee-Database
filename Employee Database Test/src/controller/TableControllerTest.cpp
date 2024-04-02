#include "TableControllerTest.h"
#include "TableController.h"
#include "TableFixture.h"
#include "DBManager.h"

using EmployeeDB::Controller::TableController;
using EmployeeDB::DBManager;

TEST_F(TableFixture, getCreateTableQueryEmpty) {
	ASSERT_STREQ("CREATE TABLE \"Roles\" ();", TableControllerTest::getCreateTableQuery(*emptyTable).c_str());
}

TEST_F(TableFixture, getCreateTableQuery) {
	ASSERT_STREQ("CREATE TABLE \"Dpt\" (\"ID\" INT NOT NULL UNIQUE PRIMARY KEY, \"DepartmentName\" TEXT NOT NULL, \"teamSize\" INT , FOREIGN KEY (\"DepartmentName\") REFERENCES \"Department\"(\"departmentName\") ON DELETE CASCADE);", TableControllerTest::getCreateTableQuery(*table).c_str());
}

TEST_F(TableFixture, createTableSuccess) {
	ASSERT_TRUE(TableController::createTable(*table));

	std::string_view queryString = "SELECT * FROM sqlite_schema WHERE name = \"Dpt\";";
	ASSERT_EQ(1, DBManager::instance().executeRowCountQuery(queryString.data()));
}

TEST_F(TableFixture, createTableFailure) {
	ASSERT_FALSE(TableController::createTable(*emptyTable));

	std::string_view queryString = "SELECT * FROM sqlite_schema WHERE name = \"Roles\";";
	ASSERT_EQ(0, DBManager::instance().executeRowCountQuery(queryString.data()));
}

TEST_F(TableFixture, deleteTableSuccess) {
	ASSERT_TRUE(TableController::createTable(*table));

	std::string_view queryString = "SELECT * FROM sqlite_schema WHERE name = \"Dpt\";";
	ASSERT_EQ(1, DBManager::instance().executeRowCountQuery(queryString.data()));

	ASSERT_TRUE(TableController::deleteTable("Dpt"));

	queryString = "SELECT * FROM sqlite_schema WHERE name = \"Dpt\";";
	ASSERT_EQ(0, DBManager::instance().executeRowCountQuery(queryString.data()));
}

TEST_F(TableFixture, deleteTableFailure) {
	ASSERT_FALSE(TableController::deleteTable("Roles"));

	std::string_view queryString = "SELECT * FROM sqlite_schema WHERE name = \"Roles\";";
	ASSERT_EQ(0, DBManager::instance().executeRowCountQuery(queryString.data()));
}