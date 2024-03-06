#ifndef __Manager_H__
#define __Manager_H__

#include "Employee.h"

namespace EmployeeDB::Model {
	class Manager : public Employee {
	public:
		void setProjectTitle(const std::string& projectTitle) {
			m_ProjectTitle = projectTitle;
		}
		void setRole(const std::string& role) {
			m_Role = role;
		}
		void setYearsOfExperience(double yearsOfExperience) {
			m_YearsOfExperience = yearsOfExperience;
		}
		void setManagerId(int managerId) {
			m_ManagerId = managerId;
		}
		void setTeamSize(int teamSize) {
			m_TeamSize = teamSize;
		}

		const std::string& getProjectTitle() const {
			return m_ProjectTitle;
		}
		const std::string& getRole() const {
			return m_Role;
		}
		double getYearsOfExperience() const {
			return m_YearsOfExperience;
		}
		int getManagerId() const {
			return m_ManagerId;
		}
		int getTeamSize() const {
			return m_TeamSize;
		}

		double computeSalary() override;
	private:
		std::string m_ProjectTitle;
		std::string m_Role;
		double m_YearsOfExperience;
		int m_ManagerId;
		int m_TeamSize;
	};
}

#endif