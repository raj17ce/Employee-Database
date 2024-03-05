#ifndef __Department_H__
#define __Department_H__

#include <string>

namespace EmployeeDB::Model {
	class Department {
	public:
        void setName(const std::string& name) {
            m_Name = name;
        }
        void setDepartmentId(int departmentId) {
            m_DepartmentId = departmentId;
        }
        void setBaseSalary(int baseSalary) {
            m_BaseSalary = baseSalary;
        }
        void setAllowance(int allowance) {
            m_Allowance = allowance;
        }
        void setDeduction(int deduction) {
            m_Deduction = deduction;
        }

        const std::string& getName() const {
            return m_Name;
        }
        int getDepartmentId() const {
            return m_DepartmentId;
        }
        int getBaseSalary() const {
            return m_BaseSalary;
        }
        int getAllowance() const {
            return m_Allowance;
        }
        int getDeduction() const {
            return m_Deduction;
        }
	private:
        std::string m_Name;
		int m_DepartmentId;
		int m_BaseSalary;
		int m_Allowance;
		int m_Deduction;
	};
}

#endif