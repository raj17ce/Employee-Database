#include "EmployeeController.h"
#include "EmployeeControllerTest.h"
#include "EmployeeFixture.h"
#include "SalaryFixture.h"
#include "DBManager.h"
#include "Salary.h"

using EmployeeDB::Controller::EmployeeController;
using EmployeeDB::Model::Salary;
using EmployeeDB::DBManager;

TEST_F(EmployeeFixture, insertEmployeeSuccess) {
	ASSERT_TRUE(EmployeeController::insertEmployee(*employee));

	std::string_view queryString = "SELECT * FROM Employee WHERE firstName = \"John\";";
	ASSERT_EQ(1, DBManager::instance().executeRowCountQuery(queryString.data()));
}

TEST_F(EmployeeFixture, insertEmployeeFailure) {
	ASSERT_TRUE(EmployeeController::insertEmployee(*employee));
	ASSERT_FALSE(EmployeeController::insertEmployee(*employee));

	std::string_view queryString = "SELECT * FROM Employee WHERE firstName = \"John\";";
	ASSERT_EQ(1, DBManager::instance().executeRowCountQuery(queryString.data()));
}

TEST_F(EmployeeFixture, getEmployeeIDbyEmailSuccess) {
	ASSERT_EQ(1, EmployeeController::getEmployeeIDbyEmail("david.brown@example.com"));
	ASSERT_EQ(2, EmployeeController::getEmployeeIDbyEmail("sarah.wilson@example.com"));
	ASSERT_EQ(3, EmployeeController::getEmployeeIDbyEmail("chris.martinez@example.com"));
	ASSERT_EQ(4, EmployeeController::getEmployeeIDbyEmail("jessica.taylor@example.com"));
}

TEST_F(EmployeeFixture, getEmployeeIDbyEmailFailure) {
	ASSERT_EQ(-1, EmployeeController::getEmployeeIDbyEmail("david.berrown@example.com"));
	ASSERT_EQ(-1, EmployeeController::getEmployeeIDbyEmail("sarah.wilefson@example.com"));
	ASSERT_EQ(-1, EmployeeController::getEmployeeIDbyEmail("chris.martinez@exeample.com"));
	ASSERT_EQ(-1, EmployeeController::getEmployeeIDbyEmail("jessica.tawsylor@example.com"));
}

TEST_F(EmployeeFixture, getDepartmentIDbyEmployeeIDSuccess) {
	ASSERT_EQ(1, EmployeeController::getDepartmentIDbyEmployeeID(1));
	ASSERT_EQ(2, EmployeeController::getDepartmentIDbyEmployeeID(2));
	ASSERT_EQ(3, EmployeeController::getDepartmentIDbyEmployeeID(3));
	ASSERT_EQ(4, EmployeeController::getDepartmentIDbyEmployeeID(4));
}

TEST_F(EmployeeFixture, getDepartmentIDbyEmployeeIDFailure) {
	ASSERT_EQ(-1, EmployeeController::getDepartmentIDbyEmployeeID(5));
	ASSERT_EQ(-1, EmployeeController::getDepartmentIDbyEmployeeID(50));
	ASSERT_EQ(-1, EmployeeController::getDepartmentIDbyEmployeeID(25));
	ASSERT_EQ(-1, EmployeeController::getDepartmentIDbyEmployeeID(8));
}

TEST_F(EmployeeFixture, checkEmployeeExistenceSuccess) {
	ASSERT_TRUE(EmployeeController::checkEmployeeExistence("1", "Engineer"));
	ASSERT_TRUE(EmployeeController::checkEmployeeExistence("2", "Finance"));
	ASSERT_TRUE(EmployeeController::checkEmployeeExistence("3", "HR"));
	ASSERT_TRUE(EmployeeController::checkEmployeeExistence("4", "QA"));
	ASSERT_TRUE(EmployeeController::checkEmployeeExistence("4", "*"));
}

TEST_F(EmployeeFixture, checkEmployeeExistenceFailure) {
	ASSERT_FALSE(EmployeeController::checkEmployeeExistence("1", "Finance"));
	ASSERT_FALSE(EmployeeController::checkEmployeeExistence("10", "Engineer"));
	ASSERT_FALSE(EmployeeController::checkEmployeeExistence("2", "HR"));
	ASSERT_FALSE(EmployeeController::checkEmployeeExistence("-1", "QA"));
}

