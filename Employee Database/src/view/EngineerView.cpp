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
	EmployeeView::printEmployeeFields();
	std::cout << "13. technology* : " << '\n';

	if (!Utility::proceedFurther("insertion")) {
		return false;
	}

	EmployeeView::getInsertEmployeeInput(obj);

	std::string userInput;

	while (true) {
		std::cout << "technology* : ";
		char userChoice = std::cin.get();
		if (userChoice == '\n') {
			std::cout << "Technology is mandatory...Please enter again!!" << '\n';
		}
		else {
			std::getline(std::cin, userInput);
			userInput = userChoice + userInput;
			obj.setTechnology(userInput);
			break;
		}
	}

	EngineerController::insertEngineer(obj);

	return Utility::repeatOperation("Engineer");
}