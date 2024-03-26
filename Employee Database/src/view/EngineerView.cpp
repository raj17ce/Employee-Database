#include "EmployeeView.h"
#include "EngineerView.h"
#include "Utility.h"
#include "EngineerController.h"

using EmployeeDB::View::EmployeeView, EmployeeDB::View::EngineerView, EmployeeDB::View::Utility;
using EmployeeDB::Controller::EngineerController;

bool EngineerView::insertEngineer() {
	Engineer obj;

	system("cls");
	std::cout << "------------------------------------------Insert Engineer-------------------------------------------------\n";
	std::cout << "Fields with * are required fields\n";
	EmployeeView::printEmployeeFields();
	std::cout << "13. technology* : " << '\n';

	if (!Utility::proceedFurther("insertion")) {
		return false;
	}

	EmployeeView::getInsertEmployeeInput(obj);

	std::string userInput;

	while (true) {
		std::cout << "technology* : ";
		std::getline(std::cin, userInput);
		Utility::removeEmptySpaces(userInput);

		if (userInput.size() == 0) {
			std::cout << "Technology is mandatory...Please enter again!!" << '\n';
		}
		else {
			obj.setTechnology(userInput);
			break;
		}
	}

	EngineerController::insertEngineer(obj);

	return Utility::repeatOperation("insert", "Engineer");
}

