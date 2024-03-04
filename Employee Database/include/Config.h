#ifndef __Config_H__
#define __Config_H__

#include <iostream>
#include "sqlite3.h"
#include "exception"

namespace EmployeeDB::Config {
	static const char* DbFilePath = "./bin/Employee.db";
}

#endif