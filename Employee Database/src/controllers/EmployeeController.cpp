#include "EmployeeController.h"

using EmployeeDB::Controller::EmployeeController;

bool EmployeeController::createEmployee(const Employee& e) {
	std::string queryString = "INSERT INTO Employee (firstName, middleName, lastName, dateOfBirth, mobileNo, email, address, gender, dateOfJoining, departmentID, managerID, performanceMetric, bonus)"
		+ std::string{ "VALUES (" } +
		"\"" + e.getFirstName() + "\"" + ", " +
		"\"" + e.getMiddleName() + "\"" + ", " +
		"\"" + e.getLastName() + "\"" + ", " +
		"\"" + e.getDateOfBirth() + "\"" + ", " +
		std::to_string(e.getMobileNumber()) + ", " +
		"\"" + e.getEmail() + "\"" + ", " +
		"\"" + e.getAddress() + "\"" + ", " +
		"\"" + EmployeeDB::Model::getGenderString(e.getGender()) + "\"" + ", " +
		"\"" + e.getDateOfJoining() + "\"" + ", " +
		std::to_string(e.getDepartmentId()) + ", " +
		std::to_string(e.getManagerId()) + ", " +
		std::to_string(e.getPerformanceMetric()) + ", " +
		std::to_string(e.getBonus()) + ");";

	try {
		DBManager::instance().executeQuery(queryString.c_str());
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
		return false;
	}
	return true;
}

int EmployeeController::selectEmployeeId(const std::string& email) {
	std::string queryString = "SELECT employeeID FROM Employee WHERE email=\"" +email + "\";";
	int selectedId{ 0 };

	auto callbackLambda = [](void* data, int argc, char** argv, char** azColName) -> int {
		int* eId = static_cast<int*>(data);
		//if (azColName[0] == "employeeID") {
			*eId = std::stoi(argv[0]);
		//}
		return 0;
	};

	try {
		DBManager::instance().executeSelectQuery(queryString.c_str(), callbackLambda, &selectedId);
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
		return -1;
	}

	return selectedId;
}