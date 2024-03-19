#include <iostream>
#include "Utility.h"

using EmployeeDB::View::Utility;

bool Utility::proceedFurther(const std::string& operation) {
	bool isInvalidInput{ false };

	while (true) {
		if (!isInvalidInput) {
			std::cout << "Do you want to proceed with "+ operation +"? [y/n] : ";
		}
		unsigned char userChoice;
		std::cin >> userChoice;

		if (userChoice == 'y' || userChoice == 'Y') {
			return true;
		}
		else if (userChoice == 'n' || userChoice == 'N') {
			return false;
		}
		else {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cerr << "Wrong Input, Please enter character [y/n] : ";
			isInvalidInput = true;
		}
	}

	return false;
}
bool Utility::repeatOperation(const std::string& Entity) {
	bool isInvalidInput = false;

	while (true) {
		if (!isInvalidInput) {
			std::cout << "Do you want to insert another "+ Entity +"? [y/n] : ";
		}
		unsigned char userChoice;
		std::cin >> userChoice;

		if (userChoice == 'y' || userChoice == 'Y') {
			return true;
		}
		else if (userChoice == 'n' || userChoice == 'N') {
			return false;
		}
		else {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cerr << "Wrong Input, Please enter character [y/n] : ";
			isInvalidInput = true;
		}
	}

	return false;
}