#ifndef __QAFixture_H__
#define __QAFixture_H__

#include "../../pch.h"
#include "./model/QA.h"
#include "DBManager.h"

using EmployeeDB::Model::QA;
using EmployeeDB::Model::Gender;
using EmployeeDB::DBManager;

class QAFixture : public testing::Test {
public:
    void SetUp() {
        qa = std::make_unique<QA>();
        updateQa = std::make_unique<QA>(true);

        qa->setFirstName("Emily");
        qa->setMiddleName("Anne");
        qa->setLastName("Williams");
        qa->setDateOfBirth("25-10-1988");
        qa->setMobileNumber(9870723456);
        qa->setEmail("emily.williams@example.com");
        qa->setAddress("101 Pine St, City, Country");
        qa->setGender(Gender::Female);
        qa->setDateOfJoining("15-02-2021");
        qa->setDepartmentID(1);
        qa->setMentorID(1);
        qa->setPerformanceMetric(0.82);
        qa->setBonus(550);

        qa->setTestingTool("Selenium");

        DBManager::instance().executeConfigQuery();

        std::string_view queryString = "INSERT INTO Department (\"departmentID\", \"departmentName\", \"baseSalary\", \"allowance\", \"deduction\") VALUES"
            "(1, 'QA', 65000, 7000, 3000);"
            "INSERT INTO Employee(\"employeeID\", \"firstName\", \"middleName\", \"lastName\", \"dateOfBirth\", \"mobileNumber\", \"email\", \"address\", \"gender\", \"dateOfJoining\", \"departmentID\", \"mentorID\", \"performanceMetric\", \"bonus\") VALUES"
            "(1, 'David', 'Lee', 'Brown', '03-04-1993', 1234509876, 'david.brown@example.com', '345 Oak St, City, Country', 'Male', '12-11-2022', 1, NULL, 0.78, 450),"
            "(2, 'Sarah', 'Elizabeth', 'Wilson', '10-07-1995', 9876543212, 'sarah.wilson@example.com', '567 Elm St, City, Country', 'Female', '05-09-2023', 1, NULL, 0.88, 600);"
            "INSERT INTO QA(\"employeeID\", \"testingTool\") VALUES"
            "(1, 'gTest'),"
            "(2, 'Jira');";

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
        DBManager::instance().executeTruncateQuery("QA");
    }

    std::unique_ptr<QA> qa;
    std::unique_ptr<QA> updateQa;
};

#endif