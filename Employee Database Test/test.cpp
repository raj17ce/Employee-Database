#include "pch.h"
#include "Validate.h"

using EmployeeDB::Validate;

//TEST(TestCaseName, TestName) {
//  EXPECT_EQ(1, 1);
//  EXPECT_TRUE(true);
//}

TEST(TestValidate, TestEmail) {
	ASSERT_EQ(Validate::validateEmail("raj@gmail.com"), true);
	ASSERT_EQ(Validate::validateEmail("raj@@gmail.com"), false);
}

TEST(TestValidate, TestMobile) {
	ASSERT_EQ(Validate::validateMobile("9988557744"), true);
	ASSERT_EQ(Validate::validateMobile("1234567890"), false);
}

TEST(TestValidate, TestDate) {
	ASSERT_EQ(Validate::validateDate("29/02/2024"), true);
	ASSERT_EQ(Validate::validateDate("30/02/2024"), false);
}

TEST(TestValidate, TestGender) {
	ASSERT_EQ(Validate::validateGender(std::string{"MaLe"}), true);
	ASSERT_EQ(Validate::validateGender(std::string{ "OTherS" }), false);
}