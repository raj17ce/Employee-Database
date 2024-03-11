#ifndef __Manager_H__
#define __Manager_H__

#include "Employee.h"

namespace EmployeeDB::Model {
	class Manager : public Employee {
	public:
		void setProjectTitle(const std::string& projectTitle) {
			m_ProjectTitle = projectTitle;
		}
		void setTechnology(const std::string& technology) {
			m_Technology = technology;
		}
		void setYearsOfExperience(double yearsOfExperience) {
			m_YearsOfExperience = yearsOfExperience;
		}
		void setManagerID(int managerID) {
			m_ManagerID = managerID;
		}
		void setDepartmentID(int departmentID) {
			m_DepartmentID = departmentID;
		}
		void setTeamSize(int teamSize) {
			m_TeamSize = teamSize;
		}

		const std::string& getProjectTitle() const {
			return m_ProjectTitle;
		}
		const std::string& getTechnology() const {
			return m_Technology;
		}
		double getYearsOfExperience() const {
			return m_YearsOfExperience;
		}
		int getManagerID() const {
			return m_ManagerID;
		}
		int getDepartmentID() const {
			return m_DepartmentID;
		}
		int getTeamSize() const {
			return m_TeamSize;
		}

		double computeSalary() override;
	private:
		std::string m_ProjectTitle;
		std::string m_Technology;
		double m_YearsOfExperience;
		int m_ManagerID;
		int m_DepartmentID;
		int m_TeamSize;
	};
}

#endif