bool EngineerView::updateEngineer() {
	Engineer obj{ true };
	bool isInvalidInput{ false };

	EmployeeView::getEmployeeIDInput(obj, "Update", "Engineer");

	system("cls");
	std::cout << "------------------------------------------Update Engineer-------------------------------------------------\n";
	EngineerController::selectEngineer("Employee.employeeID", std::to_string(obj.getEmployeeID()));
	if (!Utility::proceedFurther("Update")) {
		return false;
	}

	while (true) {
		system("cls");
		std::cout << "------------------------------------------Update Engineer-------------------------------------------------\n";
		std::cout << "Fields with * are required fields\n";
		std::cout << "0. Exit" << '\n';
		EmployeeView::printEmployeeFields();
		std::cout << "13. technology* : " << '\n';
		std::cout << "14. Go Back" << '\n';
		std::cout << "Select the field you want to update, or select 0/14 for operations: \n";

		if (isInvalidInput) {
			std::cerr << "Wrong Input, Please enter an input in the range: [0-14]\n";
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
			else if (userInput == 13) {
				while (true) {
					std::cout << "technology* : ";
					std::getline(std::cin, inputLine);
					if (inputLine.size() == 0) {
						std::cout << "Technology is mandatory...Please enter again!!" << '\n';
					}
					else {
						obj.setTechnology(inputLine);
						break;
					}
				}
				if (Utility::repeatOperation("update", "field")) {
					continue;
				}
				else {
					break;
				}
			}
			else if (userInput == 14) {
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

	EngineerController::updateEngineer(obj);

	return Utility::repeatOperation("update", "Engineer");
}

bool EngineerView::deleteEngineer() {
	Engineer obj{ true };
	bool isInvalidInput{ false };

	EmployeeView::getEmployeeIDInput(obj, "Delete", "Engineer");

	system("cls");
	std::cout << "------------------------------------------Delete Engineer-------------------------------------------------\n";
	EngineerController::selectEngineer("Employee.employeeID", std::to_string(obj.getEmployeeID()));
	if (!Utility::proceedFurther("Delete")) {
		return false;
	}

	EngineerController::deleteEngineerByID(obj.getEmployeeID());

	return Utility::repeatOperation("delete", "Engineer");
}

void EngineerView::viewEngineerConditional() {
	Engineer obj;
	bool isInvalidInput{ false };

	while (true) {
		system("cls");
		std::cout << "------------------------------------------View Engineer-------------------------------------------------\n";
		std::cout << "0. Exit" << '\n';
		EmployeeView::printViewEmployeeFields();
		std::cout << "14. technology* : " << '\n';
		std::cout << "15. Go Back" << '\n';
		std::cout << "Select the field by which you want to view the Engineer, or select 0/15 for operations: \n";

		if (isInvalidInput) {
			std::cerr << "Wrong Input, Please enter an input in the range: [0-15]\n";
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
				EngineerController::selectEngineer("employeeID", std::to_string(obj.getEmployeeID()));
				break;
			}
			else if (userInput == 2) {
				EmployeeView::getViewEmployeeInput(obj, 2);
				EngineerController::selectEngineer("firstName", obj.getFirstName());
				break;
			}
			else if (userInput == 3) {
				EmployeeView::getViewEmployeeInput(obj, 3);
				EngineerController::selectEngineer("middleName", obj.getMiddleName());
				break;
			}
			else if (userInput == 4) {
				EmployeeView::getViewEmployeeInput(obj, 4);
				EngineerController::selectEngineer("lastName", obj.getLastName());
				break;
			}
			else if (userInput == 5) {
				EmployeeView::getViewEmployeeInput(obj, 5);
				EngineerController::selectEngineer("dateOfBirth", obj.getDateOfBirth());
				break;
			}
			else if (userInput == 6) {
				EmployeeView::getViewEmployeeInput(obj, 6);
				EngineerController::selectEngineer("mobileNo", std::to_string(obj.getMobileNumber()));
				break;
			}
			else if (userInput == 7) {
				EmployeeView::getViewEmployeeInput(obj, 7);
				EngineerController::selectEngineer("email", obj.getEmail());
				break;
			}
			else if (userInput == 8) {
				EmployeeView::getViewEmployeeInput(obj, 8);
				EngineerController::selectEngineer("address", obj.getAddress());
				break;
			}
			else if (userInput == 9) {
				EmployeeView::getViewEmployeeInput(obj, 9);
				EngineerController::selectEngineer("gender", EmployeeDB::Model::getGenderString(obj.getGender()));
				break;
			}
			else if (userInput == 10) {
				EmployeeView::getViewEmployeeInput(obj, 10);
				EngineerController::selectEngineer("dateOfJoining", obj.getDateOfJoining());
				break;
			}
			else if (userInput == 11) {
				EmployeeView::getViewEmployeeInput(obj, 11);
				EngineerController::selectEngineer("mentorID", std::to_string(obj.getMentorID()));
				break;
			}
			else if (userInput == 12) {
				EmployeeView::getViewEmployeeInput(obj, 12);
				EngineerController::selectEngineer("performanceMetric", std::to_string(obj.getPerformanceMetric()));
				break;
			}
			else if (userInput == 13) {
				EmployeeView::getViewEmployeeInput(obj, 13);
				EngineerController::selectEngineer("bonus", std::to_string(obj.getBonus()));
				break;
			}
			else if (userInput == 14) {
				while (true) {
					std::cout << "technology* : ";
					std::getline(std::cin, inputLine);
					Utility::removeEmptySpaces(inputLine);

					if (inputLine.size() == 0) {
						std::cout << "technology is mandatory...Please enter again!!" << '\n';
					}
					else {
						obj.setTechnology(inputLine);
						break;
					}
				}
				EngineerController::selectEngineer("technology", obj.getTechnology());
				break;
			}
			else if (userInput == 15) {
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

bool EngineerView::viewEngineer() {
	bool isInvalidInput{ false };

	while (true) {
		system("cls");
		std::cout << "------------------------------------------View Engineer-------------------------------------------------\n";
		std::cout << "0. Exit" << '\n';
		std::cout << "1. View Engineer based on a field" << '\n';
		std::cout << "2. View all Engineer" << '\n';
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
				viewEngineerConditional();
				break;
			}
			else if (userInput == 2) {
				EngineerController::selectEngineer();
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

	return Utility::repeatOperation("view", "Engineer");
}