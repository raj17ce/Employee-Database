#ifndef __DepartmentView_H__
#define __DepartmentView_H__

#include "DepartmentController.h"

namespace EmployeeDB::View {

	class DepartmentView {
	public:
		static void printDepartmentFields();
		static void getInsertDepartmentInput(Department& obj);
		static bool insertDepartment();
	};
}

#endif