#include "pch.h"
#include "Validate.h"

using EmployeeDB::Validate;

//TEST(TestCaseName, TestName) {
//  EXPECT_EQ(1, 1);
//  EXPECT_TRUE(true);
//}

TEST(TestValidateEmail, TestEmail) {
	ASSERT_EQ(Validate::validateEmail("raj@@gmail.com"), true);
}