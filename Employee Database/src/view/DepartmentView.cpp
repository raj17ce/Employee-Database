#include <iostream>
#include "DepartmentView.h"
#include "Utility.h"
#include "DepartmentController.h"
#include "Validate.h"

using EmployeeDB::View::DepartmentView, EmployeeDB::View::Utility;
using EmployeeDB::Controller::DepartmentController;
using EmployeeDB::Validate;

void DepartmentView::printDepartmentFields() {
	std::cout << "1. departmentName* : " << '\n';
	std::cout << "2. baseSalary* : " << '\n';
	std::cout << "3. allowance* : " << '\n';
	std::cout << "4. deduction* : " << '\n';
}

void DepartmentView::printViewDepartmentFields() {
	std::cout << "1. departmentID* : " << '\n';
	std::cout << "2. departmentName* : " << '\n';
	std::cout << "3. baseSalary* : " << '\n';
	std::cout << "4. allowance* : " << '\n';
	std::cout << "5. deduction* : " << '\n';
}

void DepartmentView::getInsertDepartmentInput(Department& obj) {
	std::string userInput;

	while (true) {
		std::cout << "departmentName* : ";
		std::getline(std::cin, userInput);
		Utility::removeEmptySpaces(userInput);

		if (userInput.size() == 0) {
			std::cout << "\x1B[33m" << "departmentName is mandatory...Please enter again!!" << "\x1B[0m\n";
		}
		else {
			obj.setDepartmentName(userInput);
			break;
		}
	}

	while (true) {
		std::cout << "baseSalary* : ";
		std::getline(std::cin, userInput);
		Utility::removeEmptySpaces(userInput);

		if (userInput.size() == 0) {
			std::cout << "\x1B[33m" << "baseSalary is mandatory...Please enter again!!" << "\x1B[0m\n";
		}
		else {
			try {
				if (stod(userInput) >= 0.0) {
					obj.setBaseSalary(stod(userInput));
				}
				else {
					throw "Negative Number";
				}
			}
			catch (...) {
				std::cout << "\x1B[33m" << "Wrong input...Please enter Positive real number!!" << "\x1B[0m\n";
				continue;
			}
			break;
		}
	}

	while (true) {
		std::cout << "allowance* : ";
		std::getline(std::cin, userInput);
		Utility::removeEmptySpaces(userInput);

		if (userInput.size() == 0) {
			std::cout << "\x1B[33m" << "allowance is mandatory...Please enter again!!" << "\x1B[0m\n";
		}
		else {
			try {
				if (stod(userInput) >= 0.0) {
					obj.setAllowance(stod(userInput));
				}
				else {
					throw "Negative Number";
				}
			}
			catch (...) {
				std::cout << "\x1B[33m" << "Wrong input...Please Positive enter real number!!" << "\x1B[0m\n";
				continue;
			}
			break;
		}
	}

	while (true) {
		std::cout << "deduction* : ";
		std::getline(std::cin, userInput);
		Utility::removeEmptySpaces(userInput);

		if (userInput.size() == 0) {
			std::cout << "\x1B[33m" << "deduction is mandatory...Please enter again!!" << "\x1B[0m\n";
		}
		else {
			try {
				if (stod(userInput) >= 0.0) {
					obj.setDeduction(stod(userInput));
				}
				else {
					throw "Negative Number";
				}
			}
			catch (...) {
				std::cerr << "\x1B[33m" << "Wrong input...Please enter Positive real number!!" << "\x1B[0m\n";
				continue;
			}
			break;
		}
	}
};

bool DepartmentView::insertDepartment() {
	Department obj;

	system("cls");
	std::cout << "------------------------------------------" << "\x1B[36m" << "Insert Department" << "\x1B[0m" << "-------------------------------------------------\n";
	std::cout << "\x1B[36m" << "Fields with * are required fields" << "\x1B[0m\n";
	printDepartmentFields();

	if (!Utility::proceedFurther("insertion")) {
		return false;
	}

	getInsertDepartmentInput(obj);
	DepartmentController::insertDepartment(obj);

	return Utility::repeatOperation("insert", "Department");
}

