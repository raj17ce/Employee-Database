#ifndef __Validate_H__
#define __Validate_H__

#include <string>

namespace EmployeeDB {
	class Validate {
	public:
		static bool validateEmail(const std::string&);
		static bool validateMobile(const std::string&);
		static bool validateDate(const std::string&);
	};
}

#endif