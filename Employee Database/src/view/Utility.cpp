#include <iostream>
#include "Utility.h"

using EmployeeDB::View::Utility;

bool Utility::proceedFurther(const std::string& operation) {
	auto isInvalidInput{ false };

	while (true) {
		if (!isInvalidInput) {
			std::cout << "\x1B[33m" << "Do you want to proceed with "+ operation +"? [y/n] : " << "\x1B[0m";
		}

		std::string inputLine;
		std::getline(std::cin, inputLine);
		removeEmptySpaces(inputLine);

		if (inputLine.size() == 1 && (inputLine[0] == 'y' || inputLine[0] == 'Y')) {
			return true;
		}
		else if (inputLine.size() == 1 && (inputLine[0] == 'n' || inputLine[0] == 'N')) {
			return false;
		}
		else {
			std::cerr << "\x1B[33m" << "Wrong Input, Please enter character [y/n] : " << "\x1B[0m";
			isInvalidInput = true;
		}
	}

	return false;
}

bool Utility::repeatOperation(const std::string& operation, const std::string& Entity) {
	auto isInvalidInput = false;

	while (true) {
		if (!isInvalidInput) {
			std::cout << "\x1B[33m" << "Do you want to "+ operation + " another " + Entity +"? [y / n] : " << "\x1B[0m";
		}
		
		std::string inputLine;
		std::getline(std::cin, inputLine);
		removeEmptySpaces(inputLine);

		if (inputLine.size() == 1 && (inputLine[0] == 'y' || inputLine[0] == 'Y')) {
			return true;
		}
		else if (inputLine.size() == 1 && (inputLine[0] == 'n' || inputLine[0] == 'N')) {
			return false;
		}
		else {
			std::cerr << "\x1B[33m" << "Wrong Input, Please enter character [y/n] : " << "\x1B[0m";
			isInvalidInput = true;
		}
	}

	return false;
}

void Utility::removeEmptySpaces(std::string& str, const std::string& chars) {
	if (str.size() == 0) {
		return;
	}
	else {
		str.erase(str.find_last_not_of(chars) + 1);
		str.erase(0, str.find_first_not_of(chars));

		std::string tempStr;
		auto preSpace{ false };
		auto i{ 0 };
		while (i < str.size()) {
			if (str.at(i) != ' ') {
				if (preSpace) {
					tempStr += ' ';
				}
				tempStr += str.at(i);
				preSpace = false;
			}
			else {
				preSpace = true;
			}
			++i;
		}
		str = std::move(tempStr);
	}
}