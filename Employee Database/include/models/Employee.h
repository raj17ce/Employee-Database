#ifndef __Employee_H__
#define __Employee_H__

#include <string>

namespace EmployeeDB::Model {

	enum class Gender {
		Male,
		Female,
		Other
	};

    inline std::string getGenderString(Gender g) {
        std::string tempStr{ "Male" };
        switch (g) {
        case EmployeeDB::Model::Gender::Male:
            break;
        case EmployeeDB::Model::Gender::Female:
            tempStr = "Female";
            break;
        case EmployeeDB::Model::Gender::Other:
            tempStr = "Other";
            break;
        }
        return tempStr;
    }

	class Employee {
	public:
        Employee() = default;
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
        void setDateOfBirth(const std::string& dateOfBirth) {
            m_DateOfBirth = dateOfBirth;
        }
        void setDateOfJoining(const std::string& dateOfJoining) {
            m_DateOfJoining = dateOfJoining;
        }
        void setPerformanceMetric(double performanceMetric) {
            m_PerformanceMetric = performanceMetric;
        }
        void setMobileNumber(long long mobileNumber) {
            m_MobileNumber = mobileNumber;
        }
        void setGender(Gender gender) {
            m_Gender = gender;
        }
        void setEmployeeID(int employeeID) {
            m_EmployeeID = employeeID;
        }
        void setDepartmentID(int departmentID) {
            m_DepartmentID = departmentID;
        }
        void setManagerID(int managerID) {
            m_ManagerID = managerID;
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
        const std::string& getDateOfBirth() const {
            return m_DateOfBirth;
        }
        const std::string& getDateOfJoining() const {
            return m_DateOfJoining;
        }
        double getPerformanceMetric() const {
            return m_PerformanceMetric;
        }
        long long getMobileNumber() const {
            return m_MobileNumber;
        }
        Gender getGender() const {
            return m_Gender;
        }
        int getEmployeeID() const {
            return m_EmployeeID;
        }
        int getDepartmentID() const {
            return m_DepartmentID;
        }
        int getManagerID() const {
            return m_ManagerID;
        }
        int getBonus() const {
            return m_Bonus;
        }

        virtual double computeSalary() { return 10.2; };
	private:
		std::string m_FirstName;
		std::string m_MiddleName;
		std::string m_LastName;
        std::string m_Email;
        std::string m_Address;
        std::string m_DateOfBirth;
        std::string  m_DateOfJoining;
		double m_PerformanceMetric;
		long long m_MobileNumber;
		Gender m_Gender;
		int m_EmployeeID;
		int m_DepartmentID;
		int m_ManagerID;
		int m_Bonus;
	};
}

#endif