#ifndef __ManagerView_H__
#define __ManagerView_H__

#include "ManagerController.h"

namespace EmployeeDB::View {

	class ManagerView {
	public:
		static void printManagerFields();
		static void getInsertManagerInput(Manager& obj);
		static bool insertManager();
	};
}

#endif