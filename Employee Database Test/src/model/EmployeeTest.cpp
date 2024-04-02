#include "../../pch.h"
#include "Employee.h"

using EmployeeDB::Model::Employee;
using EmployeeDB::Model::Gender;

TEST(TestgetGenderFromString, getGenderFromStringSuccess) {
	ASSERT_EQ(Gender::Male, EmployeeDB::Model::getGenderFromString(std::string{ "Male" }));
	ASSERT_EQ(Gender::Male, EmployeeDB::Model::getGenderFromString(std::string{ "maLE" }));
	ASSERT_EQ(Gender::Female, EmployeeDB::Model::getGenderFromString(std::string{ "feMaLe" }));
	ASSERT_EQ(Gender::Female, EmployeeDB::Model::getGenderFromString(std::string{ "FEMALE" }));
	ASSERT_EQ(Gender::Other, EmployeeDB::Model::getGenderFromString(std::string{ "other" }));
	ASSERT_EQ(Gender::Other, EmployeeDB::Model::getGenderFromString(std::string{ "OtheR" }));
}

TEST(TestgetGenderFromString, getGenderFromStringFailure) {
	ASSERT_NE(Gender::Male, EmployeeDB::Model::getGenderFromString(std::string{ "Malee" }));
	ASSERT_NE(Gender::Male, EmployeeDB::Model::getGenderFromString(std::string{ "maaLE" }));
	ASSERT_NE(Gender::Female, EmployeeDB::Model::getGenderFromString(std::string{ "feeMaLe" }));
	ASSERT_NE(Gender::Female, EmployeeDB::Model::getGenderFromString(std::string{ "FEMALEe" }));
	ASSERT_NE(Gender::Other, EmployeeDB::Model::getGenderFromString(std::string{ "others" }));
	ASSERT_NE(Gender::Other, EmployeeDB::Model::getGenderFromString(std::string{ "oOtheR" }));
}

TEST(TestgetGenderString, getGenderStringEmpty) {
	ASSERT_STREQ("", EmployeeDB::Model::getGenderString(Gender::Default).c_str());
}

TEST(TestgetGenderString, getGenderStringNonEmpty) {
	ASSERT_STREQ("Male", EmployeeDB::Model::getGenderString(Gender::Male).c_str());
	ASSERT_STREQ("Female", EmployeeDB::Model::getGenderString(Gender::Female).c_str());
	ASSERT_STREQ("Other", EmployeeDB::Model::getGenderString(Gender::Other).c_str());
}