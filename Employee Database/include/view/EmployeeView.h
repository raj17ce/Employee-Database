#ifndef __EmployeeView_H__
#define __EmployeeView_H__

#include "EmployeeController.h"

namespace EmployeeDB::View {

	class EmployeeView {
	public:
		static void printEmployeeFields();
		static void getInsertEmployeeInput(Employee& obj);
	};
}

#endif