#ifndef __FinanceFixture_H__
#define __FinanceFixture_H__

#include "../../pch.h"
#include "./model/Finance.h"
#include "DBManager.h"

using EmployeeDB::Model::Finance;
using EmployeeDB::Model::Gender;
using EmployeeDB::DBManager;

class FinanceFixture : public testing::Test {
public:
    void SetUp() {
        finance = std::make_unique<Finance>();
        updateFinance = std::make_unique<Finance>(true);

        finance->setFirstName("Jane");
        finance->setMiddleName("Doe");
        finance->setLastName("Smith");
        finance->setDateOfBirth("20-08-1992");
        finance->setMobileNumber(9876543211);
        finance->setEmail("jane.smith@example.com");
        finance->setAddress("456 Elm St, City, Country");
        finance->setGender(Gender::Female);
        finance->setDateOfJoining("20-05-2018");
        finance->setDepartmentID(1);
        finance->setMentorID(1);
        finance->setPerformanceMetric(0.75);
        finance->setBonus(400);

        finance->setAccountingTool("QuickBooks");

        DBManager::instance().executeConfigQuery();

        std::string_view queryString = "INSERT INTO Department (\"departmentID\", \"departmentName\", \"baseSalary\", \"allowance\", \"deduction\") VALUES"
            "(1, 'Finance', 65000, 7000, 3000);"
            "INSERT INTO Employee(\"employeeID\", \"firstName\", \"middleName\", \"lastName\", \"dateOfBirth\", \"mobileNumber\", \"email\", \"address\", \"gender\", \"dateOfJoining\", \"departmentID\", \"mentorID\", \"performanceMetric\", \"bonus\") VALUES"
            "(1, 'David', 'Lee', 'Brown', '03-04-1993', 1234509876, 'david.brown@example.com', '345 Oak St, City, Country', 'Male', '12-11-2022', 1, NULL, 0.78, 450),"
            "(2, 'Sarah', 'Elizabeth', 'Wilson', '10-07-1995', 9876543212, 'sarah.wilson@example.com', '567 Elm St, City, Country', 'Female', '05-09-2023', 1, NULL, 0.88, 600);"
            "INSERT INTO Finance(\"employeeID\", \"accountingTool\") VALUES"
            "(1, 'Tally'),"
            "(2, 'Excel');";

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
        DBManager::instance().executeTruncateQuery("Finance");
    }

    std::unique_ptr<Finance> finance;
    std::unique_ptr<Finance> updateFinance;
};

#endif