TEST_F(EmployeeFixture, deleteEmployeeByID) {
	ASSERT_TRUE(EmployeeController::deleteEmployeeByID(1));
	ASSERT_TRUE(EmployeeController::deleteEmployeeByID(2));
	ASSERT_TRUE(EmployeeController::deleteEmployeeByID(3));
	ASSERT_TRUE(EmployeeController::deleteEmployeeByID(4));

	std::string_view queryString = "SELECT * FROM Employee";
	ASSERT_EQ(0, DBManager::instance().executeRowCountQuery(queryString.data()));
}

TEST_F(EmployeeFixture, getSalaryDetailsSuccess) {
	std::shared_ptr<Salary> salary = std::make_shared<Salary>();
	salary->setEmployeeID(1);
	salary->setDepartmentID(1);

	ASSERT_TRUE(EmployeeController::getSalaryDetails(*salary));

	ASSERT_EQ(0.78, salary->getPerformanceMetric());
	ASSERT_EQ(450.00, salary->getBonus());
	ASSERT_EQ(65000.00, salary->getBaseSalary());
	ASSERT_EQ(7000.00, salary->getAllowance());
	ASSERT_EQ(3000.00, salary->getDeduction());
}

TEST_F(EmployeeFixture, getSalaryDetailsFailure) {
	std::shared_ptr<Salary> salary = std::make_shared<Salary>();
	salary->setEmployeeID(1);
	salary->setDepartmentID(1);

	ASSERT_TRUE(EmployeeController::getSalaryDetails(*salary));

	ASSERT_NE(0.785, salary->getPerformanceMetric());
	ASSERT_NE(4450.00, salary->getBonus());
	ASSERT_NE(6505500.00, salary->getBaseSalary());
	ASSERT_NE(70400.00, salary->getAllowance());
	ASSERT_NE(30400.00, salary->getDeduction());
}

TEST_F(EmployeeFixture, getUpdateQueryConditionEmpty) {
	ASSERT_STREQ("", EmployeeControllerTest::getUpdateQueryCondition(*updateEmployee).c_str());
}

TEST_F(EmployeeFixture, getUpdateQueryConditionNonEmpty) {
	updateEmployee->setFirstName("Devin");
	ASSERT_STREQ("firstName = \"Devin\"", EmployeeControllerTest::getUpdateQueryCondition(*updateEmployee).c_str());

	updateEmployee->setDateOfBirth("17/04/2003");
	ASSERT_STREQ("firstName = \"Devin\", dateOfBirth = \"17/04/2003\"", EmployeeControllerTest::getUpdateQueryCondition(*updateEmployee).c_str());

	updateEmployee->setGender(EmployeeDB::Model::Gender::Male);
	ASSERT_STREQ("firstName = \"Devin\", dateOfBirth = \"17/04/2003\", gender = \"Male\"", EmployeeControllerTest::getUpdateQueryCondition(*updateEmployee).c_str());
}

TEST_F(EmployeeFixture, updateEmployeeSuccess) {

	updateEmployee->setEmployeeID(1);
	updateEmployee->setFirstName("Devin");

	ASSERT_TRUE(EmployeeController::updateEmployee(*updateEmployee));

	std::string_view queryString = "SELECT * FROM Employee";
	ASSERT_EQ(4, DBManager::instance().executeRowCountQuery(queryString.data()));

	queryString = "SELECT * FROM Employee WHERE firstName = \"David\"";
	ASSERT_EQ(0, DBManager::instance().executeRowCountQuery(queryString.data()));

	queryString = "SELECT * FROM Employee WHERE firstName = \"Devin\"";
	ASSERT_EQ(1, DBManager::instance().executeRowCountQuery(queryString.data()));
}

TEST_F(EmployeeFixture, updateEmployeeFailure) {

	updateEmployee->setEmployeeID(4);
	updateEmployee->setEmail("david.brown@example.com");

	ASSERT_FALSE(EmployeeController::updateEmployee(*updateEmployee));
}