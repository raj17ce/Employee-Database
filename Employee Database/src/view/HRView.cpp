#include "EmployeeView.h"
#include "HRView.h"
#include "Utility.h"
#include "HRController.h"

using EmployeeDB::View::EmployeeView, EmployeeDB::View::HRView, EmployeeDB::View::Utility;
using EmployeeDB::Controller::HRController;

bool HRView::insertHR() {
	HR obj;

	system("cls");
	std::cout << "------------------------------------------Insert HR-------------------------------------------------\n";
	std::cout << "Fields with * are required fields\n";
	EmployeeView::printEmployeeFields();
	std::cout << "13. hrSpecialization* : " << '\n';

	if (!Utility::proceedFurther("insertion")) {
		return false;
	}

	EmployeeView::getInsertEmployeeInput(obj);

	std::string userInput;

	while (true) {
		std::cout << "hrSpecialization* : ";
		std::getline(std::cin, userInput);
		Utility::removeEmptySpaces(userInput);

		if (userInput.size() == 0) {
			std::cout << "hrSpecialization is mandatory...Please enter again!!" << '\n';
		}
		else {
			obj.setHRSpecialization(userInput);
			break;
		}
	}

	HRController::insertHR(obj);

	return Utility::repeatOperation("insert", "HR");
}

bool HRView::updateHR() {
	HR obj{ true };
	bool isInvalidInput{ false };

	EmployeeView::getEmployeeIDInput(obj, "Update", "HR");

	system("cls");
	std::cout << "------------------------------------------Update HR-------------------------------------------------\n";
	HRController::selectHR("Employee.employeeID", std::to_string(obj.getEmployeeID()));
	if (!Utility::proceedFurther("Update")) {
		return false;
	}

	while (true) {
		system("cls");
		std::cout << "------------------------------------------Update HR-------------------------------------------------\n";
		std::cout << "Fields with * are required fields\n";
		std::cout << "0. Exit" << '\n';
		EmployeeView::printEmployeeFields();
		std::cout << "13. hrSpecialization* : " << '\n';
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
					std::cout << "hrSpecialization* : ";
					std::getline(std::cin, inputLine);
					if (inputLine.size() == 0) {
						std::cout << "hrSpecialization is mandatory...Please enter again!!" << '\n';
					}
					else {
						obj.setHRSpecialization(inputLine);
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

	HRController::updateHR(obj);

	return Utility::repeatOperation("update", "HR");
}

bool HRView::deleteHR() {
	HR obj{ true };
	bool isInvalidInput{ false };

	EmployeeView::getEmployeeIDInput(obj, "Delete", "HR");

	system("cls");
	std::cout << "------------------------------------------Delete HR-------------------------------------------------\n";
	HRController::selectHR("Employee.employeeID", std::to_string(obj.getEmployeeID()));
	if (!Utility::proceedFurther("Delete")) {
		return false;
	}

	HRController::deleteHRByID(obj.getEmployeeID());

	return Utility::repeatOperation("delete", "HR");
}

void HRView::viewHRConditional() {
	HR obj;
	bool isInvalidInput{ false };

	while (true) {
		system("cls");
		std::cout << "------------------------------------------View HR-------------------------------------------------\n";
		std::cout << "0. Exit" << '\n';
		EmployeeView::printViewEmployeeFields();
		std::cout << "14. hrSpecialization* : " << '\n';
		std::cout << "15. Go Back" << '\n';
		std::cout << "Select the field by which you want to view the HR, or select 0/15 for operations: \n";

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
				HRController::selectHR("employeeID", std::to_string(obj.getEmployeeID()));
				break;
			}
			else if (userInput == 2) {
				EmployeeView::getViewEmployeeInput(obj, 2);
				HRController::selectHR("firstName", obj.getFirstName());
				break;
			}
			else if (userInput == 3) {
				EmployeeView::getViewEmployeeInput(obj, 3);
				HRController::selectHR("middleName", obj.getMiddleName());
				break;
			}
			else if (userInput == 4) {
				EmployeeView::getViewEmployeeInput(obj, 4);
				HRController::selectHR("lastName", obj.getLastName());
				break;
			}
			else if (userInput == 5) {
				EmployeeView::getViewEmployeeInput(obj, 5);
				HRController::selectHR("dateOfBirth", obj.getDateOfBirth());
				break;
			}
			else if (userInput == 6) {
				EmployeeView::getViewEmployeeInput(obj, 6);
				HRController::selectHR("mobileNo", std::to_string(obj.getMobileNumber()));
				break;
			}
			else if (userInput == 7) {
				EmployeeView::getViewEmployeeInput(obj, 7);
				HRController::selectHR("email", obj.getEmail());
				break;
			}
			else if (userInput == 8) {
				EmployeeView::getViewEmployeeInput(obj, 8);
				HRController::selectHR("address", obj.getAddress());
				break;
			}
			else if (userInput == 9) {
				EmployeeView::getViewEmployeeInput(obj, 9);
				HRController::selectHR("gender", EmployeeDB::Model::getGenderString(obj.getGender()));
				break;
			}
			else if (userInput == 10) {
				EmployeeView::getViewEmployeeInput(obj, 10);
				HRController::selectHR("dateOfJoining", obj.getDateOfJoining());
				break;
			}
			else if (userInput == 11) {
				EmployeeView::getViewEmployeeInput(obj, 11);
				HRController::selectHR("mentorID", std::to_string(obj.getMentorID()));
				break;
			}
			else if (userInput == 12) {
				EmployeeView::getViewEmployeeInput(obj, 12);
				HRController::selectHR("performanceMetric", std::to_string(obj.getPerformanceMetric()));
				break;
			}
			else if (userInput == 13) {
				EmployeeView::getViewEmployeeInput(obj, 13);
				HRController::selectHR("bonus", std::to_string(obj.getBonus()));
				break;
			}
			else if (userInput == 14) {
				while (true) {
					std::cout << "hrSpecialization* : ";
					std::getline(std::cin, inputLine);
					Utility::removeEmptySpaces(inputLine);

					if (inputLine.size() == 0) {
						std::cout << "hrSpecialization is mandatory...Please enter again!!" << '\n';
					}
					else {
						obj.setHRSpecialization(inputLine);
						break;
					}
				}
				HRController::selectHR("hrSpecialization", obj.getHRSpecialization());
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

bool HRView::viewHR() {
	bool isInvalidInput{ false };

	while (true) {
		system("cls");
		std::cout << "------------------------------------------View HR-------------------------------------------------\n";
		std::cout << "0. Exit" << '\n';
		std::cout << "1. View HR based on a field" << '\n';
		std::cout << "2. View all HR" << '\n';
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
				viewHRConditional();
				break;
			}
			else if (userInput == 2) {
				HRController::selectHR();
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

	return Utility::repeatOperation("view", "HR");
}