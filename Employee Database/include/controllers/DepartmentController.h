#ifndef __DepartmentController_H__
#define __DepartmentController_H__

#include <iostream>
#include "Department.h"

namespace EmployeeDB::Controller {

	using EmployeeDB::Model::Department;

	class DepartmentController {
	public:
		static bool createDepartment(const Department&);
	};
}

#endif