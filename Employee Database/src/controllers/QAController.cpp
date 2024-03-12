#include <exception>
#include "DBManager.h"
#include "QAController.h"
#include "EmployeeController.h"
#include "DepartmentController.h"

using EmployeeDB::Controller::EmployeeController;
using EmployeeDB::Controller::QAController;
using EmployeeDB::Controller::DepartmentController;
using EmployeeDB::DBManager;

bool QAController::createQA(QA& obj) {
	int departmentID = DepartmentController::getDepartmentIDbyName("QA");

	if (departmentID == -1) {
		std::cerr << "QA department not found.";
		return false;
	}

	obj.setDepartmentID(departmentID);

	bool employeeResult = EmployeeController::createEmployee(obj);

	if (!employeeResult) {
		return false;
	}

	int employeeID = EmployeeController::getEmployeeIDbyEmail(obj.getEmail());

	std::string queryString = "INSERT INTO QA (employeeID, testingTool) VALUES (" +
		std::to_string(employeeID) + ", " +
		"\"" + obj.getTestingTool() + "\");";

	try {
		DBManager::instance().executeQuery(queryString.c_str());
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
		return false;
	}
	return true;
}

bool QAController::selectAllQA() {
	std::string queryString = "SELECT * FROM Employee NATURAL JOIN QA";
	try {
		DBManager::instance().executeSelectQuery(queryString.c_str());
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
		return false;
	}
	return true;
};