#ifndef __ManagerController_H__
#define __ManagerController_H__

#include <iostream>
#include "Manager.h"

using EmployeeDB::Model::Manager;

namespace EmployeeDB::Controller {

	class ManagerController {
	public:
		static bool createManager(Manager& obj);
		static bool selectManager(const std::string& attributeName = "", const std::string& attributeValue = "");
		static bool deleteManagerByID(int ID);
	};
}

#endif