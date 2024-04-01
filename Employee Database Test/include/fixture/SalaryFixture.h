#ifndef __SalaryFixture_H__
#define __SalaryFixture_H__

#include "../../pch.h"
#include "./model/Salary.h"

using EmployeeDB::Model::Salary;

class SalaryFixture : public testing::Test {
public:
	void SetUp() {
		salary = std::make_unique<Salary>();
		emptySalary = std::make_unique<Salary>();

		salary->setEmployeeID(1);
		salary->setDepartmentID(1);
		salary->setBaseSalary(65000.0);
		salary->setAllowance(7000.0);
		salary->setDeduction(3000.0);
		salary->setPerformanceMetric(100.0);
		salary->setBonus(5000.0);

		emptySalary->setEmployeeID(1);
	}

	std::unique_ptr<Salary> salary;
	std::unique_ptr<Salary> emptySalary;
};

#endif