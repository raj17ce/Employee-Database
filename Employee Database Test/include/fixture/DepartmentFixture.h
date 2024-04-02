#ifndef __DepartmentFixture_H__
#define __DepartmentFixture_H__

#include "../../pch.h"
#include "./model/Department.h"
#include "./DBManager.h"

using EmployeeDB::DBManager;
using EmployeeDB::Model::Department;

class DepartmentFixture : public testing::Test {
public:
    void SetUp() {
        department = std::make_unique<Department>();
        updateDepartment = std::make_unique<Department>(true);

        department->setDepartmentName("Marketing");
        department->setBaseSalary(50000.0);
        department->setAllowance(3400.0);
        department->setDeduction(1200.0);

        DBManager::instance().executeConfigQuery();

        std::string_view queryString = "INSERT INTO Department (\"departmentID\", \"departmentName\", \"baseSalary\", \"allowance\", \"deduction\") VALUES"
            "(1, 'Engineer', 65000, 7000, 3000),"
            "(2, 'Finance', 65000, 6000, 2500),"
            "(3, 'HR', 55000, 4000, 1500),"
            "(4, 'QA', 59000, 4800, 1900);";

        try {
            DBManager::instance().executeQuery(queryString.data());
        }
        catch (const std::exception& e) {
            std::cerr << "\x1B[31m" << e.what() << "\033[0m\n";
        }
    }

    void TearDown() {
        DBManager::instance().executeTruncateQuery("Department");
    }

    std::unique_ptr<Department> department;
    std::unique_ptr<Department> updateDepartment;
};
#endif