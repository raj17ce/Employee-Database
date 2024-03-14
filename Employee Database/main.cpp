#include <iostream>
#include <exception>
#include "DBManager.h"
#include "ManagerController.h"
#include "DepartmentController.h";

using EmployeeDB::Controller::ManagerController;
using EmployeeDB::Controller::DepartmentController;
using EmployeeDB::DBManager;

int main() {
	DBManager::executeCascadeQuery();

	Manager m;
	m.setManagerID(2);
	m.setDepartmentID(1);
	m.setTeamSize(5);
	m.setYearsOfExperience(5.5);
	m.setProjectTitle("CPP Project");
	m.setRole("CPP");

	ManagerController::createManager(m);

	ManagerController::selectManager();
}