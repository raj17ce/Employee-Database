#ifndef __ValidateFixture_H__
#define __ValidateFixture_H__

#include "../../pch.h"
#include "DBManager.h"

using EmployeeDB::DBManager;

class ValidateFixture : public testing::Test {
public:
    void SetUp() {

        DBManager::instance().executeConfigQuery();

        std::string queryString = "INSERT INTO Department (\"departmentID\", \"departmentName\", \"baseSalary\", \"allowance\", \"deduction\") VALUES"
            "(1, 'Engineer', 65000, 7000, 3000),"
            "(2, 'Finance', 65000, 6000, 2500),"
            "(3, 'HR', 55000, 4000, 1500),"
            "(4, 'QA', 59000, 4800, 1900);"
            "INSERT INTO Employee(\"employeeID\", \"firstName\", \"middleName\", \"lastName\", \"dateOfBirth\", \"mobileNumber\", \"email\", \"address\", \"gender\", \"dateOfJoining\", \"departmentID\", \"mentorID\", \"performanceMetric\", \"bonus\") VALUES"
            "(1, 'David', 'Lee', 'Brown', '03-04-1993', 1234509876, 'david.brown@example.com', '345 Oak St, City, Country', 'Male', '12-11-2022', 1, NULL, 0.78, 450),"
            "(2, 'Sarah', 'Elizabeth', 'Wilson', '10-07-1995', 9876543212, 'sarah.wilson@example.com', '567 Elm St, City, Country', 'Female', '05-09-2023', 1, NULL, 0.88, 600);"
            "INSERT INTO Engineer(\"employeeID\", \"technology\") VALUES"
            "(1, 'Java'),"
            "(2, 'Python');"
            "INSERT INTO Employee(\"employeeID\", \"firstName\", \"middleName\", \"lastName\", \"dateOfBirth\", \"mobileNumber\", \"email\", \"address\", \"gender\", \"dateOfJoining\", \"departmentID\", \"mentorID\", \"performanceMetric\", \"bonus\") VALUES"
            "(3, 'Jane', 'Doe', 'Smith', '20-08-1992', 9876543211, 'jane.smith@example.com', '456 Elm St, City, Country', 'Female', '20-05-2018', 2, NULL, 0.75, 400),"
            "(4, 'Lauren', 'Ann', 'Perez', '16-07-1991', 9876543214, 'lauren.perez@example.com', '789 Oakwood St, City, Country', 'Female', '25-06-2022', 2, NULL, 0.82, 450); "
            "INSERT INTO Finance(\"employeeID\", \"accountingTool\") VALUES"
            "(3, 'Tally'),"
            "(4, 'Excel');"
            "INSERT INTO Employee(\"employeeID\", \"firstName\", \"middleName\", \"lastName\", \"dateOfBirth\", \"mobileNumber\", \"email\", \"address\", \"gender\", \"dateOfJoining\", \"departmentID\", \"mentorID\", \"performanceMetric\", \"bonus\") VALUES"
            "(5,'Michael', 'James', 'Johnson', '12-12-1985', 4567890128, 'michael.johnson@example.com', '789 Oak St, City, Country', 'Male', '05-03-2019', 3, NULL, 0.9, 600),"
            "(6,'Christopher', 'Ray', 'Martinez', '28-02-1991', 4567890129, 'chris.martinez@example.com', '789 Pine St, City, Country', 'Male', '15-03-2020', 3, NULL, 0.92, 700);"
            "INSERT INTO HR(\"employeeID\", \"hrSpecialization\") VALUES"
            "(5, 'Human Resource'),"
            "(6, 'Accounting');"
            "INSERT INTO Employee(\"employeeID\", \"firstName\", \"middleName\", \"lastName\", \"dateOfBirth\", \"mobileNumber\", \"email\", \"address\", \"gender\", \"dateOfJoining\", \"departmentID\", \"mentorID\", \"performanceMetric\", \"bonus\") VALUES"
            "(7,'Emily', 'Anne', 'Williams', '25-10-1988', 9870723456, 'emily.williams@example.com', '101 Pine St, City, Country', 'Female', '15-02-2021', 4, NULL, 0.82, 550),"
            "(8,'Jessica', 'Marie', 'Taylor', '14-09-1987', 9878123456, 'jessica.taylor@example.com', '908 Maple St, City, Country', 'Female', '25-07-2019', 4, NULL, 0.81, 500);"
            "INSERT INTO QA(\"employeeID\", \"testingTool\") VALUES"
            "(7, 'gTest'),"
            "(8, 'Jira');"
            "INSERT INTO Manager(\"managerID\", \"departmentID\", \"teamSize\", \"yearsOfExperience\", \"projectTitle\", \"role\") VALUES"
            "(1, 1, 15, 10, 'Project A', 'Java'),"
            "(3, 2, 15, 10, 'Project B', 'Tally'),"
            "(5, 3, 15, 10, 'Project C', 'Human Resource'),"
            "(7, 4, 18, 12, 'Project C', 'gTest');";

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
        DBManager::instance().executeTruncateQuery("Finance");
        DBManager::instance().executeTruncateQuery("HR");
        DBManager::instance().executeTruncateQuery("QA");
        DBManager::instance().executeTruncateQuery("Manager");
    }
};

#endif