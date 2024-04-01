#ifndef __QAControllerTest_H__
#define __QAControllerTest_H__

#include "./controller/QAController.h"

using EmployeeDB::Controller::QAController;

class QAControllerTest : public QAController {
public:
	static std::string getUpdateQueryCondition(QA& obj) {
		return QAController::getUpdateQueryCondition(obj);
	}
};

#endif
