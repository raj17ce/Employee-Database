#include "EngineerController.h"
#include "EngineerControllerTest.h"
#include "EngineerFixture.h"
#include "DBManager.h"

using EmployeeDB::Controller::EngineerController;
using EmployeeDB::DBManager;

TEST_F(EngineerFixture, insertEngineerSuccess) {
	ASSERT_TRUE(EngineerController::insertEngineer(*engineer));

	std::string_view queryString = "SELECT * FROM Employee NATURAL JOIN Engineer WHERE firstName = \"John\" and technology = \"CPP\";";
	ASSERT_EQ(1, DBManager::instance().executeRowCountQuery(queryString.data()));
}

TEST_F(EngineerFixture, insertEngineerFailure) {
	ASSERT_TRUE(EngineerController::insertEngineer(*engineer));
	ASSERT_FALSE(EngineerController::insertEngineer(*engineer));

	std::string_view queryString = "SELECT * FROM Employee NATURAL JOIN Engineer WHERE firstName = \"John\" and technology = \"CPP\";";
	ASSERT_EQ(1, DBManager::instance().executeRowCountQuery(queryString.data()));
}

TEST_F(EngineerFixture, selectEngineerSuccess) {
	ASSERT_TRUE(EngineerController::selectEngineer());
	ASSERT_TRUE(EngineerController::selectEngineer("firstName", "David"));
	ASSERT_TRUE(EngineerController::selectEngineer("technology", "Python"));

	std::string_view queryString = "SELECT * FROM Engineer;";
	ASSERT_EQ(2, DBManager::instance().executeRowCountQuery(queryString.data()));
}

TEST_F(EngineerFixture, selectEngineerFailure) {
	ASSERT_FALSE(EngineerController::selectEngineer("firstNamme", "Devin"));
	ASSERT_FALSE(EngineerController::selectEngineer("bonuss", "65000"));

	std::string_view queryString = "SELECT * FROM Engineer;";
	ASSERT_EQ(2, DBManager::instance().executeRowCountQuery(queryString.data()));
}

TEST_F(EngineerFixture, deleteEngineerByID) {
	ASSERT_TRUE(EngineerController::deleteEngineerByID(1));
	ASSERT_TRUE(EngineerController::deleteEngineerByID(2));

	std::string_view queryString = "SELECT * FROM Engineer";
	ASSERT_EQ(0, DBManager::instance().executeRowCountQuery(queryString.data()));
}

TEST_F(EngineerFixture, getUpdateQueryConditionEmpty) {
	ASSERT_STREQ("", EngineerControllerTest::getUpdateQueryCondition(*updateEngineer).c_str());
}

TEST_F(EngineerFixture, getUpdateQueryConditionNonEmpty) {
	updateEngineer->setTechnology("CPP");
	ASSERT_STREQ("technology = \"CPP\"", EngineerControllerTest::getUpdateQueryCondition(*updateEngineer).c_str());
}

TEST_F(EngineerFixture, updateEngineerSuccess) {

	updateEngineer->setEmployeeID(1);
	updateEngineer->setFirstName("Devin");

	ASSERT_TRUE(EngineerController::updateEngineer(*updateEngineer));

	std::string_view queryString = "SELECT * FROM Engineer";
	ASSERT_EQ(2, DBManager::instance().executeRowCountQuery(queryString.data()));

	queryString = "SELECT * FROM Employee NATURAL JOIN Engineer WHERE firstName = \"David\"";
	ASSERT_EQ(0, DBManager::instance().executeRowCountQuery(queryString.data()));

	queryString = "SELECT * FROM Employee NATURAL JOIN Engineer WHERE firstName = \"Devin\"";
	ASSERT_EQ(1, DBManager::instance().executeRowCountQuery(queryString.data()));
}

TEST_F(EngineerFixture, updateEngineerFailure) {

	updateEngineer->setEmployeeID(2);
	updateEngineer->setEmail("david.brown@example.com");

	ASSERT_FALSE(EngineerController::updateEngineer(*updateEngineer));
}