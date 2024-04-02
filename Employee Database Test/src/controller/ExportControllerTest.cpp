#include "../../pch.h"
#include "ExportControllerTest.h"
#include "ExportFixture.h"
#include <filesystem>

namespace fs = std::filesystem;

TEST_F(ExportFixture, exportToCSVSuccess) {
	ASSERT_TRUE(ExportController::exportToCSV("Manager", "Manager"));
	ASSERT_TRUE(ExportController::exportToCSV("Employee", "Employee"));
	ASSERT_TRUE(ExportController::exportToCSV("Department", "Department"));

	fs::path exportPath{ "./data/csv/Manager.csv" };
	ASSERT_TRUE(fs::exists(exportPath));

	exportPath = "./data/csv/Employee.csv";
	ASSERT_TRUE(fs::exists(exportPath));

	exportPath = "./data/csv/Department.csv";
	ASSERT_TRUE(fs::exists(exportPath));
}

TEST_F(ExportFixture, exportToCSVFailure) {
	ASSERT_FALSE(ExportController::exportToCSV("Maaaaaanager", "Manager"));
}

TEST_F(ExportFixture, exportAll) {
	ASSERT_TRUE(ExportController::exportAll());

	fs::path exportPath{ "./data/csv/ManagerBackup.csv" };
	ASSERT_TRUE(fs::exists(exportPath));

	exportPath = "./data/csv/EmployeeBackup.csv";
	ASSERT_TRUE(fs::exists(exportPath));

	exportPath = "./data/csv/DepartmentBackup.csv";
	ASSERT_TRUE(fs::exists(exportPath));

	exportPath = "./data/csv/EngineerBackup.csv";
	ASSERT_TRUE(fs::exists(exportPath));

	exportPath = "./data/csv/HRBackup.csv";
	ASSERT_TRUE(fs::exists(exportPath));

	exportPath = "./data/csv/QABackup.csv";
	ASSERT_TRUE(fs::exists(exportPath));

	exportPath = "./data/csv/FinanceBackup.csv";
	ASSERT_TRUE(fs::exists(exportPath));
}

TEST_F(ExportFixture, removecommasEmpty) {
	std::string stringToTest{ "" };

	ExportControllerTest::removecommas(stringToTest);
	ASSERT_STREQ("", stringToTest.c_str());

	stringToTest = ",,,,,,,,,";
	ExportControllerTest::removecommas(stringToTest);
	ASSERT_STREQ("", stringToTest.c_str());
}

TEST_F(ExportFixture, removecommasNonEmpty) {
	std::string stringToTest{ "Hello, How, Are you?,,," };

	ExportControllerTest::removecommas(stringToTest);
	ASSERT_STREQ("Hello How Are you?", stringToTest.c_str());

	stringToTest = ",,,Hiii,,,He,,llo,";

	ExportControllerTest::removecommas(stringToTest);
	ASSERT_STREQ("HiiiHello", stringToTest.c_str());
}