#ifndef __Engineer_H__
#define __Engineer_H__

#include "Employee.h"

namespace EmployeeDB::Model {

	class Engineer : public Employee {
	public:
		void setProgrammingLanguage(const std::string& technology) {
			m_Technology = technology;
		}

		const std::string& getProgrammingLanguage() const {
			return m_Technology;
		}

		double computeSalary() override;
	private:
		std::string m_Technology;
	};
}

#endif