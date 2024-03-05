#ifndef __Engineer_H__
#define __Engineer_H__

#include "Employee.h"

namespace EmployeeDB::Model {

	class Engineer : public Employee {
	public:
		void setProgrammingLanguage(const std::string& programmingLanguage) {
			m_ProgrammingLanguage = programmingLanguage;
		}

		const std::string& getProgrammingLanguage() const {
			return m_ProgrammingLanguage;
		}

		double computeSalary() override;
	private:
		std::string m_ProgrammingLanguage;
	};
}

#endif