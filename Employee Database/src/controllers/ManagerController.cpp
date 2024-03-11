#include <exception>
#include "ManagerController.h"
#include "DBManager.h"

using EmployeeDB::Controller::ManagerController;

bool ManagerController::createManager(Manager& obj) {
	std::string queryString = "INSERT INTO Manager (managerID, departmentID, teamSize, yearsOfExp, projectTitle, technology) VALUES (" +
		std::to_string(obj.getManagerID()) + ", " +
		std::to_string(obj.getDepartmentID()) + ", " +
		std::to_string(obj.getTeamSize()) + ", " +
		std::to_string(obj.getYearsOfExperience()) + ", " +
		"\"" + obj.getProjectTitle() + "\"" +
		"\"" + obj.getTechnology() + "\");";

	try {
		DBManager::instance().executeQuery(queryString.c_str());
	}
	catch (std::exception& e) {
		std::cerr << e.what() << '\n';
		return false;
	}
	return true;
}