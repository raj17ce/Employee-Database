#ifndef __HRControllerTest_H__
#define __HRControllerTest_H__

#include "./controller/HRController.h"

using EmployeeDB::Controller::HRController;

class HRControllerTest : public HRController {
public:
	static std::string getUpdateQueryCondition(HR& obj) {
		return HRController::getUpdateQueryCondition(obj);
	}
};

#endif
