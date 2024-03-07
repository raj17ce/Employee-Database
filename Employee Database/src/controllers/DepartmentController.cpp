#include <exception>
#include "DepartmentController.h"
#include "DBManager.h"

using EmployeeDB::Controller::DepartmentController;
using EmployeeDB::DBManager;

bool DepartmentController::createDepartment(const Department& obj) {
	std::string queryString = "INSERT INTO Department (departmentName, baseSalary, allowance, deduction)"
		+ std::string{ "VALUES (" } +
		"\"" + obj.getDepartmentName() + "\"" + ", " +
		std::to_string(obj.getBaseSalary()) + ", " +
		std::to_string(obj.getAllowance()) + ", " +
		std::to_string(obj.getDeduction()) + ");";

	try {
		DBManager::instance().executeQuery(queryString.c_str());
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
		return false;
	}
	return true;
}

int DepartmentController::getDepartmentIDbyName(const std::string& departmentName) {
	std::string queryString = "SELECT departmentID FROM Department WHERE departmentName=\"" + departmentName + "\";";
	int departmentID{ -1 };

	auto getDepartmentIDCallback = [](void* data, int argc, char** argv, char** azColName) -> int {
		int* eId = static_cast<int*>(data);
		if (!strcmp(azColName[0], "departmentID")) {
			*eId = std::stoi(argv[0]);
		}
		return 0;
		};

	try {
		DBManager::instance().executeSelectQuery(queryString.c_str(), getDepartmentIDCallback, &departmentID);
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
		return -1;
	}

	return departmentID;
}