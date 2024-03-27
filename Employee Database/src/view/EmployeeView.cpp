#include <iostream>
#include "EmployeeView.h"
#include "EmployeeController.h"
#include "Validate.h"
#include "Utility.h"

using EmployeeDB::View::EmployeeView, EmployeeDB::View::Utility;
using EmployeeDB::Controller::EmployeeController;
using EmployeeDB::Validate;

void EmployeeView::printEmployeeFields() {
	std::cout << "1. firstName* : " << '\n';
	std::cout << "2. middleName : " << '\n';
	std::cout << "3. lastName* : " << '\n';
	std::cout << "4. dateOfBirth : " << '\n';
	std::cout << "5. mobileNo* : " << '\n';
	std::cout << "6. email* :" << '\n';
	std::cout << "7. address* :" << '\n';
	std::cout << "8. gender* :" << '\n';
	std::cout << "9. dateOfJoining* :" << '\n';
	std::cout << "10. mentorID :" << '\n';
	std::cout << "11. performanceMetric :" << '\n';
	std::cout << "12. bonus :" << '\n';
}

void EmployeeView::printViewEmployeeFields() {
	std::cout << "1. employeeID* : " << '\n';
	std::cout << "2. firstName* : " << '\n';
	std::cout << "3. middleName* : " << '\n';
	std::cout << "4. lastName* : " << '\n';
	std::cout << "5. dateOfBirth* : " << '\n';
	std::cout << "6. mobileNo* : " << '\n';
	std::cout << "7. email* :" << '\n';
	std::cout << "8. address* :" << '\n';
	std::cout << "9. gender* :" << '\n';
	std::cout << "10. dateOfJoining* :" << '\n';
	std::cout << "11. mentorID* :" << '\n';
	std::cout << "12. performanceMetric* :" << '\n';
	std::cout << "13. bonus* :" << '\n';
}

