#ifndef __Config_H__
#define __Config_H__

#include <filesystem>

namespace EmployeeDB::Config {
	static std::filesystem::path DbFilePath = "./data/Employee.db";
}

#endif