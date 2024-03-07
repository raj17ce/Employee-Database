#include <exception>
#include "DBManager.h"
#include "FinanceController.h"
#include "EmployeeController.h"
#include "DepartmentController.h"

using EmployeeDB::Controller::EmployeeController;
using EmployeeDB::Controller::FinanceController;
using EmployeeDB::Controller::DepartmentController;
using EmployeeDB::DBManager;

bool FinanceController::createFinance(Finance& obj) {
	int departmentID = DepartmentController::getDepartmentIDbyName("Finance");

	if (departmentID == -1) {
		std::cerr << "Finance department not found.";
		return false;
	}

	obj.setDepartmentID(departmentID);

	bool employeeResult = EmployeeController::createEmployee(obj);

	if (!employeeResult) {
		return false;
	}

	int employeeID = EmployeeController::getEmployeeIDbyEmail(obj.getEmail());

	std::string queryString = "INSERT INTO Finance (employeeID, accountingTool) VALUES (" +
		std::to_string(employeeID) + ", " +
		"\" " + obj.getAccountingTool() + "\");";

	try {
		DBManager::instance().executeQuery(queryString.c_str());
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
		return false;
	}
	return true;
}