void EmployeeView::getInsertEmployeeInput(Employee& obj) {
	std::string userInput;

	while (true) {
		std::cout << "firstName* : ";
		std::getline(std::cin, userInput);
		Utility::removeEmptySpaces(userInput);

		if (userInput.size() == 0) {
			std::cout << "\x1B[33m" << "First Name is mandatory...Please enter again!!" << "\x1B[0m\n";
		}
		else {
			obj.setFirstName(userInput);
			break;
		}
	}

	{
		std::cout << "middleName : ";
		std::getline(std::cin, userInput);
		Utility::removeEmptySpaces(userInput);

		if (userInput.size() != 0) {
			obj.setMiddleName(userInput);
		}
	}

	while (true) {
		std::cout << "lastName* : ";
		std::getline(std::cin, userInput);
		Utility::removeEmptySpaces(userInput);

		if (userInput.size() == 0) {
			std::cout << "\x1B[33m" << "Last Name is mandatory...Please enter again!!" << "\x1B[0m\n";
		}
		else {
			obj.setLastName(userInput);
			break;
		}
	}

	{
		while (true) {
			std::cout << "dateOfBirth [dd-mm-yyyy or dd/mm/yyyy or dd.mm.yyyy] : ";
			std::getline(std::cin, userInput);
			Utility::removeEmptySpaces(userInput);

			if (userInput.size() == 0) {
				break;
			}
			if (Validate::validateDate(userInput)) {
				obj.setDateOfBirth(userInput);
				break;
			}
			else {
				std::cerr << "\x1B[33m" << "Please Enter the date in format [dd-mm-yyyy or dd/mm/yyyy or dd.mm.yyyy] : " << "\x1B[0m\n";
			}
		}
	}

	while (true) {
		std::cout << "mobileNo* (Starting from [6-9]) : ";
		std::getline(std::cin, userInput);
		Utility::removeEmptySpaces(userInput);

		if (userInput.size() == 0) {
			std::cout << "\x1B[33m" << "mobileNo is mandatory...Please enter again!!" << "\x1B[0m\n";
		}
		else {
			if (Validate::validateMobile(userInput)) {
				obj.setMobileNumber(std::stoll(userInput));
				break;
			}
			else {
				std::cerr << "\x1B[33m" << "Wrong mobileNo...Please enter again!!" << "\x1B[0m\n";
			}
		}
	}

	while (true) {
		std::cout << "email* : ";
		std::getline(std::cin, userInput);
		Utility::removeEmptySpaces(userInput);

		if (userInput.size() == 0) {
			std::cout << "\x1B[33m" << "email is mandatory...Please enter again!!" << "\x1B[0m\n";
		}
		else {
			if (Validate::validateEmail(userInput)) {
				obj.setEmail(userInput);
				break;
			}
			else {
				std::cerr << "\x1B[33m" << "Wrong email...Please enter again!!" << "\x1B[0m\n";
			}
		}
	}

	while (true) {
		std::cout << "address* : ";
		std::getline(std::cin, userInput);
		Utility::removeEmptySpaces(userInput);

		if (userInput.size() == 0) {
			std::cout << "\x1B[33m" << "Address is mandatory...Please enter again!!" << "\x1B[0m\n";
		}
		else {
			obj.setAddress(userInput);
			break;
		}
	}

	while (true) {
		std::cout << "gender* : ";
		std::getline(std::cin, userInput);
		Utility::removeEmptySpaces(userInput);

		if (userInput.size() == 0) {
			std::cout << "\x1B[33m" << "Gender is mandatory...Please enter again!!" << "\x1B[0m\n";
		}
		else {
			if (Validate::validateGender(userInput)) {
				obj.setGender(EmployeeDB::Model::getGenderFromString(userInput));
				break;
			}
			else {
				std::cerr << "\x1B[33m" << "Wrong input...Please enter again!!" << "\x1B[0m\n";
			}
		}
	}

	while (true) {
		std::cout << "dateOfJoining* [dd-mm-yyyy or dd/mm/yyyy or dd.mm.yyyy] : ";
		std::getline(std::cin, userInput);
		Utility::removeEmptySpaces(userInput);

		if (userInput.size() == 0) {
			std::cout << "\x1B[33m" << "dateOfJoining is mandatory...Please enter again!!" << "\x1B[0m\n";
		}
		else {
			if (Validate::validateDate(userInput)) {
				obj.setDateOfJoining(userInput);
				break;
			}
			else {
				std::cerr << "\x1B[33m" << "Please Enter the date in format [dd-mm-yyyy or dd/mm/yyyy or dd.mm.yyyy] : " << "\x1B[0m\n";
			}
		}
	}

	{
		while (true) {
			std::cout << "mentorID : ";
			std::getline(std::cin, userInput);
			Utility::removeEmptySpaces(userInput);

			if (userInput.size() == 0) {
				break;
			}
			try {
				if (stoi(userInput) >= 0.0) {
					obj.setMentorID(stoi(userInput));
					break;
				}
				else {
					throw "Negative Number";
				}
			}
			catch (...) {
				std::cerr << "\x1B[33m" << "Wrong input...Please enter Positive integer number!!" << "\x1B[0m\n";
			}
		}
	}

	{
		while (true) {
			std::cout << "performanceMetric : ";
			std::getline(std::cin, userInput);
			Utility::removeEmptySpaces(userInput);

			if (userInput.size() == 0) {
				break;
			}
			try {
				if (stod(userInput) >= 0.0) {
					obj.setPerformanceMetric(stod(userInput));
					break;
				}
				else {
					throw "Negative Number";
				}
			}
			catch (...) {
				std::cerr << "\x1B[33m" << "Wrong input...Please enter Positive real number!!" << "\x1B[0m\n";
			}
		}
	}

	{
		while (true) {
			std::cout << "bonus : ";
			std::getline(std::cin, userInput);
			Utility::removeEmptySpaces(userInput);

			if (userInput.size() == 0) {
				break;
			}
			try {
				if (stod(userInput) >= 0.0) {
					obj.setBonus(stod(userInput));
					break;
				}
				else {
					throw "Negative Number";
				}
			}
			catch (...) {
				std::cerr << "\x1B[33m" << "Wrong input...Please enter Positive real number!!" << "\x1B[0m\n";
			}
		}
	}
};

