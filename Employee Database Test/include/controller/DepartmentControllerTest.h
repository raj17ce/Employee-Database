#ifndef __DepartmentControllerTest_H__
#define __DepartmentControllerTest_H__

#include "./controller/DepartmentController.h"

using EmployeeDB::Controller::DepartmentController;

class DepartmentControllerTest : public DepartmentController {
public:
	static std::string getUpdateQueryCondition(Department& obj) {
		return DepartmentController::getUpdateQueryCondition(obj);
	}
};

#endif