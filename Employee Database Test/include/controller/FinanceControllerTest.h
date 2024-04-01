#ifndef __FinanceControllerTest_H__
#define __FinanceControllerTest_H__

#include "./controller/FinanceController.h"

using EmployeeDB::Controller::FinanceController;

class FinanceControllerTest : public FinanceController {
public:
	static std::string getUpdateQueryCondition(Finance& obj) {
		return FinanceController::getUpdateQueryCondition(obj);
	}
};

#endif
