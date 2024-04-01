#ifndef __ManagerControllerTest_H__
#define __ManagerControllerTest_H__

#include "./controller/ManagerController.h"

using EmployeeDB::Controller::ManagerController;

class ManagerControllerTest : public ManagerController {
public:
	static std::string getUpdateQueryCondition(Manager& obj) {
		return ManagerController::getUpdateQueryCondition(obj);
	}
};

#endif
