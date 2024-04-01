#ifndef __TableFixture_H__
#define __TableFixture_H__

#include "../../pch.h";
#include "./model/Table.h"

using EmployeeDB::Model::Table;

class TableFixture : public ::testing::Test {
public:
	void SetUp() override {
		table = std::make_unique<Table>();

		table->setTableName("Dpt");

		std::vector<std::array<std::string, 3>> attributes;
		attributes.reserve(3);
		std::vector<std::array<std::string, 4>> foreignKeys;

		attributes.emplace_back(std::move(std::array<std::string, 3>{"ID", "INT", "NOT NULL UNIQUE PRIMARY KEY"}));
		attributes.emplace_back(std::move(std::array<std::string, 3>{"DepartmentName", "TEXT", "NOT NULL"}));
		attributes.emplace_back(std::move(std::array<std::string, 3>{"teamSize", "INT"}));

		table->setAttributesVector(attributes);

		foreignKeys.emplace_back(std::move(std::array<std::string, 4>{"DepartmentName", "Department", "departmentName", "ON DELETE CASCADE"}));

		table->setForeignKeysVector(foreignKeys);

		emptyTable = std::make_unique<Table>();
		emptyTable->setTableName("Roles");
	}

	std::unique_ptr<Table> table;
	std::unique_ptr<Table> emptyTable;
};

#endif