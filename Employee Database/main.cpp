#include <iostream>
#include <exception>
#include "DBManager.h"
#include "DepartmentController.h"
#include "Model.h"

using EmployeeDB::Controller::DepartmentController;

int main() {
	DepartmentController::selectAllDepartmentIDAndName();
}