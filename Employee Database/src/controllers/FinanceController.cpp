#include <exception>
#include "DBManager.h"
#include "FinanceController.h"
#include "EmployeeController.h"

using EmployeeDB::Controller::EmployeeController;
using EmployeeDB::Controller::FinanceController;
using EmployeeDB::DBManager;

bool FinanceController::createFinance(const Finance& obj) {
	bool employeeResult = EmployeeController::createEmployee(obj);

	if (!employeeResult) {
		return false;
	}

	int employeeID = EmployeeController::selectEmployeeIDbyEmail(obj.getEmail());

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