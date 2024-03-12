#include <iostream>
#include <exception>
#include "DBManager.h"
#include "EngineerController.h"
#include "Model.h"

using EmployeeDB::Controller::EngineerController;

int main() {
	EngineerController::selectAllEngineer();
}