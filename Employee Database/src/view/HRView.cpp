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
	EmployeeView::printEmployeeFields();
	std::cout << "13. hrSpecialization* : " << '\n';

	if (!Utility::proceedFurther("insertion")) {
		return false;
	}

	EmployeeView::getInsertEmployeeInput(obj);

	std::string userInput;

	while (true) {
		std::cout << "hrSpecialization* : ";
		char userChoice = std::cin.get();
		if (userChoice == '\n') {
			std::cout << "hrSpecialization is mandatory...Please enter again!!" << '\n';
		}
		else {
			std::getline(std::cin, userInput);
			userInput = userChoice + userInput;
			obj.setHRSpecialization(userInput);
			break;
		}
	}

	HRController::insertHR(obj);

	return Utility::repeatOperation("HR");
}