#include <iostream>
#include "ManagerView.h"
#include "Utility.h"
#include "ManagerController.h"
#include "Validate.h"

using EmployeeDB::View::ManagerView, EmployeeDB::View::Utility;
using EmployeeDB::Controller::ManagerController;
using EmployeeDB::Validate;

void ManagerView::printManagerFields() {
	std::cout << "Fields with * are required fields\n";
	std::cout << "1. managerID* (employeeID) : " << '\n';
	std::cout << "2. teamSize* : " << '\n';
	std::cout << "3. yearsOfExperience* : " << '\n';
	std::cout << "4. projectTitle : " << '\n';
	std::cout << "5. role : " << '\n';
}

void ManagerView::getInsertManagerInput(Manager& obj) {
	std::string userInput;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	while (true) {
		std::cout << "managerID* : ";
		char userChoice = std::cin.get();
		if (userChoice == '\n') {
			std::cout << "managerID is mandatory...Please enter again!!" << '\n';
		}
		else {
			std::getline(std::cin, userInput);
			userInput = userChoice + userInput;

			if (Validate::validateManagerID(userInput)) {
				obj.setManagerID(stoi(userInput));
				break;
			}
			else {
				std::cout << "Wrong input...Please enter positive integer number!!\n";
			}
		}
	}

	while (true) {
		std::cout << "teamSize* : ";
		char userChoice = std::cin.get();
		if (userChoice == '\n') {
			std::cout << "teamSize is mandatory...Please enter again!!" << '\n';
		}
		else {
			std::getline(std::cin, userInput);
			userInput = userChoice + userInput;
			try {
				if (std::stoi(userInput) >= 0) {
					obj.setTeamSize(std::stoi(userInput));
				}
				else {
					throw "Negative Number";
				}
			}
			catch (...) {
				std::cout << "Wrong input...Please enter positive integer number!!\n";
				continue;
			}
			break;
		}
	}

	while (true) {
		std::cout << "yearsOfExperience* : ";
		char userChoice = std::cin.get();
		if (userChoice == '\n') {
			std::cout << "yearsOfExperience is mandatory...Please enter again!!" << '\n';
		}
		else {
			std::getline(std::cin, userInput);
			userInput = userChoice + userInput;
			try {
				if (std::stod(userInput) >= 0.0) {
					obj.setYearsOfExperience(std::stod(userInput));
				}
				else {
					throw "Negative Number";
				}
			}
			catch (...) {
				std::cout << "Wrong input...Please enter positive real number!!\n";
				continue;
			}
			break;
		}
	}

	{
		std::cout << "projectTitle : ";
		char userChoice = std::cin.get();

		if (userChoice != '\n') {
			std::getline(std::cin, userInput);
			userInput = userChoice + userInput;
			obj.setProjectTitle(userInput);
		}
	}

	{
		std::cout << "role : ";
		char userChoice = std::cin.get();

		if (userChoice != '\n') {
			std::getline(std::cin, userInput);
			userInput = userChoice + userInput;
			obj.setRole(userInput);
		}
	}
};

bool ManagerView::insertManager() {
	Manager obj;

	system("cls");
	std::cout << "------------------------------------------Insert Manager-------------------------------------------------\n";
	printManagerFields();

	if (!Utility::proceedFurther("insertion")) {
		return false;
	}

	getInsertManagerInput(obj);
	ManagerController::insertManager(obj);

	return Utility::repeatOperation("Manager");
}