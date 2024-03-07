#include <exception>
#include "EmployeeController.h"
#include "DBManager.h"

using EmployeeDB::Controller::EmployeeController;
using EmployeeDB::DBManager;

bool EmployeeController::createEmployee(const Employee& obj) {
	std::string queryString = "INSERT INTO Employee (firstName, middleName, lastName, dateOfBirth, mobileNo, email, address, gender, dateOfJoining, departmentID, managerID, performanceMetric, bonus)"
		+ std::string{ "VALUES (" } +
		"\"" + obj.getFirstName() + "\"" + ", " +
		"\"" + obj.getMiddleName() + "\"" + ", " +
		"\"" + obj.getLastName() + "\"" + ", " +
		"\"" + obj.getDateOfBirth() + "\"" + ", " +
		std::to_string(obj.getMobileNumber()) + ", " +
		"\"" + obj.getEmail() + "\"" + ", " +
		"\"" + obj.getAddress() + "\"" + ", " +
		"\"" + EmployeeDB::Model::getGenderString(obj.getGender()) + "\"" + ", " +
		"\"" + obj.getDateOfJoining() + "\"" + ", " +
		std::to_string(obj.getDepartmentID()) + ", " +
		std::to_string(obj.getManagerID()) + ", " +
		std::to_string(obj.getPerformanceMetric()) + ", " +
		std::to_string(obj.getBonus()) + ");";

	try {
		DBManager::instance().executeQuery(queryString.c_str());
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
		return false;
	}
	return true;
}

int EmployeeController::getEmployeeIDbyEmail(const std::string& email) {
	std::string queryString = "SELECT employeeID FROM Employee WHERE email=\"" +email + "\";";
	int employeeID{ -1 };

	auto getEmployeeIDCallback = [](void* data, int argc, char** argv, char** azColName) -> int {
		int* eId = static_cast<int*>(data);
		if (!strcmp(azColName[0], "employeeID")) {
			*eId = std::stoi(argv[0]);
		}
		return 0;
	};

	try {
		DBManager::instance().executeSelectQuery(queryString.c_str(), getEmployeeIDCallback, &employeeID);
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
		return -1;
	}

	return employeeID;
}