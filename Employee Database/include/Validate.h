#ifndef __Validate_H__
#define __Validate_H__

#include <string>

namespace EmployeeDB {
	class Validate {
	public:
		static bool validateEmail(const std::string& email);
		static bool validateMobile(const std::string& number);
		static bool validateDate(const std::string& date);
		static bool validateGender(std::string& gender);
		//static bool validateManagerID(const std::string& managerID);
	};
}

#endif