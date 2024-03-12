#ifndef __QAController_H__
#define __QAController_H__

#include <iostream>
#include "QA.h"

namespace EmployeeDB::Controller {

	using EmployeeDB::Model::QA;

	class QAController {
	public:
		static bool createQA(QA&);
		static bool selectAllQA();
	};
}

#endif