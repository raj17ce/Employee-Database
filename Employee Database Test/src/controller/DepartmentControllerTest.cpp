#include "DepartmentControllerTest.h"
#include "DepartmentFixture.h"
#include "DepartmentController.h"
#include "DBManager.h"

using EmployeeDB::Controller::DepartmentController;
using EmployeeDB::DBManager;

TEST_F(DepartmentFixture, insertDepartmentSuccess) {
	ASSERT_TRUE(DepartmentController::insertDepartment(*department));

	std::string_view queryString = "SELECT * FROM Department WHERE departmentName = \"Marketing\";";
	ASSERT_EQ(1, DBManager::instance().executeRowCountQuery(queryString.data()));
}

TEST_F(DepartmentFixture, insertDepartmentFailure) {
	DepartmentController::insertDepartment(*department);
	ASSERT_FALSE(DepartmentController::insertDepartment(*department));

	std::string_view queryString = "SELECT * FROM Department WHERE departmentName = \"Marketing\";";
	ASSERT_EQ(1, DBManager::instance().executeRowCountQuery(queryString.data()));
}

TEST_F(DepartmentFixture, getDepartmentIDbyNameSuccess) {
	ASSERT_EQ(1, DepartmentController::getDepartmentIDbyName("Engineer"));
	ASSERT_EQ(2, DepartmentController::getDepartmentIDbyName("Finance"));
	ASSERT_EQ(3, DepartmentController::getDepartmentIDbyName("HR"));
	ASSERT_EQ(4, DepartmentController::getDepartmentIDbyName("QA"));
}

TEST_F(DepartmentFixture, getDepartmentIDbyNameFailure) {
	ASSERT_EQ(-1, DepartmentController::getDepartmentIDbyName("Enggineer"));
	ASSERT_EQ(-1, DepartmentController::getDepartmentIDbyName("Marketing"));
	ASSERT_EQ(-1, DepartmentController::getDepartmentIDbyName("R&D"));
	ASSERT_EQ(-1, DepartmentController::getDepartmentIDbyName("QAa"));
}

TEST_F(DepartmentFixture, checkDepartmentExistenceTrue) {
	ASSERT_TRUE(DepartmentController::checkDepartmentExistence("1"));
	ASSERT_TRUE(DepartmentController::checkDepartmentExistence("2"));
	ASSERT_TRUE(DepartmentController::checkDepartmentExistence("3"));
	ASSERT_TRUE(DepartmentController::checkDepartmentExistence("4"));
}

TEST_F(DepartmentFixture, checkDepartmentExistenceFalse) {
	ASSERT_FALSE(DepartmentController::checkDepartmentExistence("10"));
	ASSERT_FALSE(DepartmentController::checkDepartmentExistence("-1"));
	ASSERT_FALSE(DepartmentController::checkDepartmentExistence("50"));
	ASSERT_FALSE(DepartmentController::checkDepartmentExistence("47"));
}

TEST_F(DepartmentFixture, selectDepartmentSuccess) {
	ASSERT_TRUE(DepartmentController::selectDepartment());
	ASSERT_TRUE(DepartmentController::selectDepartment("departmentName", "Engineer"));
	ASSERT_TRUE(DepartmentController::selectDepartment("baseSalary", "65000"));

	std::string_view queryString = "SELECT * FROM Department";
	ASSERT_EQ(4, DBManager::instance().executeRowCountQuery(queryString.data()));
}

TEST_F(DepartmentFixture, selectDepartmentFailure) {
	ASSERT_FALSE(DepartmentController::selectDepartment("departmenttName", "Engineer"));
	ASSERT_FALSE(DepartmentController::selectDepartment("baseSalaryyy", "65000"));

	std::string_view queryString = "SELECT * FROM Department";
	ASSERT_EQ(4, DBManager::instance().executeRowCountQuery(queryString.data()));
}

TEST_F(DepartmentFixture, deleteDepartmentByID) {
	ASSERT_TRUE(DepartmentController::deleteDepartmentByID(1));
	ASSERT_TRUE(DepartmentController::deleteDepartmentByID(2));
	ASSERT_TRUE(DepartmentController::deleteDepartmentByID(3));
	ASSERT_TRUE(DepartmentController::deleteDepartmentByID(4));

	std::string_view queryString = "SELECT * FROM Department";
	ASSERT_EQ(0, DBManager::instance().executeRowCountQuery(queryString.data()));
}

TEST_F(DepartmentFixture, getUpdateQueryConditionEmpty) {
	ASSERT_STREQ("", DepartmentControllerTest::getUpdateQueryCondition(*updateDepartment).c_str());
}

TEST_F(DepartmentFixture, getUpdateQueryConditionNonEmpty) {
	updateDepartment->setDepartmentName("Marketing");
	ASSERT_STREQ("departmentName = \"Marketing\"", DepartmentControllerTest::getUpdateQueryCondition(*updateDepartment).c_str());

	updateDepartment->setAllowance(5000.00);
	ASSERT_STREQ("departmentName = \"Marketing\", allowance = 5000.000000", DepartmentControllerTest::getUpdateQueryCondition(*updateDepartment).c_str());

	updateDepartment->setDepartmentName("R&D");
	ASSERT_STREQ("departmentName = \"R&D\", allowance = 5000.000000", DepartmentControllerTest::getUpdateQueryCondition(*updateDepartment).c_str());
}

TEST_F(DepartmentFixture, updateDepartmentSuccess) {

	updateDepartment->setDepartmentID(1);
	updateDepartment->setDepartmentName("Engineering");

	ASSERT_TRUE(DepartmentController::updateDepartment(*updateDepartment));

	std::string_view queryString = "SELECT * FROM Department";
	ASSERT_EQ(4, DBManager::instance().executeRowCountQuery(queryString.data()));

	queryString = "SELECT * FROM Department WHERE departmentName = \"Engineer\"";
	ASSERT_EQ(0, DBManager::instance().executeRowCountQuery(queryString.data()));

	queryString = "SELECT * FROM Department WHERE departmentName = \"Engineering\"";
	ASSERT_EQ(1, DBManager::instance().executeRowCountQuery(queryString.data()));
}

TEST_F(DepartmentFixture, updateDepartmentFailure) {

	updateDepartment->setDepartmentID(4);
	updateDepartment->setDepartmentName("Engineer");

	ASSERT_FALSE(DepartmentController::updateDepartment(*updateDepartment));
}