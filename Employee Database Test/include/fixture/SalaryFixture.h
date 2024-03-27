#include "../../pch.h";
#include "./model/Salary.h"

using EmployeeDB::Model::Salary;

class SalaryFixture : public testing::Test {
public:
	void SetUp() {
		salary = new Salary{};
		emptySalary = new Salary{};

		salary->setDepartmentID(1);
		salary->setBaseSalary(65000.0);
		salary->setAllowance(7000.0);
		salary->setDeduction(3000.0);
		salary->setPerformanceMetric(100.0);
		salary->setBonus(5000.0);
	}

	void TearDown() {
		delete salary;
		delete emptySalary;
	}
private:
	Salary* salary;
	Salary* emptySalary;
};