#ifndef __EmployeeController_H__
#define __EmployeeController_H__

#include <iostream>
#include "Employee.h"

using EmployeeDB::Model::Employee;

namespace EmployeeDB::Controller {

	class EmployeeController {
	public:
		static bool insertEmployee(const Employee& obj);
		static int getEmployeeIDbyEmail(const std::string& email);
		static int getDepartmentIDbyEmployeeID(int ID);
		static bool checkEmployeeExistence(const std::string& employeeID);
		static bool deleteEmployeeByID(int ID);
		static bool updateEmployee(Employee& obj);
	private:
		static std::string getUpdateQueryCondition(Employee& obj);
	};
}

#endif