void DepartmentView::getUpdateDepartmentInput(Department& obj, int fieldNumber) {
	std::string userInput;

	switch (fieldNumber) {
		case 1:
			while (true) {
				std::cout << "departmentName* : ";
				std::getline(std::cin, userInput);
				Utility::removeEmptySpaces(userInput);

				if (userInput.size() == 0) {
					std::cout << "\x1B[33m" << "departmentName is mandatory...Please enter again!!" << "\x1B[0m\n";
				}
				else {
					obj.setDepartmentName(userInput);
					break;
				}
			}
			break;

		case 2:
			while (true) {
				std::cout << "baseSalary* : ";
				std::getline(std::cin, userInput);
				Utility::removeEmptySpaces(userInput);

				if (userInput.size() == 0) {
					std::cout << "\x1B[33m" << "baseSalary is mandatory...Please enter again!!" << "\x1B[0m\n";
				}
				else {
					try {
						if (stod(userInput) >= 0.0) {
							obj.setBaseSalary(stod(userInput));
						}
						else {
							throw "Negative Number";
						}
					}
					catch (...) {
						std::cout << "\x1B[33m" << "Wrong input...Please enter Positive real number!!" << "\x1B[0m\n";
						continue;
					}
					break;
				}
			}
			break;

		case 3:
			while (true) {
				std::cout << "allowance* : ";
				std::getline(std::cin, userInput);
				Utility::removeEmptySpaces(userInput);

				if (userInput.size() == 0) {
					std::cout << "\x1B[33m" << "allowance is mandatory...Please enter again!!" << "\x1B[0m\n";
				}
				else {
					try {
						if (stod(userInput) >= 0.0) {
							obj.setAllowance(stod(userInput));
						}
						else {
							throw "Negative Number";
						}
					}
					catch (...) {
						std::cout << "\x1B[33m" << "Wrong input...Please Positive enter real number!!" << "\x1B[0m\n";
						continue;
					}
					break;
				}
			}
			break;

		case 4:
			while (true) {
				std::cout << "deduction* : ";
				std::getline(std::cin, userInput);
				Utility::removeEmptySpaces(userInput);

				if (userInput.size() == 0) {
					std::cout << "\x1B[33m" << "deduction is mandatory...Please enter again!!" << "\x1B[0m\n";
				}
				else {
					try {
						if (stod(userInput) >= 0.0) {
							obj.setDeduction(stod(userInput));
						}
						else {
							throw "Negative Number";
						}
					}
					catch (...) {
						std::cerr << "\x1B[33m" << "Wrong input...Please enter Positive real number!!" << "\x1B[0m\n";
						continue;
					}
					break;
				}
			}
			break;
	}
}

