#ifndef __ManagerFixture_H__
#define __ManagerFixture_H__

#include "../../pch.h"
#include "./model/Manager.h"
#include "DBManager.h"

using EmployeeDB::Model::Manager;
using EmployeeDB::Model::Gender;
using EmployeeDB::DBManager;

class ManagerFixture : public testing::Test {
public:
    void SetUp() {
        manager = std::make_unique<Manager>();
        updateManager = std::make_unique<Manager>(true);

        manager->setManagerID(3);
        manager->setDepartmentID(2);
        manager->setTeamSize(15);
        manager->setYearsOfExperience(10.0);
        manager->setProjectTitle("Project Z");
        manager->setRole("Excel");

        DBManager::instance().executeConfigQuery();

        std::string_view queryString = "INSERT INTO Department (\"departmentID\", \"departmentName\", \"baseSalary\", \"allowance\", \"deduction\") VALUES"
            "(1, 'Engineer', 65000, 7000, 3000),"
            "(2, 'Finance', 62000, 8000, 4000);"
            "INSERT INTO Employee(\"employeeID\", \"firstName\", \"middleName\", \"lastName\", \"dateOfBirth\", \"mobileNumber\", \"email\", \"address\", \"gender\", \"dateOfJoining\", \"departmentID\", \"mentorID\", \"performanceMetric\", \"bonus\") VALUES"
            "(1, 'David', 'Lee', 'Brown', '03-04-1993', 1234509876, 'david.brown@example.com', '345 Oak St, City, Country', 'Male', '12-11-2022', 1, NULL, 0.78, 450),"
            "(2, 'Sarah', 'Elizabeth', 'Wilson', '10-07-1995', 9876543212, 'sarah.wilson@example.com', '567 Elm St, City, Country', 'Female', '05-09-2023', 1, NULL, 0.88, 600),"
            "(3, 'Jane', 'Doe', 'Smith', '20-08-1992', 9876543211, 'jane.smith@example.com', '456 Elm St, City, Country', 'Female', '20-05-2018', 2, NULL, 0.75, 400);"
            "INSERT INTO Manager(\"managerID\", \"departmentID\", \"teamSize\", \"yearsOfExperience\", \"projectTitle\", \"role\") VALUES"
            "(1, 1, 15, 10, 'Project A', 'Java'),"
            "(2, 1, 18, 12, 'Project E', 'C#');";

        try {
            DBManager::instance().executeQuery(queryString.data());
        }
        catch (const std::exception& e) {
            std::cerr << "\x1B[31m" << e.what() << "\033[0m\n";
        }
    }

    void TearDown() {
        DBManager::instance().executeTruncateQuery("Department");
        DBManager::instance().executeTruncateQuery("Employee");
        DBManager::instance().executeTruncateQuery("Engineer");
        DBManager::instance().executeTruncateQuery("Manager");
    }

    std::unique_ptr<Manager> manager;
    std::unique_ptr<Manager> updateManager;
};

#endif