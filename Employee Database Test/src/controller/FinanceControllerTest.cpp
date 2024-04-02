#include "FinanceController.h"
#include "FinanceControllerTest.h"
#include "FinanceFixture.h"
#include "DBManager.h"

using EmployeeDB::Controller::FinanceController;
using EmployeeDB::DBManager;

TEST_F(FinanceFixture, insertFinanceSuccess) {
	ASSERT_TRUE(FinanceController::insertFinance(*finance));

	std::string_view queryString = "SELECT * FROM Employee NATURAL JOIN Finance WHERE firstName = \"Jane\" and accountingTool = \"QuickBooks\";";
	ASSERT_EQ(1, DBManager::instance().executeRowCountQuery(queryString.data()));
}

TEST_F(FinanceFixture, insertFinanceFailure) {
	ASSERT_TRUE(FinanceController::insertFinance(*finance));
	ASSERT_FALSE(FinanceController::insertFinance(*finance));

	std::string_view queryString = "SELECT * FROM Employee NATURAL JOIN Finance WHERE firstName = \"Jane\" and accountingTool = \"QuickBooks\";";
	ASSERT_EQ(1, DBManager::instance().executeRowCountQuery(queryString.data()));
}

TEST_F(FinanceFixture, selectFinanceSuccess) {
	ASSERT_TRUE(FinanceController::selectFinance());
	ASSERT_TRUE(FinanceController::selectFinance("firstName", "David"));
	ASSERT_TRUE(FinanceController::selectFinance("accountingTool", "Excel"));

	std::string_view queryString = "SELECT * FROM Finance;";
	ASSERT_EQ(2, DBManager::instance().executeRowCountQuery(queryString.data()));
}

TEST_F(FinanceFixture, selectFinanceFailure) {
	ASSERT_FALSE(FinanceController::selectFinance("firstNamme", "Devin"));
	ASSERT_FALSE(FinanceController::selectFinance("bonuss", "65000"));

	std::string_view queryString = "SELECT * FROM Finance;";
	ASSERT_EQ(2, DBManager::instance().executeRowCountQuery(queryString.data()));
}

TEST_F(FinanceFixture, deleteFinanceByID) {
	ASSERT_TRUE(FinanceController::deleteFinanceByID(1));
	ASSERT_TRUE(FinanceController::deleteFinanceByID(2));

	std::string_view queryString = "SELECT * FROM Finance";
	ASSERT_EQ(0, DBManager::instance().executeRowCountQuery(queryString.data()));
}

TEST_F(FinanceFixture, getUpdateQueryConditionEmpty) {
	ASSERT_STREQ("", FinanceControllerTest::getUpdateQueryCondition(*updateFinance).c_str());
}

TEST_F(FinanceFixture, getUpdateQueryConditionNonEmpty) {
	updateFinance->setAccountingTool("Excel");
	ASSERT_STREQ("accountingTool = \"Excel\"", FinanceControllerTest::getUpdateQueryCondition(*updateFinance).c_str());
}

TEST_F(FinanceFixture, updateFinanceSuccess) {

	updateFinance->setEmployeeID(1);
	updateFinance->setFirstName("Devin");

	ASSERT_TRUE(FinanceController::updateFinance(*updateFinance));

	std::string_view queryString = "SELECT * FROM Finance";
	ASSERT_EQ(2, DBManager::instance().executeRowCountQuery(queryString.data()));

	queryString = "SELECT * FROM Employee NATURAL JOIN Finance WHERE firstName = \"David\"";
	ASSERT_EQ(0, DBManager::instance().executeRowCountQuery(queryString.data()));

	queryString = "SELECT * FROM Employee NATURAL JOIN Finance WHERE firstName = \"Devin\"";
	ASSERT_EQ(1, DBManager::instance().executeRowCountQuery(queryString.data()));
}

TEST_F(FinanceFixture, updateFinanceFailure) {

	updateFinance->setEmployeeID(2);
	updateFinance->setEmail("david.brown@example.com");

	ASSERT_FALSE(FinanceController::updateFinance(*updateFinance));
}