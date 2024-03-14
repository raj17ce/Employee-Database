#include <iostream>
#include <exception>
#include "DBManager.h"
#include "EngineerController.h"

using EmployeeDB::Controller::EngineerController;
using EmployeeDB::DBManager;

int main() {
	DBManager::executeCascadeQuery();

	Engineer e{ true };

	e.setEmployeeID(1);
	e.setTechnology("CPP, Unreal");

	EngineerController::updateEngineer(e);

	EngineerController::selectEngineer();
}