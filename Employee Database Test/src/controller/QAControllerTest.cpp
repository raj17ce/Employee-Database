#include "QAController.h"
#include "QAControllerTest.h"
#include "QAFixture.h"
#include "DBManager.h"

using EmployeeDB::Controller::QAController;
using EmployeeDB::DBManager;

TEST_F(QAFixture, insertQASuccess) {
	ASSERT_TRUE(QAController::insertQA(*qa));

	std::string queryString = "SELECT * FROM Employee NATURAL JOIN QA WHERE firstName = \"Emily\" and testingTool = \"Selenium\";";
	ASSERT_EQ(1, DBManager::instance().executeRowCountQuery(queryString.c_str()));
}

TEST_F(QAFixture, insertQAFailure) {
	ASSERT_TRUE(QAController::insertQA(*qa));
	ASSERT_FALSE(QAController::insertQA(*qa));

	std::string queryString = "SELECT * FROM Employee NATURAL JOIN QA WHERE firstName = \"Emily\" and testingTool = \"Selenium\";";
	ASSERT_EQ(1, DBManager::instance().executeRowCountQuery(queryString.c_str()));
}

TEST_F(QAFixture, selectQASuccess) {
	ASSERT_TRUE(QAController::selectQA());
	ASSERT_TRUE(QAController::selectQA("firstName", "David"));
	ASSERT_TRUE(QAController::selectQA("testingTool", "Jira"));

	std::string queryString = "SELECT * FROM QA;";
	ASSERT_EQ(2, DBManager::instance().executeRowCountQuery(queryString.c_str()));
}

TEST_F(QAFixture, selectQAFailure) {
	ASSERT_FALSE(QAController::selectQA("firstNamme", "Devin"));
	ASSERT_FALSE(QAController::selectQA("bonuss", "65000"));

	std::string queryString = "SELECT * FROM QA;";
	ASSERT_EQ(2, DBManager::instance().executeRowCountQuery(queryString.c_str()));
}

TEST_F(QAFixture, deleteQAByID) {
	ASSERT_TRUE(QAController::deleteQAByID(1));
	ASSERT_TRUE(QAController::deleteQAByID(2));

	std::string queryString = "SELECT * FROM QA";
	ASSERT_EQ(0, DBManager::instance().executeRowCountQuery(queryString.c_str()));
}

TEST_F(QAFixture, getUpdateQueryConditionEmpty) {
	ASSERT_STREQ("", QAControllerTest::getUpdateQueryCondition(*updateQa).c_str());
}

TEST_F(QAFixture, getUpdateQueryConditionNonEmpty) {
	updateQa->setTestingTool("gTest");
	ASSERT_STREQ("testingTool = \"gTest\"", QAControllerTest::getUpdateQueryCondition(*updateQa).c_str());
}

TEST_F(QAFixture, updateQASuccess) {

	updateQa->setEmployeeID(1);
	updateQa->setFirstName("Devin");

	ASSERT_TRUE(QAController::updateQA(*updateQa));

	std::string queryString = "SELECT * FROM QA";
	ASSERT_EQ(2, DBManager::instance().executeRowCountQuery(queryString.c_str()));

	queryString = "SELECT * FROM Employee NATURAL JOIN QA WHERE firstName = \"David\"";
	ASSERT_EQ(0, DBManager::instance().executeRowCountQuery(queryString.c_str()));

	queryString = "SELECT * FROM Employee NATURAL JOIN QA WHERE firstName = \"Devin\"";
	ASSERT_EQ(1, DBManager::instance().executeRowCountQuery(queryString.c_str()));
}

TEST_F(QAFixture, updateQAFailure) {

	updateQa->setEmployeeID(2);
	updateQa->setEmail("david.brown@example.com");

	ASSERT_FALSE(QAController::updateQA(*updateQa));
}