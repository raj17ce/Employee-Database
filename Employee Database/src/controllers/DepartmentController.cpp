#include <exception>
#include <iomanip>
#include "DepartmentController.h"
#include "DBManager.h"

using EmployeeDB::Controller::DepartmentController;
using EmployeeDB::DBManager;

bool DepartmentController::createDepartment(const Department& obj) {
	std::string queryString = "INSERT INTO Department (departmentName, baseSalary, allowance, deduction) "
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
	std::string queryString = "SELECT departmentID FROM Department WHERE departmentName = \"" + departmentName + "\";";
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

bool DepartmentController::selectAllDepartmentIDAndName() {
	std::string queryString = "SELECT departmentID,departmentName FROM Department;";

	//auto lambda = [](void* data, int argc, char** argv, char** azColName) {
	//	int* count = static_cast<int*>(data);

	//	if(count != nullptr && *count == 0) {
	//		++(*count);
	//		std::cout << "|--------------------|----------------------------------------|\n";
	//		std::cout << "|" << std::setw(20) << std::left << azColName[0] << "|" << std::setw(40) << std::left << azColName[1] << "|\n";
	//		std::cout << "|--------------------|----------------------------------------|\n";
	//	}
	//	std::cout << "|" << std::setw(20) << std::left << argv[0] << "|" << std::setw(40) << std::left << argv[1] << "|\n";
	///*	int i;
	//	for (i = 0; i < argc; i++) {
	//		std::cout << "|" << std::setw(20) << std::left << azColName[i] << "|" << std::setw(40) << std::left << (argv[i] ? argv[i] : "NULL") << "|\n";
	//	}*/
	//	return 0;
	//	};

	try {
		int i = 0;
		DBManager::instance().executeSelectQuery(queryString.c_str());
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
		return false;
	}

	return true;
}

bool DepartmentController::selectDepartment(const std::string& attributeName, const std::string& attributeValue) {
	std::string queryString = "SELECT * FROM Department " + ((attributeName.size() != 0) ? "WHERE " + attributeName + " = \"" + attributeValue + "\"":"") + ";";

	try {
		DBManager::instance().executeSelectQuery(queryString.c_str());
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
		return false;
	}
	return true;
};

bool DepartmentController::deleteDepartmentByID(int ID) {
	std::string queryString = "DELETE FROM Department WHERE departmentID = " + std::to_string(ID) + ";";

	try {
		DBManager::instance().executeQuery(queryString.c_str());
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
		return false;
	}
	return true;
}

std::string DepartmentController::getUpdateQueryCondition(Department& obj) {
	std::string updateQueryCondition{ "" };

	if (obj.getDepartmentName() != "#") {
		updateQueryCondition += "departmentName = \"" + obj.getDepartmentName() + "\"";
	}
	if (obj.getBaseSalary() != -1.0) {
		if (updateQueryCondition.size() != 0) {
			updateQueryCondition += ", ";
		}
		updateQueryCondition += "baseSalary = " + std::to_string(obj.getBaseSalary());
	}
	if (obj.getAllowance() != -1.0) {
		if (updateQueryCondition.size() != 0) {
			updateQueryCondition += ", ";
		}
		updateQueryCondition += "allowance = " + std::to_string(obj.getAllowance());
	}
	if (obj.getDeduction() != -1.0) {
		if (updateQueryCondition.size() != 0) {
			updateQueryCondition += ", ";
		}
		updateQueryCondition += "deduction = " + std::to_string(obj.getDeduction());
	}

	return updateQueryCondition;
}

bool DepartmentController::updateDepartment(Department& obj) {

	std::string updateQueryCondition = getUpdateQueryCondition(obj);

	if (updateQueryCondition.size() != 0) {
		std::string queryString = "UPDATE Department SET " + updateQueryCondition + " WHERE departmentID = " + std::to_string(obj.getDepartmentID()) + ";";
		try {
			DBManager::instance().executeQuery(queryString.c_str());
		}
		catch (const std::exception& e) {
			std::cerr << e.what() << '\n';
			return false;
		}
	}
	return true;
}