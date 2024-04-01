#ifndef __EngineerControllerTest_H__
#define __EngineerControllerTest_H__

#include "./controller/EngineerController.h"

using EmployeeDB::Controller::EngineerController;

class EngineerControllerTest : public EngineerController {
public:
	static std::string getUpdateQueryCondition(Engineer& obj) {
		return EngineerController::getUpdateQueryCondition(obj);
	}
};

#endif
