#ifndef __HRFixture_H__
#define __HRFixture_H__

#include "../../pch.h"
#include "./model/HR.h"
#include "DBManager.h"

using EmployeeDB::Model::HR;
using EmployeeDB::Model::Gender;
using EmployeeDB::DBManager;

class HRFixture : public testing::Test {
public:
    void SetUp() {
        hr = std::make_unique<HR>();
        updateHr = std::make_unique<HR>(true);

        hr->setFirstName("Michael");
        hr->setMiddleName("James");
        hr->setLastName("Johnson");
        hr->setDateOfBirth("12-12-1985");
        hr->setMobileNumber(4567890128);
        hr->setEmail("michael.johnson@example.com");
        hr->setAddress("789 Oak St, City, Country");
        hr->setGender(Gender::Male);
        hr->setDateOfJoining("05-03-2019");
        hr->setDepartmentID(1);
        hr->setMentorID(1);
        hr->setPerformanceMetric(0.9);
        hr->setBonus(600);

        hr->setHRSpecialization("Recruitment");

        DBManager::instance().executeConfigQuery();

        std::string queryString = "INSERT INTO Department (\"departmentID\", \"departmentName\", \"baseSalary\", \"allowance\", \"deduction\") VALUES"
            "(1, 'HR', 65000, 7000, 3000);"
            "INSERT INTO Employee(\"employeeID\", \"firstName\", \"middleName\", \"lastName\", \"dateOfBirth\", \"mobileNumber\", \"email\", \"address\", \"gender\", \"dateOfJoining\", \"departmentID\", \"mentorID\", \"performanceMetric\", \"bonus\") VALUES"
            "(1, 'David', 'Lee', 'Brown', '03-04-1993', 1234509876, 'david.brown@example.com', '345 Oak St, City, Country', 'Male', '12-11-2022', 1, NULL, 0.78, 450),"
            "(2, 'Sarah', 'Elizabeth', 'Wilson', '10-07-1995', 9876543212, 'sarah.wilson@example.com', '567 Elm St, City, Country', 'Female', '05-09-2023', 1, NULL, 0.88, 600);"
            "INSERT INTO HR(\"employeeID\", \"hrSpecialization\") VALUES"
            "(1, 'Human Resource'),"
            "(2, 'Accounting');";

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
        DBManager::instance().executeTruncateQuery("HR");
    }

    std::unique_ptr<HR> hr;
    std::unique_ptr<HR> updateHr;
};

#endif