#include "../../pch.h";
#include "./model/Department.h"

using EmployeeDB::Model::Department;

class DepartmentFixture : public testing::Test {
public:
    void SetUp() {
        department = new Department{};
        emptyDepartment = new Department{};

        department->setDepartmentName("Engineering");
        department->setDepartmentID(1);
        department->setBaseSalary(65000.0);
        department->setAllowance(7000.0);
        department->setDeduction(3000.0);
    }

    void TearDown()  {
        delete department;
        delete emptyDepartment;
    }
private:
    Department* department;
    Department* emptyDepartment;
};