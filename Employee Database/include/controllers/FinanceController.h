#ifndef __FinanceController_H__
#define __FinanceController_H__

#include <iostream>
#include "Finance.h"

namespace EmployeeDB::Controller {

	using EmployeeDB::Model::Finance;

	class FinanceController {
	public:
		static bool createFinance(Finance&);
		static bool selectFinance(const std::string& attributeName = "", const std::string& attributeValue = "");
		static bool deleteFinanceByID(int);
	};
}

#endif