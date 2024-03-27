#include "../../pch.h";
#include "./model/Employee.h"

using EmployeeDB::Model::Employee;
using EmployeeDB::Model::Gender;

class EmployeeFixture : public testing::Test {
public:
    void SetUp() {
        employee = new Employee{};
        emptyEmployee = new Employee{};

        employee->setFirstName("John");
        employee->setMiddleName("Doe");
        employee->setLastName("Smith");
        employee->setDateOfBirth("15-05-1990");
        employee->setMobileNumber(1234567891);
        employee->setEmail("john.smith@example.com");
        employee->setAddress("123 Main St, City, Country");
        employee->setGender(Gender::Male);
        employee->setDateOfJoining("10-01-2020");
        employee->setDepartmentID(1);
        employee->setMentorID(0);
        employee->setPerformanceMetric(0.85);
        employee->setBonus(500.0);
    }

    void TearDown() {
        delete employee;
        delete emptyEmployee;
    }

private:
    Employee* employee;
    Employee* emptyEmployee;
};