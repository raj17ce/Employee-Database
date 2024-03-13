#include <exception>
#include "DBManager.h"
#include "EngineerController.h"
#include "EmployeeController.h"
#include "DepartmentController.h"

using EmployeeDB::Controller::EmployeeController;
using EmployeeDB::Controller::EngineerController;
using EmployeeDB::Controller::DepartmentController;
using EmployeeDB::DBManager;

bool EngineerController::createEngineer(Engineer& obj) {
	int departmentID = DepartmentController::getDepartmentIDbyName("Engineer");

	if (departmentID == -1) {
		std::cerr << "Engineer department not found.";
		return false;
	}

	obj.setDepartmentID(departmentID);

	bool employeeResult = EmployeeController::createEmployee(obj);

	if (!employeeResult) {
		return false;
	}

	int employeeID = EmployeeController::getEmployeeIDbyEmail(obj.getEmail());

	std::string queryString = "INSERT INTO Engineer (employeeID, technology) VALUES (" +
		std::to_string(employeeID) + ", " +
		"\"" + obj.getTechnology() + "\");";

	try {
		DBManager::instance().executeQuery(queryString.c_str());
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
		return false;
	}
	return true;
}

bool EngineerController::selectEngineer(const std::string& attributeName, const std::string& attributeValue) {
	std::string queryString = "SELECT * FROM Employee NATURAL JOIN Engineer " + ((attributeName.size() != 0) ? "WHERE " + attributeName + " = \"" + attributeValue + "\"" : "") + ";";

	try {
		DBManager::instance().executeSelectQuery(queryString.c_str());
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
		return false;
	}
	return true;
};

bool EngineerController::deleteEngineerByID(int ID) {
	return EmployeeController::deleteEmployeeByID(ID);
}