#ifndef __ExportControllerTest_h__
#define __ExportControllerTest_h__

#include "ExportController.h"

using EmployeeDB::Controller::ExportController;

class ExportControllerTest : public ExportController {
public:
	static void removecommas(std::string& str) {
		ExportController::removeCommas(str);
	}
};

#endif