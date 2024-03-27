#include "pch.h"
#include "Validate.h"

using EmployeeDB::Validate;

TEST(TestValidateEmail, ValidateEmailTrue) {
	ASSERT_EQ(Validate::validateEmail("hello@gmail.com"), true);
	ASSERT_EQ(Validate::validateEmail("hello@gmail.co.uk"), true);
	ASSERT_EQ(Validate::validateEmail("hello.hii@gmail.com"), true);
	ASSERT_EQ(Validate::validateEmail("hello123@gmail.shop.in"), true);
	ASSERT_EQ(Validate::validateEmail("123hello@gmail.com"), true);
}

TEST(TestValidateEmail, ValidateEmailFalse) {
	ASSERT_EQ(Validate::validateEmail("hello@@gmail.com"), false);
	ASSERT_EQ(Validate::validateEmail("hello@gmai$l.couk"), false);
	ASSERT_EQ(Validate::validateEmail("hello-hiii@gmail.com"), false);
	ASSERT_EQ(Validate::validateEmail("hello123$@gmail.shop.in"), false);
	ASSERT_EQ(Validate::validateEmail("123-alan@gmail.co.in.kom"), false);
}

TEST(TestValidateMobile, ValidateMobileTrue) {
	ASSERT_EQ(Validate::validateMobile("9875445568"), true);
	ASSERT_EQ(Validate::validateMobile("9521364578"), true);
	ASSERT_EQ(Validate::validateMobile("6548752369"), true);
	ASSERT_EQ(Validate::validateMobile("7230154030"), true);
	ASSERT_EQ(Validate::validateMobile("8080406085"), true);
}

TEST(TestValidateMobile, ValidateMobileFalse) {
	ASSERT_EQ(Validate::validateMobile("1234567989"), false);
	ASSERT_EQ(Validate::validateMobile("9876"), false);
	ASSERT_EQ(Validate::validateMobile("3920254252"), false);
	ASSERT_EQ(Validate::validateMobile("8530157511111"), false);
	ASSERT_EQ(Validate::validateMobile("2635458545"), false);
}

TEST(TestValidateDate, ValidateDateTrue) {
	ASSERT_EQ(Validate::validateDate("17/04/2003"), true);
	ASSERT_EQ(Validate::validateDate("17-04-2003"), true);
	ASSERT_EQ(Validate::validateDate("17.04.2003"), true);
	ASSERT_EQ(Validate::validateDate("29/02/2024"), true);
	ASSERT_EQ(Validate::validateDate("31/12/2024"), true);
}

TEST(TestValidateDate, ValidateDateFalse) {
	ASSERT_EQ(Validate::validateDate("17/04-2003"), false);
	ASSERT_EQ(Validate::validateDate("17.13.2003"), false);
	ASSERT_EQ(Validate::validateDate("31/04/2003"), false);
	ASSERT_EQ(Validate::validateDate("29/02/2023"), false);
	ASSERT_EQ(Validate::validateDate("32/12/2024"), false);
}

TEST(TestValidateGender, ValidateGenderTrue) {
	ASSERT_EQ(Validate::validateGender(std::string{ "Male" }), true);
	ASSERT_EQ(Validate::validateGender(std::string{ "Female" }), true);
	ASSERT_EQ(Validate::validateGender(std::string{ "Other" }), true);
	ASSERT_EQ(Validate::validateGender(std::string{ "mAlE" }), true);
	ASSERT_EQ(Validate::validateGender(std::string{ "FeMaLe" }), true);
}

TEST(TestValidateGender, ValidateGenderFalse) {
	ASSERT_EQ(Validate::validateGender(std::string{ "Malee" }), false);
	ASSERT_EQ(Validate::validateGender(std::string{ "females" }), false);
	ASSERT_EQ(Validate::validateGender(std::string{ "Otherl" }), false);
	ASSERT_EQ(Validate::validateGender(std::string{ "    " }), false);
	ASSERT_EQ(Validate::validateGender(std::string{ "femalles" }), false);
}

TEST(TestValidateEmployeeID, ValidateEmployeeIDTrue) {
	ASSERT_EQ(Validate::validateEmployeeID("1","Engineer"), true);
	ASSERT_EQ(Validate::validateEmployeeID("8","Finance"), true);
	ASSERT_EQ(Validate::validateEmployeeID("15","HR"), true);
	ASSERT_EQ(Validate::validateEmployeeID("22","QA"), true);
	ASSERT_EQ(Validate::validateEmployeeID("5","Engineer"), true);
}

TEST(TestValidateEmployeeID, ValidateEmployeeIDFalse) {
	ASSERT_EQ(Validate::validateEmployeeID("1", "Finance"), false);
	ASSERT_EQ(Validate::validateEmployeeID("8", "Engineer"), false);
	ASSERT_EQ(Validate::validateEmployeeID("150", "HR"), false);
	ASSERT_EQ(Validate::validateEmployeeID("20", "QA"), false);
	ASSERT_EQ(Validate::validateEmployeeID("50", "Engineer"), false);
}

TEST(TestValidateManagerID, ValidateManagerIDTrue) {
	ASSERT_EQ(Validate::validateManagerID("1"), true);
	ASSERT_EQ(Validate::validateManagerID("8"), true);
	ASSERT_EQ(Validate::validateManagerID("15"), true);
	ASSERT_EQ(Validate::validateManagerID("23"), true);
	ASSERT_EQ(Validate::validateManagerID("5"), true);
}

TEST(TestValidateManagerID, ValidateManagerIDFalse) {
	ASSERT_EQ(Validate::validateManagerID("10"), false);
	ASSERT_EQ(Validate::validateManagerID("800"), false);
	ASSERT_EQ(Validate::validateManagerID("-5"), false);
	ASSERT_EQ(Validate::validateManagerID("Hello"), false);
	ASSERT_EQ(Validate::validateManagerID("25"), false);
}

TEST(TestValidateDepartmentID, ValidateDepartmentIDTrue) {
	ASSERT_EQ(Validate::validateDepartmentID("1"), true);
	ASSERT_EQ(Validate::validateDepartmentID("2"), true);
	ASSERT_EQ(Validate::validateDepartmentID("3"), true);
	ASSERT_EQ(Validate::validateDepartmentID("4"), true);
}

TEST(TestValidateDepartmentID, ValidateDepartmentIDFalse) {
	ASSERT_EQ(Validate::validateDepartmentID("-1"), false);
	ASSERT_EQ(Validate::validateDepartmentID("0"), false);
	ASSERT_EQ(Validate::validateDepartmentID("300"), false);
	ASSERT_EQ(Validate::validateDepartmentID("4Hello"), false);
}