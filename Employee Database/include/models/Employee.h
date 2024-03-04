#ifndef __Employee_H__
#define __Employee_H__

#include "Config.h";

namespace EmployeeDB::Model {

	enum class Gender {
		Male,
		Female,
		Other
	};

	class Employee {
	public:
        void setFirstName(const std::string& firstName) {
            m_FirstName = firstName;
        }
        void setMiddleName(const std::string& middleName) {
            m_MiddleName = middleName;
        }
        void setLastName(const std::string& lastName) {
            m_LastName = lastName;
        }
        void setEmail(const std::string& email) {
            m_Email = email;
        }
        void setAddress(const std::string& address) {
            m_Address = address;
        }
        void setPerformanceMetric(double performanceMetric) {
            m_PerformanceMetric = performanceMetric;
        }
        // TODO: Setters for DateOfBirth and DateOfJoining
        void setMobileNumber(long mobileNumber) {
            m_MobileNumber = mobileNumber;
        }
        void setGender(Gender gender) {
            m_Gender = gender;
        }
        void setEmployeeId(int employeeId) {
            m_EmployeeId = employeeId;
        }
        void setDepartmentId(int departmentId) {
            m_DepartmentId = departmentId;
        }
        void setManagerId(int managerId) {
            m_ManagerId = managerId;
        }
        void setBonus(int bonus) {
            m_Bonus = bonus;
        }

        const std::string& getFirstName() const {
            return m_FirstName;
        }
        const std::string& getMiddleName() const {
            return m_MiddleName;
        }
        const std::string& getLastName() const {
            return m_LastName;
        }
        const std::string& getEmail() const {
            return m_Email;
        }
        const std::string& getAddress() const {
            return m_Address;
        }
        double getPerformanceMetric() const {
            return m_PerformanceMetric;
        }
        // TODO: Getters for DateOfBirth and DateOfJoining
        long getMobileNumber() const {
            return m_MobileNumber;
        }
        Gender getGender() const {
            return m_Gender;
        }
        int getEmployeeId() const {
            return m_EmployeeId;
        }
        int getDepartmentId() const {
            return m_DepartmentId;
        }
        int getManagerId() const {
            return m_ManagerId;
        }
        int getBonus() const {
            return m_Bonus;
        }

		virtual double computeSalary();
	private:
		std::string m_FirstName;
		std::string m_MiddleName;
		std::string m_LastName;
        std::string m_Email;
        std::string m_Address;
		double m_PerformanceMetric;
		//to-do m_DateOFBirth;
		//to-do m_DateOfJoining;
		long m_MobileNumber;
		Gender m_Gender;
		int m_EmployeeId;
		int m_DepartmentId;
		int m_ManagerId;
		int m_Bonus;
	};
}

#endif