#ifndef __EngineerController_H__
#define __EngineerController_H__

#include <iostream>
#include "Engineer.h"

namespace EmployeeDB::Controller {

	using EmployeeDB::Model::Engineer;

	class EngineerController {
	public:
		static bool createEngineer(const Engineer&);
	};
}

#endif