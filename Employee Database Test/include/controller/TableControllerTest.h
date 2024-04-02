#ifndef __TableControllerTest_H__
#define __TableControllerTest_H__

#include "./controller/TableController.h"

using EmployeeDB::Controller::TableController;

class TableControllerTest : public TableController {
public:
	static std::string getCreateTableQuery(Table& obj) {
		return TableController::getCreateTableQuery(obj);
	}
};

#endif
