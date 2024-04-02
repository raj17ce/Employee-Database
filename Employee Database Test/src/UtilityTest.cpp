#include "Utility.h"
#include "../pch.h"

using EmployeeDB::View::Utility;

TEST(TestRemoveEmptySpaces, removeEmptySpacesEmpty) {
	std::string emptyString{ "" };
	Utility::removeEmptySpaces(emptyString);

	ASSERT_STREQ("", emptyString.c_str());
}

TEST(TestRemoveEmptySpaces, removeEmptySpacesNonEmpty) {
	std::string stringToTest{ " \n\v\f\rHello , xyz" };

	Utility::removeEmptySpaces(stringToTest);
	ASSERT_STREQ("Hello , xyz", stringToTest.c_str());

	stringToTest = " Hello     Hiii   ";
	Utility::removeEmptySpaces(stringToTest);
	ASSERT_STREQ("Hello Hiii", stringToTest.c_str());
}

TEST(TestRemoveEmptySpaces, removeEmptySpacesMultiSpaces) {
	std::string stringToTest { " Hello     Hiii   "};
	Utility::removeEmptySpaces(stringToTest);

	ASSERT_STREQ("Hello Hiii", stringToTest.c_str());
}