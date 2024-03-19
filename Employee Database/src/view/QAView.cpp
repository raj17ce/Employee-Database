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
	EmployeeView::printEmployeeFields();
	std::cout << "13. testingTool* : " << '\n';

	if (!Utility::proceedFurther("insertion")) {
		return false;
	}

	EmployeeView::getInsertEmployeeInput(obj);

	std::string userInput;

	while (true) {
		std::cout << "testingTool* : ";
		char userChoice = std::cin.get();
		if (userChoice == '\n') {
			std::cout << "testingTool is mandatory...Please enter again!!" << '\n';
		}
		else {
			std::getline(std::cin, userInput);
			userInput = userChoice + userInput;
			obj.setTestingTool(userInput);
			break;
		}
	}

	QAController::insertQA(obj);

	return Utility::repeatOperation("QA");
}