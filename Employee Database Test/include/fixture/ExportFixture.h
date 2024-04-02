#ifndef __ExportFixture_h__
#define __ExportFixture_h__

#include "../../pch.h"
#include "DBManager.h"
#include <filesystem>

using EmployeeDB::DBManager;
namespace fs = std::filesystem;

class ExportFixture : public ::testing::Test {
protected:
	void SetUp() override {
		DBManager::executeConfigQuery();

		std::string_view queryString = "INSERT INTO Department (\"departmentID\", \"departmentName\", \"baseSalary\", \"allowance\", \"deduction\") VALUES "
			"(1, 'Engineer', 65000, 7000, 3000),"
			"(2, 'Finance', 65000, 6000, 2500),"
			"(3, 'HR', 55000, 4000, 1500),"
			"(4, 'QA', 59000, 4800, 1900);"
			"INSERT INTO Employee (\"employeeID\", \"firstName\", \"middleName\", \"lastName\", \"dateOfBirth\", \"mobileNumber\", \"email\", \"address\", \"gender\", \"dateOfJoining\", \"departmentID\", \"mentorID\", \"performanceMetric\", \"bonus\") VALUES "
			"(1, 'John', 'Doe', 'Smith', '15-05-1990', 1234567891, 'john.smith@example.com', '123 Main St, City, Country', 'Male', '10-01-2020', 1, 1, 0.85, 500),"
			"(2, 'David', 'Lee', 'Brown', '03-04-1993', 1234509876, 'david.brown@example.com', '345 Oak St, City, Country', 'Male', '12-11-2022', 1, 2, 0.78, 450),"
			"(3, 'Jane', 'Doe', 'Smith', '20-08-1992', 9876543211, 'jane.smith@example.com', '456 Elm St, City, Country', 'Female', '20-05-2018', 2, 3, 0.75, 400),"
			"(4, 'Sarah', 'Elizabeth', 'Wilson', '10-07-1995', 9876543212, 'sarah.wilson@example.com', '567 Elm St, City, Country', 'Female', '05-09-2023', 2, 3, 0.88, 600);"
			"INSERT INTO Manager(\"managerID\", \"departmentID\", \"teamSize\", \"yearsOfExp\", \"projectTitle\", \"role\") VALUES "
			"(1, 1, 15, 10, 'Project A', 'Java'),"
			"(3, 2, 18, 12, 'Project E', 'SAP');";

		try {
			DBManager::instance().executeQuery(queryString.data());
		}
		catch (const std::exception& e) {
			std::cerr << "\x1B[31m" << e.what() << "\033[0m\n";
		}
	}

	void TearDown() override {

		fs::path exportPath{ "./data/csv/Department.csv" };
		if (fs::exists(exportPath)) {
			fs::remove(exportPath);
		}

		exportPath = "./data/csv/Employee.csv";
		if (fs::exists(exportPath)) {
			fs::remove(exportPath);
		}

		exportPath = "./data/csv/Manager.csv";
		if (fs::exists(exportPath)) {
			fs::remove(exportPath);
		}

		
		exportPath = "./data/csv/DepartmentBackup.csv";
		if (fs::exists(exportPath)) {
			fs::remove(exportPath);
		}

		exportPath = "./data/csv/EmployeeBackup.csv";
		if (fs::exists(exportPath)) {
			fs::remove(exportPath);
		}

		exportPath = "./data/csv/EngineerBackup.csv";
		if (fs::exists(exportPath)) {
			fs::remove(exportPath);
		}

		exportPath = "./data/csv/FinanceBackup.csv";
		if (fs::exists(exportPath)) {
			fs::remove(exportPath);
		}

		exportPath = "./data/csv/HRBackup.csv";
		if (fs::exists(exportPath)) {
			fs::remove(exportPath);
		}	

		exportPath = "./data/csv/QABackup.csv";
		if (fs::exists(exportPath)) {
			fs::remove(exportPath);
		}

		exportPath = "./data/csv/ManagerBackup.csv";
		if (fs::exists(exportPath)) {
			fs::remove(exportPath);
		}

		DBManager::instance().executeTruncateQuery("Department");
		DBManager::instance().executeTruncateQuery("Employee");
		DBManager::instance().executeTruncateQuery("Manager");
	}
};

#endif