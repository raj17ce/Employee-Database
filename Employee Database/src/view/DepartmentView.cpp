#include <iostream>
#include "DepartmentView.h"
#include "Utility.h"
#include "DepartmentController.h"
#include "Validate.h"

using EmployeeDB::View::DepartmentView, EmployeeDB::View::Utility;
using EmployeeDB::Controller::DepartmentController;
using EmployeeDB::Validate;

void DepartmentView::printDepartmentFields() {
	std::cout << "Fields with * are required fields\n";
	std::cout << "1. departmentName* : " << '\n';
	std::cout << "2. baseSalary* : " << '\n';
	std::cout << "3. allowance* : " << '\n';
	std::cout << "4. deduction* : " << '\n';
}

void DepartmentView::getInsertDepartmentInput(Department& obj) {
	std::string userInput;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	while (true) {
		std::cout << "departmentName* : ";
		char userChoice = std::cin.get();
		if (userChoice == '\n') {
			std::cout << "departmentName is mandatory...Please enter again!!" << '\n';
		}
		else {
			std::getline(std::cin, userInput);
			userInput = userChoice + userInput;

			obj.setDepartmentName(userInput);
			break;
		}
	}

	while (true) {
		std::cout << "baseSalary* : ";
		char userChoice = std::cin.get();
		if (userChoice == '\n') {
			std::cout << "baseSalary is mandatory...Please enter again!!" << '\n';
		}
		else {
			std::getline(std::cin, userInput);
			userInput = userChoice + userInput;
			try {
				if (stod(userInput) >= 0.0) {
					obj.setBaseSalary(stod(userInput));
				}
				else {
					throw "Negative Number";
				}
			}
			catch (...) {
				std::cout << "Wrong input...Please enter Positive real number!!\n";
				continue;
			}
			break;
		}
	}

	while (true) {
		std::cout << "allowance* : ";
		char userChoice = std::cin.get();
		if (userChoice == '\n') {
			std::cout << "allowance is mandatory...Please enter again!!" << '\n';
		}
		else {
			std::getline(std::cin, userInput);
			userInput = userChoice + userInput;
			try {
				if (stod(userInput) >= 0.0) {
					obj.setAllowance(stod(userInput));
				}
				else {
					throw "Negative Number";
				}
			}
			catch (...) {
				std::cout << "Wrong input...Please Positive enter real number!!\n";
				continue;
			}
			break;
		}
	}

	while (true) {
		std::cout << "deduction* : ";
		char userChoice = std::cin.get();
		if (userChoice == '\n') {
			std::cout << "deduction is mandatory...Please enter again!!" << '\n';
		}
		else {
			std::getline(std::cin, userInput);
			userInput = userChoice + userInput;
			try {
				if (stod(userInput) >= 0.0) {
					obj.setDeduction(stod(userInput));
				}
				else {
					throw "Negative Number";
				}
			}
			catch (...) {
				std::cerr << "Wrong input...Please enter Positive real number!!\n";
			}
			break;
		}
	}
};

bool DepartmentView::insertDepartment() {
	Department obj;

	system("cls");
	std::cout << "------------------------------------------Insert Department-------------------------------------------------\n";
	printDepartmentFields();

	if (!Utility::proceedFurther("insertion")) {
		return false;
	}

	getInsertDepartmentInput(obj);
	DepartmentController::insertDepartment(obj);

	return Utility::repeatOperation("Department");
}