void DepartmentView::getViewDepartmentInput(Department& obj, int fieldNumber) {
	std::string userInput;

	switch (fieldNumber) {
	case 1:
		while (true) {
			std::cout << "departmentID* : ";
			std::getline(std::cin, userInput);
			Utility::removeEmptySpaces(userInput);

			if (userInput.size() == 0) {
				std::cout << "\x1B[33m" << "departmentID is mandatory...Please enter again!!" << "\x1B[0m\n";
			}
			else {
				try {
					if (stoi(userInput) > 0) {
						obj.setDepartmentID(stoi(userInput));
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
			std::cout << "departmentName* : ";
			std::getline(std::cin, userInput);
			Utility::removeEmptySpaces(userInput);

			if (userInput.size() == 0) {
				std::cout << "\x1B[33m" << "departmentName is mandatory...Please enter again!!" << "\x1B[0m\n";
			}
			else {
				obj.setDepartmentName(userInput);
				break;
			}
		}
		break;

	case 3:
		while (true) {
			std::cout << "baseSalary* : ";
			std::getline(std::cin, userInput);
			Utility::removeEmptySpaces(userInput);

			if (userInput.size() == 0) {
				std::cout << "\x1B[33m" << "baseSalary is mandatory...Please enter again!!" << "\x1B[0m\n";
			}
			else {
				try {
					if (stod(userInput) >= 0.0) {
						obj.setBaseSalary(stod(userInput));
					}
					else {
						throw "Negative Number";
					}
				}
				catch (...) {
					std::cout << "\x1B[33m" << "Wrong input...Please enter Positive real number!!" << "\x1B[0m\n";
					continue;
				}
				break;
			}
		}
		break;

	case 4:
		while (true) {
			std::cout << "allowance* : ";
			std::getline(std::cin, userInput);
			Utility::removeEmptySpaces(userInput);

			if (userInput.size() == 0) {
				std::cout << "\x1B[33m" << "allowance is mandatory...Please enter again!!" << "\x1B[0m\n";
			}
			else {
				try {
					if (stod(userInput) >= 0.0) {
						obj.setAllowance(stod(userInput));
					}
					else {
						throw "Negative Number";
					}
				}
				catch (...) {
					std::cout << "\x1B[33m" << "Wrong input...Please Positive enter real number!!" << "\x1B[0m\n";
					continue;
				}
				break;
			}
		}
		break;

	case 5:
		while (true) {
			std::cout << "deduction* : ";
			std::getline(std::cin, userInput);
			Utility::removeEmptySpaces(userInput);

			if (userInput.size() == 0) {
				std::cout << "\x1B[33m" << "deduction is mandatory...Please enter again!!" << "\x1B[0m\n";
			}
			else {
				try {
					if (stod(userInput) >= 0.0) {
						obj.setDeduction(stod(userInput));
					}
					else {
						throw "Negative Number";
					}
				}
				catch (...) {
					std::cerr << "\x1B[33m" << "Wrong input...Please enter Positive real number!!" << "\x1B[0m\n";
					continue;
				}
				break;
			}
		}
		break;
	}
}

bool DepartmentView::getDepartmentIDInput(Department& obj, const std::string& operation) {
	std::string userInput;

	system("cls");
	std::cout << "------------------------------------------" << "\x1B[36m" << operation <<" Department"<< "\x1B[0m" <<"-------------------------------------------------\n";
	std::cout << "\x1B[33m" << "To "+ operation +" a Department, please enter departmentID." << "\x1B[0m\n";

	while (true) {
		std::cout << "departmentID* : ";
		std::getline(std::cin, userInput);
		Utility::removeEmptySpaces(userInput);

		if (userInput.size() == 0) {
			std::cout << "\x1B[33m" << "departmentID is mandatory...Please enter again!!" << "\x1B[0m\n";
		}
		else {
			if (Validate::validateDepartmentID(userInput)) {
				obj.setDepartmentID(stoi(userInput));
				break;
			}
			else {
				std::cout << "\x1B[33m" << "Wrong input...Please enter positive integer number!!" << "\x1B[0m\n";
			}
		}
	}

	system("cls");
	std::cout << "------------------------------------------" << "\x1B[36m" << operation << " Department" << "\x1B[0m" << "-------------------------------------------------\n";
	DepartmentController::selectDepartment("departmentID", userInput);

	return Utility::proceedFurther(operation);
}

bool DepartmentView::updateDepartment() {
	Department obj{ true };
	auto isInvalidInput{ false };

	if (!getDepartmentIDInput(obj, "Update")) {
		return false;
	}

	while (true) {
		system("cls");
		std::cout << "------------------------------------------" << "\x1B[36m" << "Update Department" << "\x1B[0m" << "-------------------------------------------------\n";
		std::cout << "\x1B[36m" << "Fields with * are required fields" << "\x1B[0m\n";
		std::cout << "0. Exit" << '\n';
		printDepartmentFields();
		std::cout << "5. Go Back" << '\n';
		std::cout << "\x1B[33m" << "Select the field you want to update, or select 0/5 for operations:" << "\x1B[0m\n";

		if (isInvalidInput) {
			std::cerr << "\x1B[33m" << "Wrong Input, Please enter an input in the range: [0-5]" << "\x1B[0m\n";
			isInvalidInput = false;
		}

		int userInput;
		std::string inputLine;
		std::getline(std::cin, inputLine);
		Utility::removeEmptySpaces(inputLine);

		if (inputLine.length() == 0) {
			isInvalidInput = true;
			continue;
		}
		try {
			userInput = stoi(inputLine);
			if (userInput == 0) {
				std::exit(0);
			}
			else if (userInput >= 1 && userInput <= 4) {
				getUpdateDepartmentInput(obj, userInput);
				if (Utility::repeatOperation("update", "field")) {
					continue;
				}
				else {
					break;
				}
			}
			else if (userInput == 5) {
				return false;
			}
			else {
				isInvalidInput = true;
			}
		}
		catch (...) {
			isInvalidInput = true;
		}
	}

	DepartmentController::updateDepartment(obj);

	return Utility::repeatOperation("update", "Department");
}

bool DepartmentView::deleteDepartment() {
	Department obj{ true };
	auto isInvalidInput{ false };

	if (!getDepartmentIDInput(obj, "Delete")) {
		return false;
	}

	DepartmentController::deleteDepartmentByID(obj.getDepartmentID());

	return Utility::repeatOperation("delete", "Department");
}

bool DepartmentView::viewDepartmentConditional() {
	Department obj;
	auto isInvalidInput{ false };

	while (true) {
		system("cls");
		std::cout << "------------------------------------------" << "\x1B[36m" << "View Department" << "\x1B[0m" << "-------------------------------------------------\n";
		std::cout << "0. Exit" << '\n';
		printViewDepartmentFields();
		std::cout << "6. Go Back" << '\n';
		std::cout << "\x1B[33m" << "Select the field by which you want to view the Department, or select 0/6 for operations:" << "\x1B[0m\n";

		if (isInvalidInput) {
			std::cerr << "\x1B[33m" << "Wrong Input, Please enter an input in the range: [0-3]" << "\x1B[0m\n";
			isInvalidInput = false;
		}

		int userInput;
		std::string inputLine;
		std::getline(std::cin, inputLine);
		Utility::removeEmptySpaces(inputLine);

		if (inputLine.length() == 0) {
			isInvalidInput = true;
			continue;
		}
		try {
			userInput = stoi(inputLine);
			if (userInput == 0) {
				std::exit(0);
			}
			else if (userInput == 1) {
				getViewDepartmentInput(obj, 1);
				DepartmentController::selectDepartment("departmentID", std::to_string(obj.getDepartmentID()));
				break;
			}
			else if (userInput == 2) {
				getViewDepartmentInput(obj, 2);
				DepartmentController::selectDepartment("departmentName", obj.getDepartmentName());
				break;
			}
			else if (userInput == 3) {
				getViewDepartmentInput(obj, 3);
				DepartmentController::selectDepartment("baseSalary", std::to_string(obj.getBaseSalary()));
				break;
			}
			else if (userInput == 4) {
				getViewDepartmentInput(obj, 4);
				DepartmentController::selectDepartment("allowance", std::to_string(obj.getAllowance()));
				break;
			}
			else if (userInput == 5) {
				getViewDepartmentInput(obj, 5);
				DepartmentController::selectDepartment("deduction", std::to_string(obj.getDeduction()));
				break;
			}
			else if (userInput == 6) {
				return false;
			}
			else {
				isInvalidInput = true;
			}
		}
		catch (...) {
			isInvalidInput = true;
		}
	}
	return true;
}

bool DepartmentView::viewDepartment() {
	auto isInvalidInput{ false };

	while (true) {
		system("cls");
		std::cout << "------------------------------------------" << "\x1B[36m" << "View Department" << "\x1B[0m" << "-------------------------------------------------\n";
		std::cout << "0. Exit" << '\n';
		std::cout << "1. View Department based on a field" << '\n';
		std::cout << "2. View all Department" << '\n';
		std::cout << "3. Go Back" << '\n';
		std::cout << "\x1B[33m" << "Select the operation [0-3]: " << "\x1B[0m\n";

		if (isInvalidInput) {
			std::cerr << "\x1B[33m" << "Wrong Input, Please enter an input in the range: [0-3]" << "\x1B[0m\n";
			isInvalidInput = false;
		}

		int userInput;
		std::string inputLine;
		std::getline(std::cin, inputLine);
		Utility::removeEmptySpaces(inputLine);

		if (inputLine.length() == 0) {
			isInvalidInput = true;
			continue;
		}
		try {
			userInput = stoi(inputLine);
			if (userInput == 0) {
				std::exit(0);
			}
			else if (userInput == 1) {
				if (!viewDepartmentConditional()) {
					return true;
				}
				break;
			}
			else if (userInput == 2) {
				DepartmentController::selectDepartment();
				break;
			}
			else if (userInput == 3) {
				return false;
			}
			else {
				isInvalidInput = true;
			}
		}
		catch (...) {
			isInvalidInput = true;
		}
	}

	return Utility::repeatOperation("view", "Department");
}