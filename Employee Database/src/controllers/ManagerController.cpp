#include <exception>
#include "ManagerController.h"
#include "DBManager.h"

using EmployeeDB::Controller::ManagerController;

bool ManagerController::createManager(Manager& obj) {
	std::string queryString = "INSERT INTO Manager (managerID, departmentID, teamSize, yearsOfExp, projectTitle, role) VALUES (" +
		std::to_string(obj.getManagerID()) + ", " +
		std::to_string(obj.getDepartmentID()) + ", " +
		std::to_string(obj.getTeamSize()) + ", " +
		std::to_string(obj.getYearsOfExperience()) + ", " +
		"\"" + obj.getProjectTitle() + "\"," +
		"\"" + obj.getRole() + "\");";

	try {
		DBManager::instance().executeQuery(queryString.c_str());
	}
	catch (std::exception& e) {
		std::cerr << e.what() << '\n';
		return false;
	}
	return true;
}

bool ManagerController::selectManager(const std::string& attributeName, const std::string& attributeValue) {
	std::string queryString = "SELECT * FROM ManagerView " + ((attributeName.size() != 0) ? "WHERE " + attributeName + " = \"" + attributeValue + "\"" : "") + ";";

	try {
		DBManager::instance().executeSelectQuery(queryString.c_str());
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
		return false;
	}
	return true;
};

bool ManagerController::deleteManagerByID(int ID) {
	std::string queryString = "DELETE FROM Manager WHERE managerID = " + std::to_string(ID) + ";";

	try {
		DBManager::instance().executeQuery(queryString.c_str());
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
		return false;
	}
	return true;
};

std::string ManagerController::getUpdateQueryCondition(Manager& obj) {
	std::string updateQueryCondition{ "" };

	if (obj.getTeamSize() != -1) {
		updateQueryCondition += "teamSize = " + std::to_string(obj.getTeamSize());
	}
	if (obj.getYearsOfExperience() != -1) {
		if (updateQueryCondition.size() != 0) {
			updateQueryCondition += ", ";
		}
		updateQueryCondition += "yearsOfExperience = " + std::to_string(obj.getYearsOfExperience());
	}
	if (obj.getProjectTitle() != "#") {
		if (updateQueryCondition.size() != 0) {
			updateQueryCondition += ", ";
		}
		updateQueryCondition += "projectTitle = \"" + obj.getProjectTitle() + "\"";
	}
	if (obj.getRole() != "#") {
		if (updateQueryCondition.size() != 0) {
			updateQueryCondition += ", ";
		}
		updateQueryCondition += "role = \"" + obj.getRole() + "\"";
	}

	return updateQueryCondition;
}

bool ManagerController::updateManager(Manager& obj) {

	std::string updateQueryCondition = getUpdateQueryCondition(obj);

	if (updateQueryCondition.size() != 0) {
		std::string queryString = "UPDATE Manager SET " + updateQueryCondition + " WHERE managerID = " + std::to_string(obj.getManagerID()) + " AND departmentID = " + std::to_string(obj.getDepartmentID()) + ";";
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