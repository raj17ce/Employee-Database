#ifndef __EmployeeController_H__
#define __EmployeeController_H__

#include <iostream>
#include "Employee.h"

namespace EmployeeDB::Controller {

	using EmployeeDB::Model::Employee;

	class EmployeeController {
	public:
		static bool createEmployee(const Employee&);
		static int getEmployeeIDbyEmail(const std::string&);
	};
}

#endif