#include "SalaryFixture.h"
#include "../../pch.h"

TEST_F(SalaryFixture, computeSalaryEmpty) {
	ASSERT_DOUBLE_EQ(0.0, emptySalary->computeSalary());
}

TEST_F(SalaryFixture, computeSalaryNonEmpty) {
	ASSERT_DOUBLE_EQ(128600.00, salary->computeSalary());

	salary->setPerformanceMetric(0.0);
	ASSERT_DOUBLE_EQ(74000.00, salary->computeSalary());
}