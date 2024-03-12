#ifndef __HRController_H__
#define __HRController_H__

#include <iostream>
#include "HR.h"

namespace EmployeeDB::Controller {

	using EmployeeDB::Model::HR;

	class HRController {
	public:
		static bool createHR(HR&);
		static bool selectAllHR();
	};
}

#endif