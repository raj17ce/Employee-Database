#include "ManagerControllerTest.h"
#include "ManagerFixture.h"
#include "ManagerController.h"
#include "DBManager.h"

using EmployeeDB::Controller::ManagerController;
using EmployeeDB::DBManager;

TEST_F(ManagerFixture, insertManagerSuccess) {
	ASSERT_TRUE(ManagerController::insertManager(*manager));

	std::string_view queryString = "SELECT * FROM Manager WHERE managerID = 3;";
	ASSERT_EQ(1, DBManager::instance().executeRowCountQuery(queryString.data()));
}

TEST_F(ManagerFixture, insertManagerFailure) {
	ManagerController::insertManager(*manager);
	ASSERT_FALSE(ManagerController::insertManager(*manager));

	std::string_view queryString = "SELECT * FROM Manager WHERE managerID = 3;";
	ASSERT_EQ(1, DBManager::instance().executeRowCountQuery(queryString.data()));
}

TEST_F(ManagerFixture, selectManagerSuccess) {
	ASSERT_TRUE(ManagerController::selectManager());
	ASSERT_TRUE(ManagerController::selectManager("firstName", "David"));
	ASSERT_TRUE(ManagerController::selectManager("projectTitle", "Project A"));

	std::string_view queryString = "SELECT * FROM Manager";
	ASSERT_EQ(2, DBManager::instance().executeRowCountQuery(queryString.data()));
}

TEST_F(ManagerFixture, selectManagerFailure) {
	ASSERT_FALSE(ManagerController::selectManager("firstNaame", "Devin"));
	ASSERT_FALSE(ManagerController::selectManager("projectTitlee", "Project Z"));

	std::string_view queryString = "SELECT * FROM Manager";
	ASSERT_EQ(2, DBManager::instance().executeRowCountQuery(queryString.data()));
}

TEST_F(ManagerFixture, checkManagerExistenceTrue) {
	ASSERT_TRUE(ManagerController::checkManagerExistence("1"));
	ASSERT_TRUE(ManagerController::checkManagerExistence("2"));
}

TEST_F(ManagerFixture, checkManagerExistenceFalse) {
	ASSERT_FALSE(ManagerController::checkManagerExistence("4"));
	ASSERT_FALSE(ManagerController::checkManagerExistence("-1"));
	ASSERT_FALSE(ManagerController::checkManagerExistence("3"));
	ASSERT_FALSE(ManagerController::checkManagerExistence("10"));
}

TEST_F(ManagerFixture, deleteDepartmentByID) {
	ASSERT_TRUE(ManagerController::deleteManagerByID(1));
	ASSERT_TRUE(ManagerController::deleteManagerByID(2));

	std::string_view queryString = "SELECT * FROM Manager";
	ASSERT_EQ(0, DBManager::instance().executeRowCountQuery(queryString.data()));
}

TEST_F(ManagerFixture, getUpdateQueryConditionEmpty) {
	ASSERT_STREQ("", ManagerControllerTest::getUpdateQueryCondition(*updateManager).c_str());
}

TEST_F(ManagerFixture, getUpdateQueryConditionNonEmpty) {
	updateManager->setTeamSize(20);
	ASSERT_STREQ("teamSize = 20", ManagerControllerTest::getUpdateQueryCondition(*updateManager).c_str());

	updateManager->setProjectTitle("Project Z");
	ASSERT_STREQ("teamSize = 20, projectTitle = \"Project Z\"", ManagerControllerTest::getUpdateQueryCondition(*updateManager).c_str());
}

TEST_F(ManagerFixture, getUpdateQueryConditionMultiple) {

	updateManager->setTeamSize(20);
	updateManager->setProjectTitle("Project Z");
	ASSERT_STREQ("teamSize = 20, projectTitle = \"Project Z\"", ManagerControllerTest::getUpdateQueryCondition(*updateManager).c_str());
}

TEST_F(ManagerFixture, updateManagerSuccess) {

	updateManager->setManagerID(1);
	updateManager->setEmployeeID(1);
	updateManager->setTeamSize(7);
	updateManager->setFirstName("Devin");

	ASSERT_TRUE(ManagerController::updateManager(*updateManager));

	std::string_view queryString = "SELECT * FROM Manager";
	ASSERT_EQ(2, DBManager::instance().executeRowCountQuery(queryString.data()));

	queryString = "SELECT * FROM Manager NATURAL JOIN Employee WHERE firstName = \"David\"";
	ASSERT_EQ(0, DBManager::instance().executeRowCountQuery(queryString.data()));

	queryString = "SELECT * FROM Manager NATURAL JOIN Employee WHERE firstName = \"Devin\" and teamSize = 7;";
	ASSERT_EQ(1, DBManager::instance().executeRowCountQuery(queryString.data()));
}

TEST_F(ManagerFixture, updateManagerFailure) {

	updateManager->setManagerID(1);
	updateManager->setEmployeeID(1);
	updateManager->setEmail("sarah.wilson@example.com");

	ASSERT_FALSE(ManagerController::updateManager(*updateManager));
}