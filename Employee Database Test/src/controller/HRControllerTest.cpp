#include "HRController.h"
#include "HRControllerTest.h"
#include "HRFixture.h"
#include "DBManager.h"

using EmployeeDB::Controller::HRController;
using EmployeeDB::DBManager;

TEST_F(HRFixture, insertHRSuccess) {
	ASSERT_TRUE(HRController::insertHR(*hr));

	std::string_view queryString = "SELECT * FROM Employee NATURAL JOIN HR WHERE firstName = \"Michael\" and hrSpecialization = \"Recruitment\";";
	ASSERT_EQ(1, DBManager::instance().executeRowCountQuery(queryString.data()));
}

TEST_F(HRFixture, insertHRFailure) {
	ASSERT_TRUE(HRController::insertHR(*hr));
	ASSERT_FALSE(HRController::insertHR(*hr));

	std::string_view queryString = "SELECT * FROM Employee NATURAL JOIN HR WHERE firstName = \"Michael\" and hrSpecialization = \"Recruitment\";";
	ASSERT_EQ(1, DBManager::instance().executeRowCountQuery(queryString.data()));
}

TEST_F(HRFixture, selectHRSuccess) {
	ASSERT_TRUE(HRController::selectHR());
	ASSERT_TRUE(HRController::selectHR("firstName", "David"));
	ASSERT_TRUE(HRController::selectHR("hrSpecialization", "Human Resource"));

	std::string_view queryString = "SELECT * FROM HR;";
	ASSERT_EQ(2, DBManager::instance().executeRowCountQuery(queryString.data()));
}

TEST_F(HRFixture, selectHRFailure) {
	ASSERT_FALSE(HRController::selectHR("firstNamme", "Devin"));
	ASSERT_FALSE(HRController::selectHR("bonuss", "65000"));

	std::string_view queryString = "SELECT * FROM HR;";
	ASSERT_EQ(2, DBManager::instance().executeRowCountQuery(queryString.data()));
}

TEST_F(HRFixture, deleteHRByID) {
	ASSERT_TRUE(HRController::deleteHRByID(1));
	ASSERT_TRUE(HRController::deleteHRByID(2));

	std::string_view queryString = "SELECT * FROM HR";
	ASSERT_EQ(0, DBManager::instance().executeRowCountQuery(queryString.data()));
}

TEST_F(HRFixture, getUpdateQueryConditionEmpty) {
	ASSERT_STREQ("", HRControllerTest::getUpdateQueryCondition(*updateHr).c_str());
}

TEST_F(HRFixture, getUpdateQueryConditionNonEmpty) {
	updateHr->setHRSpecialization("Resource");
	ASSERT_STREQ("hrSpecialization = \"Resource\"", HRControllerTest::getUpdateQueryCondition(*updateHr).c_str());
}

TEST_F(HRFixture, updateHRSuccess) {

	updateHr->setEmployeeID(1);
	updateHr->setFirstName("Devin");

	ASSERT_TRUE(HRController::updateHR(*updateHr));

	std::string_view queryString = "SELECT * FROM HR";
	ASSERT_EQ(2, DBManager::instance().executeRowCountQuery(queryString.data()));

	queryString = "SELECT * FROM Employee NATURAL JOIN HR WHERE firstName = \"David\"";
	ASSERT_EQ(0, DBManager::instance().executeRowCountQuery(queryString.data()));

	queryString = "SELECT * FROM Employee NATURAL JOIN HR WHERE firstName = \"Devin\"";
	ASSERT_EQ(1, DBManager::instance().executeRowCountQuery(queryString.data()));
}

TEST_F(HRFixture, updateHRFailure) {

	updateHr->setEmployeeID(2);
	updateHr->setEmail("david.brown@example.com");

	ASSERT_FALSE(HRController::updateHR(*updateHr));
}