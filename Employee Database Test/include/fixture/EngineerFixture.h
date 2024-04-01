#ifndef __EngineerFixture_H__
#define __EngineerFixture_H__

#include "../../pch.h"
#include "./model/Engineer.h"
#include "DBManager.h"

using EmployeeDB::Model::Engineer;
using EmployeeDB::DBManager;
using EmployeeDB::Model::Gender;

class EngineerFixture : public testing::Test {
public:
    void SetUp() {
        engineer = std::make_unique<Engineer>();
        updateEngineer = std::make_unique<Engineer>(true);

        engineer->setFirstName("John");
        engineer->setMiddleName("Doe");
        engineer->setLastName("Smith");
        engineer->setDateOfBirth("15-05-1990");
        engineer->setMobileNumber(1234567891);
        engineer->setEmail("john.smith@example.com");
        engineer->setAddress("123 Main St, City, Country");
        engineer->setGender(Gender::Male);
        engineer->setDateOfJoining("10-01-2020");
        engineer->setDepartmentID(1);
        engineer->setMentorID(1);
        engineer->setPerformanceMetric(0.85);
        engineer->setBonus(500);
        engineer->setTechnology("CPP");

        DBManager::instance().executeConfigQuery();

        std::string queryString = "INSERT INTO Department (\"departmentID\", \"departmentName\", \"baseSalary\", \"allowance\", \"deduction\") VALUES"
            "(1, 'Engineer', 65000, 7000, 3000);"
            "INSERT INTO Employee(\"employeeID\", \"firstName\", \"middleName\", \"lastName\", \"dateOfBirth\", \"mobileNumber\", \"email\", \"address\", \"gender\", \"dateOfJoining\", \"departmentID\", \"mentorID\", \"performanceMetric\", \"bonus\") VALUES"
            "(1, 'David', 'Lee', 'Brown', '03-04-1993', 1234509876, 'david.brown@example.com', '345 Oak St, City, Country', 'Male', '12-11-2022', 1, NULL, 0.78, 450),"
            "(2, 'Sarah', 'Elizabeth', 'Wilson', '10-07-1995', 9876543212, 'sarah.wilson@example.com', '567 Elm St, City, Country', 'Female', '05-09-2023', 1, NULL, 0.88, 600);"
            "INSERT INTO Engineer(\"employeeID\", \"technology\") VALUES"
            "(1, 'Java'),"
            "(2, 'Python');";

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
        DBManager::instance().executeTruncateQuery("Engineer");
    }

    std::unique_ptr<Engineer> engineer;
    std::unique_ptr<Engineer> updateEngineer;
};

#endif