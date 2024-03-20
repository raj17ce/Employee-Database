#include <string>
#include <iostream>
#include <regex>
#include <exception>
#include "Validate.h"
#include "EmployeeController.h"

using EmployeeDB::Validate;
using EmployeeDB::Controller::EmployeeController;


bool Validate::validateEmail(const std::string& email) {
	return std::regex_match(email, std::regex("(^[a-zA-Z0-9.]+@([a-zA-Z0-9\\-]+.)+[a-zA-Z0-9]{2,4}$)"));
}

bool Validate::validateMobile(const std::string& number) {
	return std::regex_match(number, std::regex("(^[6-9]{1}[0-9]{9}$)"));
}

bool Validate::validateDate(const std::string& date) {
    return std::regex_match(date,std::regex(R"(^(?:(?:31(\/|-|\.)(?:0?[13578]|1[02]))\1|(?:(?:29|30)(\/|-|\.)(?:0?[13-9]|1[0-2])\2))(?:(?:1[6-9]|[2-9]\d)?\d{2})$|^(?:29(\/|-|\.)0?2\3(?:(?:(?:1[6-9]|[2-9]\d)?(?:0[48]|[2468][048]|[13579][26])|(?:(?:16|[2468][048]|[3579][26])00))))$|^(?:0?[1-9]|1\d|2[0-8])(\/|-|\.)(?:(?:0?[1-9])|(?:1[0-2]))\4(?:(?:1[6-9]|[2-9]\d)?\d{2})$)"));
}

bool Validate::validateGender(std::string& gender) {
	std::transform(gender.begin(), gender.end(), gender.begin(), ::tolower);
	return (gender == "male" || gender == "female" || gender == "other");
}

bool Validate::validateManagerID(const std::string& managerID) {
	bool regexResult = std::regex_match(managerID, std::regex("(^[0-9]+$)"));

	if (!regexResult) {
		return false;
	}

	return EmployeeController::checkEmployeeExistence(managerID);
}