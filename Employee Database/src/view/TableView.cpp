#include <iostream>
#include <string>
#include <array>
#include <vector>
#include "TableView.h"
#include "Utility.h"

using EmployeeDB::View::TableView, EmployeeDB::View::Utility;
using EmployeeDB::Controller::TableController;

void TableView::getAttributesInput(Table& obj) {
	std::vector<std::array<std::string, 3>> attributesVector;
	attributesVector.reserve(10);

	while (true) {
		std::string attributeName;
		while (true) {
			std::cout << "Attribute name* : ";
			std::getline(std::cin, attributeName);
			Utility::removeEmptySpaces(attributeName);

			if (attributeName.size() == 0) {
				std::cout << "\x1B[33m" << "Attribute Name is mandatory...Please enter again!!" << "\033[0m\n";
			}
			else {
				break;
			}
		}

		std::string attributeType;
		while (true) {
			std::cout << "Attribute type* : ";
			std::getline(std::cin, attributeType);
			Utility::removeEmptySpaces(attributeType);

			if (attributeType.size() == 0) {
				std::cout << "\x1B[33m" << "Attribute Type is mandatory...Please enter again!!" << "\033[0m\n";
			}
			else {
				break;
			}
		}

		std::string attributeConstraints{ "" };
		{
			std::cout << "Attribute constraints : ";
			std::getline(std::cin, attributeConstraints);
			Utility::removeEmptySpaces(attributeConstraints);
		}

		attributesVector.emplace_back(std::move(std::array<std::string, 3>{attributeName, attributeType, attributeConstraints}));

		if (!Utility::repeatOperation("add", "Attribute")) {
			break;
		}
	}

	obj.setAttributesVector(attributesVector);
}

void TableView::getForeignKeysInput(Table& obj) {
	std::vector<std::array<std::string, 4>> foreignKeysVector;
	foreignKeysVector.reserve(3);

	auto foreignKeyInsertion{ true };
	if (!Utility::proceedFurther("Foreign key insertion")) {
		foreignKeyInsertion = false;
	}

	while (foreignKeyInsertion) {
		std::string keyAttributeName;
		while (true) {
			std::cout << "Attribute Name(Foreign Key)* : ";
			std::getline(std::cin, keyAttributeName);
			Utility::removeEmptySpaces(keyAttributeName);

			if (keyAttributeName.size() == 0) {
				std::cout << "\x1B[33m" << "Attribute Name is mandatory...Please enter again!!" << "\033[0m\n";
			}
			else {
				break;
			}
		}

		std::string referencedTableName;
		while (true) {
			std::cout << "Referenced Table Name* : ";
			std::getline(std::cin, referencedTableName);
			Utility::removeEmptySpaces(referencedTableName);

			if (referencedTableName.size() == 0) {
				std::cout << "\x1B[33m" << "Referenced Table Name is mandatory...Please enter again!!" << "\033[0m\n";
			}
			else {
				break;
			}
		}

		std::string referencedAttributeName;
		while (true) {
			std::cout << "Referenced Attribute Name* : ";
			std::getline(std::cin, referencedAttributeName);
			Utility::removeEmptySpaces(referencedAttributeName);

			if (referencedAttributeName.size() == 0) {
				std::cout << "\x1B[33m" << "Referenced Attribute Name is mandatory...Please enter again!!" << "\033[0m\n";
			}
			else {
				break;
			}
		}

		std::string keyConstraints;
		{
			std::cout << "Key Constraints : ";
			std::getline(std::cin, keyConstraints);
			Utility::removeEmptySpaces(keyConstraints);
		}

		foreignKeysVector.emplace_back(std::move(std::array<std::string, 4>{ keyAttributeName, referencedTableName, referencedAttributeName, keyConstraints }));

		if (!Utility::repeatOperation("Add", "foreign key")) {
			foreignKeyInsertion = false;
		}
	}

	obj.setForeignKeysVector(std::move(foreignKeysVector));
}

bool TableView::createTable() {
	Table obj;

	system("cls");
	std::cout << "------------------------------------------" << "\x1B[36m" << "Create Table" << "\033[0m" << "-------------------------------------------------\n";
	std::cout << "\x1B[36m" << "Fields with * are required fields" << "\x1B[0m\n";

	while (true) {
		std::string userInput;
		std::cout << "Table name* : ";
		std::getline(std::cin, userInput);
		Utility::removeEmptySpaces(userInput);

		if (userInput.size() == 0) {
			std::cout << "\x1B[33m" << "Table Name is mandatory...Please enter again!!" << "\033[0m\n";
		}
		else {
			obj.setTableName(userInput);
			break;
		}
	}

	getAttributesInput(obj);
	getForeignKeysInput(obj);

	TableController::createTable(obj);

	return Utility::repeatOperation("Create", "Table");
}

bool TableView::deleteTable() {
	Table obj;

	system("cls");
	std::cout << "------------------------------------------" << "\x1B[36m" << "Delete Table" << "\033[0m" << "-------------------------------------------------\n";
	std::cout << "\x1B[33m" << "Enter the name of the Table you want to delete." << "\x1B[0m\n";

	std::string tableName;
	while (true) {
		std::cout << "Table name* : ";
		std::getline(std::cin, tableName);
		Utility::removeEmptySpaces(tableName);

		if (tableName.size() == 0) {
			std::cout << "\x1B[33m" << "Table Name is mandatory...Please enter again!!" << "\033[0m\n";
		}
		else {
			obj.setTableName(tableName);
			break;
		}
	}

	TableController::deleteTable(tableName);

	return Utility::repeatOperation("Delete", "Table");
}