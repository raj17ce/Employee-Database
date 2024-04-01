#include "pch.h"
#include "Validate.h"

using EmployeeDB::Validate;

TEST(TestValidateEmail, ValidateEmailTrue) {
	ASSERT_TRUE(Validate::validateEmail("hello@gmail.com"));
	ASSERT_TRUE(Validate::validateEmail("hello@gmail.co.uk"));
	ASSERT_TRUE(Validate::validateEmail("hello.hii@gmail.com"));
	ASSERT_TRUE(Validate::validateEmail("hello123@gmail.shop.in"));
	ASSERT_TRUE(Validate::validateEmail("123hello@gmail.com"));
}

TEST(TestValidateEmail, ValidateEmailFalse) {
	ASSERT_FALSE(Validate::validateEmail("hello@@gmail.com"));
	ASSERT_FALSE(Validate::validateEmail("hello@gmai$l.couk"));
	ASSERT_FALSE(Validate::validateEmail("hello-hiii@gmail.com"));
	ASSERT_FALSE(Validate::validateEmail("hello123$@gmail.shop.in"));
	ASSERT_FALSE(Validate::validateEmail("123-alan@gmail.co.in.kom"));
}

TEST(TestValidateMobile, ValidateMobileTrue) {
	ASSERT_TRUE(Validate::validateMobile("9875445568"));
	ASSERT_TRUE(Validate::validateMobile("9521364578"));
	ASSERT_TRUE(Validate::validateMobile("6548752369"));
	ASSERT_TRUE(Validate::validateMobile("7230154030"));
	ASSERT_TRUE(Validate::validateMobile("8080406085"));
}

TEST(TestValidateMobile, ValidateMobileFalse) {
	ASSERT_FALSE(Validate::validateMobile("1234567989"));
	ASSERT_FALSE(Validate::validateMobile("9876"));
	ASSERT_FALSE(Validate::validateMobile("3920254252"));
	ASSERT_FALSE(Validate::validateMobile("8530157511111"));
	ASSERT_FALSE(Validate::validateMobile("2635458545"));
}

TEST(TestValidateDate, ValidateDateTrue) {
	ASSERT_TRUE(Validate::validateDate("17/04/2003"));
	ASSERT_TRUE(Validate::validateDate("17-04-2003"));
	ASSERT_TRUE(Validate::validateDate("17.04.2003"));
	ASSERT_TRUE(Validate::validateDate("29/02/2024"));
	ASSERT_TRUE(Validate::validateDate("31/12/2024"));
}

TEST(TestValidateDate, ValidateDateFalse) {
	ASSERT_FALSE(Validate::validateDate("17/04-2003"));
	ASSERT_FALSE(Validate::validateDate("17.13.2003"));
	ASSERT_FALSE(Validate::validateDate("31/04/2003"));
	ASSERT_FALSE(Validate::validateDate("29/02/2023"));
	ASSERT_FALSE(Validate::validateDate("32/12/2024"));
}

TEST(TestValidateGender, ValidateGenderTrue) {
	ASSERT_TRUE(Validate::validateGender(std::string{ "Male" }));
	ASSERT_TRUE(Validate::validateGender(std::string{ "Female" }));
	ASSERT_TRUE(Validate::validateGender(std::string{ "Other" }));
	ASSERT_TRUE(Validate::validateGender(std::string{ "mAlE" }));
	ASSERT_TRUE(Validate::validateGender(std::string{ "FeMaLe" }));
}

TEST(TestValidateGender, ValidateGenderFalse) {
	ASSERT_FALSE(Validate::validateGender(std::string{ "Malee" }));
	ASSERT_FALSE(Validate::validateGender(std::string{ "females" }));
	ASSERT_FALSE(Validate::validateGender(std::string{ "Otherl" }));
	ASSERT_FALSE(Validate::validateGender(std::string{ "    " }));
	ASSERT_FALSE(Validate::validateGender(std::string{ "femalles" }));
}

//TEST(TestValidateEmployeeID, ValidateEmployeeIDTrue) {
//	ASSERT_TRUE(Validate::validateEmployeeID("1","Engineer"));
//	ASSERT_TRUE(Validate::validateEmployeeID("8","Finance"));
//	ASSERT_TRUE(Validate::validateEmployeeID("15","HR"));
//	ASSERT_TRUE(Validate::validateEmployeeID("22","QA"));
//	ASSERT_TRUE(Validate::validateEmployeeID("5","Engineer"));
//}
//
//TEST(TestValidateEmployeeID, ValidateEmployeeIDFalse) {
//	ASSERT_FALSE(Validate::validateEmployeeID("1", "Finance"));
//	ASSERT_FALSE(Validate::validateEmployeeID("8", "Engineer"));
//	ASSERT_FALSE(Validate::validateEmployeeID("150", "HR"));
//	ASSERT_FALSE(Validate::validateEmployeeID("20", "QA"));
//	ASSERT_FALSE(Validate::validateEmployeeID("50", "Engineer"));
//}
//
//TEST(TestValidateManagerID, ValidateManagerIDTrue) {
//	ASSERT_TRUE(Validate::validateManagerID("1"));
//	ASSERT_TRUE(Validate::validateManagerID("8"));
//	ASSERT_TRUE(Validate::validateManagerID("15"));
//	ASSERT_TRUE(Validate::validateManagerID("23"));
//	ASSERT_TRUE(Validate::validateManagerID("5"));
//}
//
//TEST(TestValidateManagerID, ValidateManagerIDFalse) {
//	ASSERT_FALSE(Validate::validateManagerID("10"));
//	ASSERT_FALSE(Validate::validateManagerID("800"));
//	ASSERT_FALSE(Validate::validateManagerID("-5"));
//	ASSERT_FALSE(Validate::validateManagerID("Hello"));
//	ASSERT_FALSE(Validate::validateManagerID("25"));
//}
//
//TEST(TestValidateDepartmentID, ValidateDepartmentIDTrue) {
//	ASSERT_TRUE(Validate::validateDepartmentID("1"));
//	ASSERT_TRUE(Validate::validateDepartmentID("2"));
//	ASSERT_TRUE(Validate::validateDepartmentID("3"));
//	ASSERT_TRUE(Validate::validateDepartmentID("4"));
//}
//
//TEST(TestValidateDepartmentID, ValidateDepartmentIDFalse) {
//	ASSERT_FALSE(Validate::validateDepartmentID("-1"));
//	ASSERT_FALSE(Validate::validateDepartmentID("0"));
//	ASSERT_FALSE(Validate::validateDepartmentID("300"));
//	ASSERT_FALSE(Validate::validateDepartmentID("4Hello"));
//}