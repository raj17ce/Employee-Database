#ifndef __EmployeeFixture_H__
#define __EmployeeFixture_H__

#include "../../pch.h"
#include "./model/Employee.h"
#include "DBManager.h"

using EmployeeDB::Model::Employee;
using EmployeeDB::Model::Gender;
using EmployeeDB::DBManager;

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
        employee->setPerformanceMetric(0.85);
        employee->setBonus(500.0);

        DBManager::instance().executeConfigQuery();

        std::string queryString = "INSERT INTO Department (\"departmentID\", \"departmentName\", \"baseSalary\", \"allowance\", \"deduction\") VALUES"
            "(1, 'Engineer', 65000, 7000, 3000),"
            "(2, 'Finance', 65000, 6000, 2500),"
            "(3, 'HR', 55000, 4000, 1500),"
            "(4, 'QA', 59000, 4800, 1900);"
            "INSERT INTO Employee(\"employeeID\", \"firstName\", \"middleName\", \"lastName\", \"dateOfBirth\", \"mobileNumber\", \"email\", \"address\", \"gender\", \"dateOfJoining\", \"departmentID\", \"mentorID\", \"performanceMetric\", \"bonus\") VALUES"
            "(1, 'David', 'Lee', 'Brown', '03-04-1993', 1234509876, 'david.brown@example.com', '345 Oak St, City, Country', 'Male', '12-11-2022', 1, NULL, 0.78, 450),"
            "(2, 'Sarah', 'Elizabeth', 'Wilson', '10-07-1995', 9876543212, 'sarah.wilson@example.com', '567 Elm St, City, Country', 'Female', '05-09-2023', 2, NULL, 0.88, 600),"
            "(3, 'Christopher', 'Ray', 'Martinez', '28-02-1991', 4567890129, 'chris.martinez@example.com', '789 Pine St, City, Country', 'Male', '15-03-2020', 3, NULL, 0.92, 700),"
            "(4, 'Jessica', 'Marie', 'Taylor', '14-09-1987', 9878123456, 'jessica.taylor@example.com', '908 Maple St, City, Country', 'Female', '25-07-2019', 4, NULL, 0.81, 500);";

        try {
            DBManager::instance().executeQuery(queryString.c_str());
        }
        catch (const std::exception& e) {
            std::cerr << "\x1B[31m" << e.what() << "\033[0m\n";
        }
    }

    void TearDown() {
        DBManager::instance().executeTruncateQuery("Department");
        DBManager::instance().executeTruncateQuery("Employee");
    }

    std::unique_ptr<Employee> employee;
    std::unique_ptr<Employee> updateEmployee;
};

#endif