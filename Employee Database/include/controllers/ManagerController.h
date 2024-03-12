#ifndef __ManagerController_H__
#define __ManagerController_H__

#include <iostream>
#include "Manager.h"

namespace EmployeeDB::Controller {

	using EmployeeDB::Model::Manager;

	class ManagerController {
	public:
		static bool createManager(Manager&);
		static bool selectAllManager();
	};
}

#endif