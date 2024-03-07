#include <exception>
#include "DBManager.h"
#include "EngineerController.h"
#include "EmployeeController.h"

using EmployeeDB::Controller::EmployeeController;
using EmployeeDB::Controller::EngineerController;
using EmployeeDB::DBManager;

bool EngineerController::createEngineer(const Engineer& obj) {
	bool employeeResult = EmployeeController::createEmployee(obj);

	if (!employeeResult) {
		return false;
	}

	int employeeID = EmployeeController::selectEmployeeIDbyEmail(obj.getEmail());

	std::string queryString = "INSERT INTO Engineer (employeeID, technology) VALUES (" +
		std::to_string(employeeID) + ", " +
		"\" " + obj.getTechnology() + "\");";

	try {
		DBManager::instance().executeQuery(queryString.c_str());
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
		return false;
	}
	return true;
} 