void EmployeeView::getUpdateEmployeeInput(Employee& obj, int fieldNumber) {
	std::string userInput;

	switch (fieldNumber) {
	case 1:
		while (true) {
			std::cout << "firstName* : ";
			std::getline(std::cin, userInput);
			Utility::removeEmptySpaces(userInput);

			if (userInput.size() == 0) {
				std::cout << "\x1B[33m" << "First Name is mandatory...Please enter again!!" << "\x1B[0m\n";
			}
			else {
				obj.setFirstName(userInput);
				break;
			}
		}
		break;
	case 2:
		{
			std::cout << "middleName : ";
			std::getline(std::cin, userInput);
			Utility::removeEmptySpaces(userInput);

			if (userInput.size() != 0) {
				obj.setMiddleName(userInput);
			}
		}
		break;
	case 3:
		while (true) {
			std::cout << "lastName* : ";
			std::getline(std::cin, userInput);
			Utility::removeEmptySpaces(userInput);

			if (userInput.size() == 0) {
				std::cout << "\x1B[33m" << "Last Name is mandatory...Please enter again!!" << "\x1B[0m\n";
			}
			else {
				obj.setLastName(userInput);
				break;
			}
		}
		break;
	case 4:
		{
			while (true) {
				std::cout << "dateOfBirth [dd-mm-yyyy or dd/mm/yyyy or dd.mm.yyyy] : ";
				std::getline(std::cin, userInput);
				Utility::removeEmptySpaces(userInput);

				if (userInput.size() == 0) {
					break;
				}
				if (Validate::validateDate(userInput)) {
					obj.setDateOfBirth(userInput);
					break;
				}
				else {
					std::cerr << "\x1B[33m" << "Please Enter the date in format [dd-mm-yyyy or dd/mm/yyyy or dd.mm.yyyy] : " << "\x1B[0m\n";
				}
			}
		}
		break;
	case 5:
		while (true) {
			std::cout << "mobileNo* (Starting from [6-9]) : ";
			std::getline(std::cin, userInput);
			Utility::removeEmptySpaces(userInput);

			if (userInput.size() == 0) {
				std::cout << "\x1B[33m" << "mobileNo is mandatory...Please enter again!!" << "\x1B[0m\n";
			}
			else {
				if (Validate::validateMobile(userInput)) {
					obj.setMobileNumber(std::stoll(userInput));
					break;
				}
				else {
					std::cerr << "\x1B[33m" << "Wrong mobileNo...Please enter again!!" << "\x1B[0m\n";
				}
			}
		}
		break;
	case 6:
		while (true) {
			std::cout << "email* : ";
			std::getline(std::cin, userInput);
			Utility::removeEmptySpaces(userInput);

			if (userInput.size() == 0) {
				std::cout << "\x1B[33m" << "email is mandatory...Please enter again!!" << "\x1B[0m\n";
			}
			else {
				if (Validate::validateEmail(userInput)) {
					obj.setEmail(userInput);
					break;
				}
				else {
					std::cerr << "\x1B[33m" << "Wrong email...Please enter again!!" << "\x1B[0m\n";
				}
			}
		}
		break;
	case 7:
		while (true) {
			std::cout << "address* : ";
			std::getline(std::cin, userInput);
			Utility::removeEmptySpaces(userInput);

			if (userInput.size() == 0) {
				std::cout << "\x1B[33m" << "Address is mandatory...Please enter again!!" << "\x1B[0m\n";
			}
			else {
				obj.setAddress(userInput);
				break;
			}
		}
		break;
	case 8:
		while (true) {
			std::cout << "gender* : ";
			std::getline(std::cin, userInput);
			Utility::removeEmptySpaces(userInput);

			if (userInput.size() == 0) {
				std::cout << "\x1B[33m" << "Gender is mandatory...Please enter again!!" << "\x1B[0m\n";
			}
			else {
				if (Validate::validateGender(userInput)) {
					obj.setGender(EmployeeDB::Model::getGenderFromString(userInput));
					break;
				}
				else {
					std::cerr << "\x1B[33m" << "Wrong input...Please enter again!!" << "\x1B[0m\n";
				}
			}
		}
		break;
	case 9:
		while (true) {
			std::cout << "dateOfJoining* [dd-mm-yyyy or dd/mm/yyyy or dd.mm.yyyy] : ";
			std::getline(std::cin, userInput);
			Utility::removeEmptySpaces(userInput);

			if (userInput.size() == 0) {
				std::cout << "\x1B[33m" << "dateOfJoining is mandatory...Please enter again!!" << "\x1B[0m\n";
			}
			else {
				if (Validate::validateDate(userInput)) {
					obj.setDateOfJoining(userInput);
					break;
				}
				else {
					std::cerr << "\x1B[33m" << "Please Enter the date in format [dd-mm-yyyy or dd/mm/yyyy or dd.mm.yyyy] : " << "\x1B[0m\n";
				}
			}
		}
		break;
	case 10:
		{
			while (true) {
				std::cout << "mentorID : ";
				std::getline(std::cin, userInput);
				Utility::removeEmptySpaces(userInput);

				if (userInput.size() == 0) {
					break;
				}
				try {
					if (stoi(userInput) >= 0.0) {
						obj.setMentorID(stoi(userInput));
						break;
					}
					else {
						throw "Negative Number";
					}
				}
				catch (...) {
					std::cerr << "\x1B[33m" << "Wrong input...Please enter Positive integer number!!" << "\x1B[0m\n";
				}
			}
		}
		break;
	case 11:
		{
			while (true) {
				std::cout << "performanceMetric : ";
				std::getline(std::cin, userInput);
				Utility::removeEmptySpaces(userInput);

				if (userInput.size() == 0) {
					break;
				}
				try {
					if (stod(userInput) >= 0.0) {
						obj.setPerformanceMetric(stod(userInput));
						break;
					}
					else {
						throw "Negative Number";
					}
				}
				catch (...) {
					std::cerr << "\x1B[33m" << "Wrong input...Please enter Positive real number!!" << "\x1B[0m\n";
				}
			}
		}
		break;
	case 12:
		{
			while (true) {
				std::cout << "bonus : ";
				std::getline(std::cin, userInput);
				Utility::removeEmptySpaces(userInput);

				if (userInput.size() == 0) {
					break;
				}
				try {
					if (stod(userInput) >= 0.0) {
						obj.setBonus(stod(userInput));
						break;
					}
					else {
						throw "Negative Number";
					}
				}
				catch (...) {
					std::cerr << "\x1B[33m" << "Wrong input...Please enter Positive real number!!" << "\x1B[0m\n";
				}
			}
		}
		break;
	}
};

