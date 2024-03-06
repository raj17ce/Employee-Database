#ifndef __EmployeeController_H__
#define __EmployeeController_H__

#include <iostream>
#include "exception"
#include "Employee.h"
#include "DBManager.h"

namespace EmployeeDB::Controller {

	using EmployeeDB::Model::Employee;

	class EmployeeController {
	public:
		static bool createEmployee(const Employee&);
		static int selectEmployeeId(const std::string& email);
	};
}

#endif