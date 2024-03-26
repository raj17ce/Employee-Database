#include <iostream>
#include "ManagerView.h"
#include "EmployeeView.h"
#include "Utility.h"
#include "ManagerController.h"
#include "Validate.h"

using EmployeeDB::View::ManagerView, EmployeeDB::View::EmployeeView, EmployeeDB::View::Utility;
using EmployeeDB::Controller::ManagerController;
using EmployeeDB::Validate;

void ManagerView::printManagerFields() {
	std::cout << "1. managerID* (employeeID) : " << '\n';
	std::cout << "2. teamSize* : " << '\n';
	std::cout << "3. yearsOfExperience* : " << '\n';
	std::cout << "4. projectTitle : " << '\n';
	std::cout << "5. role : " << '\n';
}

void ManagerView::getInsertManagerInput(Manager& obj) {
	std::string userInput;

	while (true) {
		std::cout << "managerID* : ";
		std::getline(std::cin, userInput);
		Utility::removeEmptySpaces(userInput);

		if (userInput.size() == 0) {
			std::cout << "managerID is mandatory...Please enter again!!" << '\n';
		}
		else {
			if (Validate::validateEmployeeID(userInput, "*")) {
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
		std::getline(std::cin, userInput);
		Utility::removeEmptySpaces(userInput);

		if (userInput.size() == 0) {
			std::cout << "teamSize is mandatory...Please enter again!!" << '\n';
		}
		else {
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
		std::getline(std::cin, userInput);
		Utility::removeEmptySpaces(userInput);

		if (userInput.size() == 0) {
			std::cout << "yearsOfExperience is mandatory...Please enter again!!" << '\n';
		}
		else {
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
		std::getline(std::cin, userInput);
		Utility::removeEmptySpaces(userInput);

		if (userInput.size() != 0) {
			obj.setProjectTitle(userInput);
		}
	}

	{
		std::cout << "role : ";
		std::getline(std::cin, userInput);
		Utility::removeEmptySpaces(userInput);

		if (userInput.size() != 0) {
			obj.setRole(userInput);
		}
	}
};

bool ManagerView::insertManager() {
	Manager obj;

	system("cls");
	std::cout << "------------------------------------------Insert Manager-------------------------------------------------\n";
	std::cout << "Fields with * are required fields\n";
	printManagerFields();

	if (!Utility::proceedFurther("insertion")) {
		return false;
	}

	getInsertManagerInput(obj);
	ManagerController::insertManager(obj);

	return Utility::repeatOperation("insert", "Manager");
}

void ManagerView::printUpdateManagerFields() {
	std::cout << "13. teamSize* : " << '\n';
	std::cout << "14. yearsOfExperience* : " << '\n';
	std::cout << "15. projectTitle : " << '\n';
	std::cout << "16. role : " << '\n';
}

void ManagerView::printViewManagerFields() {
	std::cout << "14. teamSize* : " << '\n';
	std::cout << "15. yearsOfExperience* : " << '\n';
	std::cout << "16. projectTitle* : " << '\n';
	std::cout << "17. role* : " << '\n';
}

void ManagerView::getUpdateManagerInput(Manager& obj, int fieldNumber) {
	std::string userInput;

	switch (fieldNumber) {
	case 13:
		while (true) {
			std::cout << "teamSize* : ";
			std::getline(std::cin, userInput);
			Utility::removeEmptySpaces(userInput);

			if (userInput.size() == 0) {
				std::cout << "teamSize is mandatory...Please enter again!!" << '\n';
			}
			else {
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
		break;

	case 14:
		while (true) {
			std::cout << "yearsOfExperience* : ";
			std::getline(std::cin, userInput);
			Utility::removeEmptySpaces(userInput);

			if (userInput.size() == 0) {
				std::cout << "yearsOfExperience is mandatory...Please enter again!!" << '\n';
			}
			else {
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
		break;

	case 15:
		{
			std::cout << "projectTitle : ";
			std::getline(std::cin, userInput);
			Utility::removeEmptySpaces(userInput);

			if (userInput.size() != 0) {
				obj.setProjectTitle(userInput);
			}
		}
		break;

	case 16:
		{
			std::cout << "role : ";
			std::getline(std::cin, userInput);
			Utility::removeEmptySpaces(userInput);

			if (userInput.size() != 0) {
				obj.setRole(userInput);
			}
		}
		break;
	}
}

void ManagerView::getViewManagerInput(Manager& obj, int fieldNumber) {
	std::string userInput;

	switch (fieldNumber) {
	case 14:
		while (true) {
			std::cout << "teamSize* : ";
			std::getline(std::cin, userInput);
			Utility::removeEmptySpaces(userInput);

			if (userInput.size() == 0) {
				std::cout << "teamSize is mandatory...Please enter again!!" << '\n';
			}
			else {
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
		break;

	case 15:
		while (true) {
			std::cout << "yearsOfExperience* : ";
			std::getline(std::cin, userInput);
			Utility::removeEmptySpaces(userInput);

			if (userInput.size() == 0) {
				std::cout << "yearsOfExperience is mandatory...Please enter again!!" << '\n';
			}
			else {
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
		break;

	case 16:
		while (true) {
			std::cout << "projectTitle* : ";
			std::getline(std::cin, userInput);
			Utility::removeEmptySpaces(userInput);

			if (userInput.size() == 0) {
				std::cout << "projectTitle is mandatory...Please enter again!!" << '\n';
			}
			else {
				obj.setProjectTitle(userInput);
				break;
			}
		}
		break;
	case 17:
		while (true) {
			std::cout << "role* : ";
			std::getline(std::cin, userInput);
			Utility::removeEmptySpaces(userInput);

			if (userInput.size() == 0) {
				std::cout << "role is mandatory...Please enter again!!" << '\n';
			}
			else {
				obj.setRole(userInput);
				break;
			}
		}
		break;
	}
}

bool ManagerView::getManagerIDInput(Manager& obj, const std::string& operation) {
	std::string userInput;

	system("cls");
	std::cout << "------------------------------------------"+ operation +" Manager-------------------------------------------------\n";
	std::cout << "To "+ operation +" a Manager, please enter managerID.\n";

	while (true) {
		std::cout << "managerID* : ";
		std::getline(std::cin, userInput);
		Utility::removeEmptySpaces(userInput);

		if (userInput.size() == 0) {
			std::cout << "managerID is mandatory...Please enter again!!" << '\n';
		}
		else {
			if (Validate::validateManagerID(userInput)) {
				obj.setManagerID(stoi(userInput));
				obj.setEmployeeID(stoi(userInput));
				break;
			}
			else {
				std::cout << "Wrong input...Please enter positive integer number!!\n";
			}
		}
	}

	system("cls");
	std::cout << "------------------------------------------"+ operation +" Manager-------------------------------------------------\n";
	ManagerController::selectManager("employeeID", userInput);

	if (operation == "Delete") {
		std::cout << "Note : Deleting manager will not affect the corresponding Employee entry.\n";
	}
	return Utility::proceedFurther(operation);
}

bool ManagerView::updateManager() {
	Manager obj{ true };
	bool isInvalidInput{ false };

	if (!getManagerIDInput(obj, "Update")) {
		return false;
	}

	while (true) {
		system("cls");
		std::cout << "------------------------------------------Update Manager-------------------------------------------------\n";
		std::cout << "Fields with * are required fields\n";
		std::cout << "0. Exit" << '\n';
		EmployeeView::printEmployeeFields();
		printUpdateManagerFields();
		std::cout << "17. Go Back" << '\n';
		std::cout << "Select the field you want to update, or select 0/17 for operations: \n";

		if (isInvalidInput) {
			std::cerr << "Wrong Input, Please enter an input in the range: [0-17]\n";
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
			else if (userInput >= 1 && userInput <= 12) {
				EmployeeView::getUpdateEmployeeInput(obj, userInput);
				if (Utility::repeatOperation("update", "field")) {
					continue;
				}
				else {
					break;
				}
			}
			else if (userInput >= 13 && userInput <= 16) {
				getUpdateManagerInput(obj, userInput);
				if (Utility::repeatOperation("update", "field")) {
					continue;
				}
				else {
					break;
				}
			}
			else if (userInput == 17) {
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

	ManagerController::updateManager(obj);

	return Utility::repeatOperation("update", "Manager");
}

bool ManagerView::deleteManager() {
	Manager obj{ true };
	bool isInvalidInput{ false };

	if (!getManagerIDInput(obj, "Delete")) {
		return false;
	}

	ManagerController::deleteManagerByID(obj.getManagerID());

	return Utility::repeatOperation("delete", "Manager");
}

void ManagerView::viewManagerConditional() {
	Manager obj;
	bool isInvalidInput{ false };

	while (true) {
		system("cls");
		std::cout << "------------------------------------------View Manager-------------------------------------------------\n";
		std::cout << "0. Exit" << '\n';
		EmployeeView::printViewEmployeeFields();
		printViewManagerFields();
		std::cout << "18. Go Back" << '\n';
		std::cout << "Select the field by which you want to view the Manager, or select 0/18 for operations: \n";

		if (isInvalidInput) {
			std::cerr << "Wrong Input, Please enter an input in the range: [0-3]\n";
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
				EmployeeView::getViewEmployeeInput(obj, 1);
				ManagerController::selectManager("employeeID", std::to_string(obj.getEmployeeID()));
				break;
			}
			else if (userInput == 2) {
				EmployeeView::getViewEmployeeInput(obj, 2);
				ManagerController::selectManager("firstName", obj.getFirstName());
				break;
			}
			else if (userInput == 3) {
				EmployeeView::getViewEmployeeInput(obj, 3);
				ManagerController::selectManager("middleName", obj.getMiddleName());
				break;
			}
			else if (userInput == 4) {
				EmployeeView::getViewEmployeeInput(obj, 4);
				ManagerController::selectManager("lastName", obj.getLastName());
				break;
			}
			else if (userInput == 5) {
				EmployeeView::getViewEmployeeInput(obj, 5);
				ManagerController::selectManager("dateOfBirth", obj.getDateOfBirth());
				break;
			}
			else if (userInput == 6) {
				EmployeeView::getViewEmployeeInput(obj, 6);
				ManagerController::selectManager("mobileNo", std::to_string(obj.getMobileNumber()));
				break;
			}
			else if (userInput == 7) {
				EmployeeView::getViewEmployeeInput(obj, 7);
				ManagerController::selectManager("email", obj.getEmail());
				break;
			}
			else if (userInput == 8) {
				EmployeeView::getViewEmployeeInput(obj, 8);
				ManagerController::selectManager("address", obj.getAddress());
				break;
			}
			else if (userInput == 9) {
				EmployeeView::getViewEmployeeInput(obj, 9);
				ManagerController::selectManager("gender", EmployeeDB::Model::getGenderString(obj.getGender()));
				break;
			}
			else if (userInput == 10) {
				EmployeeView::getViewEmployeeInput(obj, 10);
				ManagerController::selectManager("dateOfJoining", obj.getDateOfJoining());
				break;
			}
			else if (userInput == 11) {
				EmployeeView::getViewEmployeeInput(obj, 11);
				ManagerController::selectManager("mentorID", std::to_string(obj.getMentorID()));
				break;
			}
			else if (userInput == 12) {
				EmployeeView::getViewEmployeeInput(obj, 12);
				ManagerController::selectManager("performanceMetric", std::to_string(obj.getPerformanceMetric()));
				break;
			}
			else if (userInput == 13) {
				EmployeeView::getViewEmployeeInput(obj, 13);
				ManagerController::selectManager("bonus", std::to_string(obj.getBonus()));
				break;
			}
			else if (userInput == 14) {
				getViewManagerInput(obj, 14);
				ManagerController::selectManager("teamSize", std::to_string(obj.getTeamSize()));
				break;
			}
			else if (userInput == 15) {
				getViewManagerInput(obj, 15);
				ManagerController::selectManager("yearsOfExperience", std::to_string(obj.getYearsOfExperience()));
				break;
			}
			else if (userInput == 16) {
				getViewManagerInput(obj, 16);
				ManagerController::selectManager("projectTitle", obj.getProjectTitle());
				break;
			}
			else if (userInput == 17) {
				getViewManagerInput(obj, 17);
				ManagerController::selectManager("role", obj.getRole());
				break;
			}
			else if (userInput == 18) {
				return;
			}
			else {
				isInvalidInput = true;
			}
		}
		catch (...) {
			isInvalidInput = true;
		}
	}
}

bool ManagerView::viewManager() {
	bool isInvalidInput{ false };

	while (true) {
		system("cls");
		std::cout << "------------------------------------------View Manager-------------------------------------------------\n";
		std::cout << "0. Exit" << '\n';
		std::cout << "1. View Manager based on a field" << '\n';
		std::cout << "2. View all Manager" << '\n';
		std::cout << "3. Go Back" << '\n';
		std::cout << "Select the operation [0-3]: \n";

		if (isInvalidInput) {
			std::cerr << "Wrong Input, Please enter an input in the range: [0-3]\n";
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
				viewManagerConditional();
				break;
			}
			else if (userInput == 2) {
				ManagerController::selectManager();
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

	return Utility::repeatOperation("view", "Manager");
}