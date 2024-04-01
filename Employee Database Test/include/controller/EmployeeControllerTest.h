#ifndef __EmployeeControllerTest_H__
#define __EmployeeControllerTest_H__

#include "./controller/EmployeeController.h"

using EmployeeDB::Controller::EmployeeController;

class EmployeeControllerTest : public EmployeeController {
public:
	static std::string getUpdateQueryCondition(Employee& obj) {
		return EmployeeController::getUpdateQueryCondition(obj);
	}
};

#endif
