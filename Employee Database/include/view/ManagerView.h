#ifndef __ManagerView_H__
#define __ManagerView_H__

#include "ManagerController.h"

namespace EmployeeDB::View {

	class ManagerView {
	public:
		static void printManagerFields();
		static void getInsertManagerInput(Manager& obj);
		static bool insertManager();
		static void printUpdateManagerFields();
		static void getUpdateManagerInput(Manager& obj, int fieldNumber);
		static bool getManagerIDInput(Manager& obj, const std::string& operation);
		static bool updateManager();
		static bool deleteManager();
	};
}

#endif