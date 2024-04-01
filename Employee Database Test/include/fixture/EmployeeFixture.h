#ifndef __EmployeeFixture_H__
#define __EmployeeFixture_H__

#include "../../pch.h";
#include "./model/Employee.h"

using EmployeeDB::Model::Employee;
using EmployeeDB::Model::Gender;

class EmployeeFixture : public testing::Test {
public:
    void SetUp() {
        employee = std::make_unique<Employee>();
        updateEmployee = std::make_unique<Employee>(true);

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

    std::unique_ptr<Employee> employee;
    std::unique_ptr<Employee> updateEmployee;
};

#endif