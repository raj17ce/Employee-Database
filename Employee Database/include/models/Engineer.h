#ifndef __Engineer_H__
#define __Engineer_H__

#include "Employee.h"

namespace EmployeeDB::Model {

	class Engineer : public Employee {
	public:
		void setTechnology(const std::string& technology) {
			m_Technology = technology;
		}

		const std::string& getTechnology() const {
			return m_Technology;
		}

		double computeSalary() override {
			return 10.2;
		};
	private:
		std::string m_Technology;
	};
}

#endif