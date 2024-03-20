#include "../pch.h"
#include "gtest/gtest.h"
#include "./model/Employee.h"

class EmployeeFixture : public testing::Test {
protected:
	void SetUp() {

	}

	EmployeeDB::Model::Employee obj;
};