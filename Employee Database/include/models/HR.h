#ifndef __HR_H__
#define __HR_H__

#include "Employee.h";

namespace EmployeeDB::Model {
	class HR : public Employee {
	public:
		void setHRSpecialization(const std::string& specialization) {
			m_HRSpecialization = specialization;
		}

		const std::string& getHRSpecialization() const {
			return m_HRSpecialization;
		}

		double computeSalary() override;
	private:
		std::string m_HRSpecialization;
	};
}

#endif