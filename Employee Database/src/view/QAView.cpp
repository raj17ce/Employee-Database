#include "EmployeeView.h"
#include "QAView.h"
#include "Utility.h"
#include "QAController.h"

using EmployeeDB::View::EmployeeView, EmployeeDB::View::QAView, EmployeeDB::View::Utility;
using EmployeeDB::Controller::QAController;

bool QAView::insertQA() {
	QA obj;

	system("cls");
	std::cout << "------------------------------------------Insert QA-------------------------------------------------\n";
	std::cout << "Fields with * are required fields\n";
	EmployeeView::printEmployeeFields();
	std::cout << "13. testingTool* : " << '\n';

	if (!Utility::proceedFurther("insertion")) {
		return false;
	}

	EmployeeView::getInsertEmployeeInput(obj);

	std::string userInput;

	while (true) {
		std::cout << "testingTool* : ";
		std::getline(std::cin, userInput);
		Utility::removeEmptySpaces(userInput);

		if (userInput.size() == 0) {
			std::cout << "testingTool is mandatory...Please enter again!!" << '\n';
		}
		else {
			obj.setTestingTool(userInput);
			break;
		}
	}

	QAController::insertQA(obj);

	return Utility::repeatOperation("insert", "QA");
}

bool QAView::updateQA() {
	QA obj{ true };
	bool isInvalidInput{ false };

	EmployeeView::getEmployeeIDInput(obj, "Update", "QA");

	system("cls");
	std::cout << "------------------------------------------Update QA-------------------------------------------------\n";
	QAController::selectQA("Employee.employeeID", std::to_string(obj.getEmployeeID()));
	if (!Utility::proceedFurther("Update")) {
		return false;
	}

	while (true) {
		system("cls");
		std::cout << "------------------------------------------Update QA-------------------------------------------------\n";
		std::cout << "Fields with * are required fields\n";
		std::cout << "0. Exit" << '\n';
		EmployeeView::printEmployeeFields();
		std::cout << "13. testingTool* : " << '\n';
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
					std::cout << "testingTool* : ";
					std::getline(std::cin, inputLine);
					if (inputLine.size() == 0) {
						std::cout << "testingTool is mandatory...Please enter again!!" << '\n';
					}
					else {
						obj.setTestingTool(inputLine);
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

	QAController::updateQA(obj);

	return Utility::repeatOperation("update", "QA");
}

bool QAView::deleteQA() {
	QA obj{ true };
	bool isInvalidInput{ false };

	EmployeeView::getEmployeeIDInput(obj, "Delete", "QA");

	system("cls");
	std::cout << "------------------------------------------Delete QA-------------------------------------------------\n";
	QAController::selectQA("Employee.employeeID", std::to_string(obj.getEmployeeID()));
	if (!Utility::proceedFurther("Delete")) {
		return false;
	}

	QAController::deleteQAByID(obj.getEmployeeID());

	return Utility::repeatOperation("delete", "QA");
}

void QAView::viewQAConditional() {
	QA obj;
	bool isInvalidInput{ false };

	while (true) {
		system("cls");
		std::cout << "------------------------------------------View QA-------------------------------------------------\n";
		std::cout << "0. Exit" << '\n';
		EmployeeView::printViewEmployeeFields();
		std::cout << "14. testingTool* : " << '\n';
		std::cout << "15. Go Back" << '\n';
		std::cout << "Select the field by which you want to view the QA, or select 0/15 for operations: \n";

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
				QAController::selectQA("employeeID", std::to_string(obj.getDepartmentID()));
				break;
			}
			else if (userInput == 2) {
				EmployeeView::getViewEmployeeInput(obj, 2);
				QAController::selectQA("firstName", obj.getFirstName());
				break;
			}
			else if (userInput == 3) {
				EmployeeView::getViewEmployeeInput(obj, 3);
				QAController::selectQA("middleName", obj.getMiddleName());
				break;
			}
			else if (userInput == 4) {
				EmployeeView::getViewEmployeeInput(obj, 4);
				QAController::selectQA("lastName", obj.getLastName());
				break;
			}
			else if (userInput == 5) {
				EmployeeView::getViewEmployeeInput(obj, 5);
				QAController::selectQA("dateOfBirth", obj.getDateOfBirth());
				break;
			}
			else if (userInput == 6) {
				EmployeeView::getViewEmployeeInput(obj, 6);
				QAController::selectQA("mobileNo", std::to_string(obj.getMobileNumber()));
				break;
			}
			else if (userInput == 7) {
				EmployeeView::getViewEmployeeInput(obj, 7);
				QAController::selectQA("email", obj.getEmail());
				break;
			}
			else if (userInput == 8) {
				EmployeeView::getViewEmployeeInput(obj, 8);
				QAController::selectQA("address", obj.getAddress());
				break;
			}
			else if (userInput == 9) {
				EmployeeView::getViewEmployeeInput(obj, 9);
				QAController::selectQA("gender", EmployeeDB::Model::getGenderString(obj.getGender()));
				break;
			}
			else if (userInput == 10) {
				EmployeeView::getViewEmployeeInput(obj, 10);
				QAController::selectQA("dateOfJoining", obj.getDateOfJoining());
				break;
			}
			else if (userInput == 11) {
				EmployeeView::getViewEmployeeInput(obj, 11);
				QAController::selectQA("mentorID", std::to_string(obj.getMentorID()));
				break;
			}
			else if (userInput == 12) {
				EmployeeView::getViewEmployeeInput(obj, 12);
				QAController::selectQA("performanceMetric", std::to_string(obj.getPerformanceMetric()));
				break;
			}
			else if (userInput == 13) {
				EmployeeView::getViewEmployeeInput(obj, 13);
				QAController::selectQA("bonus", std::to_string(obj.getBonus()));
				break;
			}
			else if (userInput == 14) {
				while (true) {
					std::cout << "testingTool* : ";
					std::getline(std::cin, inputLine);
					Utility::removeEmptySpaces(inputLine);

					if (inputLine.size() == 0) {
						std::cout << "testingTool is mandatory...Please enter again!!" << '\n';
					}
					else {
						obj.setTestingTool(inputLine);
						break;
					}
				}
				QAController::selectQA("testingTool", obj.getTestingTool());
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

bool QAView::viewQA() {
	bool isInvalidInput{ false };

	while (true) {
		system("cls");
		std::cout << "------------------------------------------View QA-------------------------------------------------\n";
		std::cout << "0. Exit" << '\n';
		std::cout << "1. View QA based on a field" << '\n';
		std::cout << "2. View all QA" << '\n';
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
				viewQAConditional();
				break;
			}
			else if (userInput == 2) {
				QAController::selectQA();
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

	return Utility::repeatOperation("view", "QA");
}