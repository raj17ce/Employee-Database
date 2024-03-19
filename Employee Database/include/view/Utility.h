#ifndef __Utility_H__
#define __Utility_H__

#include <string>

namespace EmployeeDB::View {
	class Utility {
	public:
		static bool proceedFurther(const std::string& operation);
		static bool repeatOperation(const std::string& Entity);
	};
}

#endif