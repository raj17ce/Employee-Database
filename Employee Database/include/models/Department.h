#ifndef __Department_H__
#define __Department_H__

#include <string>

namespace EmployeeDB::Model {
	class Department {
	public:
        void setDepartmentName(const std::string& name) {
            m_DepartmentName = name;
        }
        void setDepartmentID(int departmentID) {
            m_DepartmentID = departmentID;
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

        const std::string& getDepartmentName() const {
            return m_DepartmentName;
        }
        int getDepartmentID() const {
            return m_DepartmentID;
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
        std::string m_DepartmentName;
		int m_DepartmentID;
		int m_BaseSalary;
		int m_Allowance;
		int m_Deduction;
	};
}

#endif