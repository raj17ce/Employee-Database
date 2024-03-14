#ifndef __EmployeeController_H__
#define __EmployeeController_H__

#include <iostream>
#include "Employee.h"

using EmployeeDB::Model::Employee;

namespace EmployeeDB::Controller {

	class EmployeeController {
	public:
		static bool createEmployee(const Employee& obj);
		static int getEmployeeIDbyEmail(const std::string& email);
		static bool deleteEmployeeByID(int ID);
		static bool updateEmployee(const Employee& obj);
	};
}

#endif