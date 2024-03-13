#ifndef __FinanceController_H__
#define __FinanceController_H__

#include <iostream>
#include "Finance.h"

namespace EmployeeDB::Controller {

	using EmployeeDB::Model::Finance;

	class FinanceController {
	public:
		static bool createFinance(Finance&);
		static bool selectAllFinance();
		static bool deleteFinanceByID(int);
	};
}

#endif