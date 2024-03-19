#ifndef __Manager_H__
#define __Manager_H__

#include "Employee.h"

namespace EmployeeDB::Model {
	class Manager : public Employee {
	public:
		Manager() :
			m_ProjectTitle{""},
			m_Role{""},
			m_YearsOfExperience{ 0.0 },
			m_ManagerID{ 0 },
			m_TeamSize{ 0 } {
		}

		Manager(bool isUpdateObj) :
			m_ProjectTitle{ "#" },
			m_Role{ "#" },
			m_YearsOfExperience{ -1.0 },
			m_ManagerID{ -1 },
			m_TeamSize{ -1 } {
		}
		void setProjectTitle(const std::string& projectTitle) {
			m_ProjectTitle = projectTitle;
		}
		void setRole(const std::string& role) {
			m_Role = role;
		}
		void setYearsOfExperience(double yearsOfExperience) {
			m_YearsOfExperience = yearsOfExperience;
		}
		void setManagerID(int managerID) {
			m_ManagerID = managerID;
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
		int getManagerID() const {
			return m_ManagerID;
		}
		int getTeamSize() const {
			return m_TeamSize;
		}

		double computeSalary() override {
			return 10.2;
		};
	private:
		std::string m_ProjectTitle;
		std::string m_Role;
		double m_YearsOfExperience;
		int m_ManagerID;
		int m_TeamSize;
	};
}

#endif