void EmployeeView::getViewEmployeeInput(Employee& obj, int fieldNumber) {
	std::string userInput;

	switch (fieldNumber) {
	case 1:
		while (true) {
			std::cout << "employeeID* : ";
			std::getline(std::cin, userInput);
			Utility::removeEmptySpaces(userInput);

			if (userInput.size() == 0) {
				std::cout << "\x1B[33m" << "employeeID is mandatory...Please enter again!!" << "\x1B[0m\n";
			}
			else {
				try {
					if (stoi(userInput) > 0) {
						obj.setEmployeeID(stoi(userInput));
					}
					else {
						throw "Negative Number";
					}
				}
				catch (...) {
					std::cout << "\x1B[33m" << "Wrong input...Please enter again!!" << "\x1B[0m\n";
					continue;
				}
				break;
			}
		}
		break;
	case 2:
		while (true) {
			std::cout << "firstName* : ";
			std::getline(std::cin, userInput);
			Utility::removeEmptySpaces(userInput);

			if (userInput.size() == 0) {
				std::cout << "\x1B[33m" << "First Name is mandatory...Please enter again!!" << "\x1B[0m\n";
			}
			else {
				obj.setFirstName(userInput);
				break;
			}
		}
		break;
	case 3:
		while (true) {
			std::cout << "middleName* : ";
			std::getline(std::cin, userInput);
			Utility::removeEmptySpaces(userInput);

			if (userInput.size() == 0) {
				std::cout << "\x1B[33m" << "middleName is mandatory...Please enter again!!" << "\x1B[0m\n";
			}
			else {
				obj.setMiddleName(userInput);
				break;
			}
		}
		break;
	case 4:
		while (true) {
			std::cout << "lastName* : ";
			std::getline(std::cin, userInput);
			Utility::removeEmptySpaces(userInput);

			if (userInput.size() == 0) {
				std::cout << "\x1B[33m" << "Last Name is mandatory...Please enter again!!" << "\x1B[0m\n";
			}
			else {
				obj.setLastName(userInput);
				break;
			}
		}
		break;
	case 5:
		while (true) {
			std::cout << "dateOfBirth* [dd-mm-yyyy or dd/mm/yyyy or dd.mm.yyyy] : ";
			std::getline(std::cin, userInput);
			Utility::removeEmptySpaces(userInput);

			if (userInput.size() == 0) {
				std::cout << "\x1B[33m" << "dateOfBirth is mandatory...Please enter again!!" << "\x1B[0m\n";
			}
			else {
				if (Validate::validateDate(userInput)) {
					obj.setDateOfBirth(userInput);
					break;
				}
				else {
					std::cerr << "\x1B[33m" << "Please Enter the date in format [dd-mm-yyyy or dd/mm/yyyy or dd.mm.yyyy] : " << "\x1B[0m\n";
				}
			}
		}
		break;
	case 6:
		while (true) {
			std::cout << "mobileNo* (Starting from [6-9]) : ";
			std::getline(std::cin, userInput);
			Utility::removeEmptySpaces(userInput);

			if (userInput.size() == 0) {
				std::cout << "\x1B[33m" << "mobileNo is mandatory...Please enter again!!" << "\x1B[0m\n";
			}
			else {
				if (Validate::validateMobile(userInput)) {
					obj.setMobileNumber(std::stoll(userInput));
					break;
				}
				else {
					std::cerr << "\x1B[33m" << "Wrong mobileNo...Please enter again!!" << "\x1B[0m\n";
				}
			}
		}
		break;
	case 7:
		while (true) {
			std::cout << "email* : ";
			std::getline(std::cin, userInput);
			Utility::removeEmptySpaces(userInput);

			if (userInput.size() == 0) {
				std::cout << "\x1B[33m" << "email is mandatory...Please enter again!!" << "\x1B[0m\n";
			}
			else {
				if (Validate::validateEmail(userInput)) {
					obj.setEmail(userInput);
					break;
				}
				else {
					std::cerr << "\x1B[33m" << "Wrong email...Please enter again!!" << "\x1B[0m\n";
				}
			}
		}
		break;
	case 8:
		while (true) {
			std::cout << "address* : ";
			std::getline(std::cin, userInput);
			Utility::removeEmptySpaces(userInput);

			if (userInput.size() == 0) {
				std::cout << "\x1B[33m" << "Address is mandatory...Please enter again!!" << "\x1B[0m\n";
			}
			else {
				obj.setAddress(userInput);
				break;
			}
		}
		break;
	case 9:
		while (true) {
			std::cout << "gender* : ";
			std::getline(std::cin, userInput);
			Utility::removeEmptySpaces(userInput);

			if (userInput.size() == 0) {
				std::cout << "\x1B[33m" << "Gender is mandatory...Please enter again!!" << "\x1B[0m\n";
			}
			else {
				if (Validate::validateGender(userInput)) {
					obj.setGender(EmployeeDB::Model::getGenderFromString(userInput));
					break;
				}
				else {
					std::cerr << "\x1B[33m" << "Wrong input...Please enter again!!" << "\x1B[0m\n";
				}
			}
		}
		break;
	case 10:
		while (true) {
			std::cout << "dateOfJoining* [dd-mm-yyyy or dd/mm/yyyy or dd.mm.yyyy] : ";
			std::getline(std::cin, userInput);
			Utility::removeEmptySpaces(userInput);

			if (userInput.size() == 0) {
				std::cout << "\x1B[33m" << "dateOfJoining is mandatory...Please enter again!!" << "\x1B[0m\n";
			}
			else {
				if (Validate::validateDate(userInput)) {
					obj.setDateOfJoining(userInput);
					break;
				}
				else {
					std::cerr << "\x1B[33m" << "Please Enter the date in format [dd-mm-yyyy or dd/mm/yyyy or dd.mm.yyyy] : " << "\x1B[0m\n";
				}
			}
		}
		break;
	case 11:
		while (true) {
			std::cout << "mentorID* : ";
			std::getline(std::cin, userInput);
			Utility::removeEmptySpaces(userInput);

			if (userInput.size() == 0) {
				std::cout << "\x1B[33m" << "mentorID is mandatory...Please enter again!!" << "\x1B[0m\n";
			}
			else {
				try {
					if (stoi(userInput) > 0) {
						obj.setMentorID(stoi(userInput));
					}
					else {
						throw "Negative Number";
					}
				}
				catch (...) {
					std::cout << "\x1B[33m" << "Wrong input...Please enter again!!" << "\x1B[0m\n";
					continue;
				}
				break;
			}
		}
		break;
	case 12:
		while (true) {
			std::cout << "performanceMetric* : ";
			std::getline(std::cin, userInput);
			Utility::removeEmptySpaces(userInput);

			if (userInput.size() == 0) {
				std::cout << "\x1B[33m" << "performanceMetric is mandatory...Please enter again!!" << "\x1B[0m\n";
			}
			else {
				try {
					if (stod(userInput) > 0.0) {
						obj.setPerformanceMetric(stoi(userInput));
					}
					else {
						throw "Negative Number";
					}
				}
				catch (...) {
					std::cout << "\x1B[33m" << "Wrong input...Please enter again!!" << "\x1B[0m\n";
					continue;
				}
				break;
			}
		}
		break;
	case 13:
		while (true) {
			std::cout << "bonus* : ";
			std::getline(std::cin, userInput);
			Utility::removeEmptySpaces(userInput);

			if (userInput.size() == 0) {
				std::cout << "\x1B[33m" << "bonus is mandatory...Please enter again!!" << "\x1B[0m\n";
			}
			else {
				try {
					if (stod(userInput) > 0.0) {
						obj.setBonus(stoi(userInput));
					}
					else {
						throw "Negative Number";
					}
				}
				catch (...) {
					std::cout << "\x1B[33m" << "Wrong input...Please enter again!!" << "\x1B[0m\n";
					continue;
				}
				break;
			}
		}
		break;
	}
};

void EmployeeView::getEmployeeIDInput(Employee& obj, const std::string& operation, const std::string& entity) {
	std::string userInput;

	system("cls");
	std::cout << "------------------------------------------" << "\x1B[36m" << operation << " " + entity << "\x1B[0m" << "-------------------------------------------------\n";
	std::cout << "\x1B[33m" << "To " + operation + " " + entity + ", please enter employeeID." << "\x1B[0m\n";

	while (true) {
		std::cout << "employeeID* : ";
		std::getline(std::cin, userInput);
		Utility::removeEmptySpaces(userInput);

		if (userInput.size() == 0) {
			std::cout << "\x1B[33m" << "employeeID is mandatory...Please enter again!!" << "\x1B[0m\n";
		}
		else {
			if (Validate::validateEmployeeID(userInput, entity)) {
				obj.setEmployeeID(stoi(userInput));
				break;
			}
			else {
				std::cout << "\x1B[33m" << "Wrong input...Please enter positive integer number!!" << "\x1B[0m\n";
			}
		}
	}
}