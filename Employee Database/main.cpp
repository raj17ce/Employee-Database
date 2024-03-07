#include <iostream>
#include "DBManager.h"
#include "Model.h"
#include "QAController.h"

using EmployeeDB::DBManager;
using EmployeeDB::Model::QA, EmployeeDB::Controller::QAController;

int main() {
	DBManager& db = DBManager::instance();

    QA dummyEmployee;

    // Set dummy values for all attributes
    dummyEmployee.setFirstName("Rahul");
    dummyEmployee.setMiddleName("R.");
    dummyEmployee.setLastName("Patel");
    dummyEmployee.setEmail("rahul@gmail.com");
    dummyEmployee.setAddress("valsad, Gujarat");
    dummyEmployee.setDateOfBirth("17-04-2003");
    dummyEmployee.setDateOfJoining("01-01-2025");
    dummyEmployee.setPerformanceMetric(10);
    dummyEmployee.setMobileNumber(8888665552);
    dummyEmployee.setGender(EmployeeDB::Model::Gender::Male);
    dummyEmployee.setDepartmentID(101);
    dummyEmployee.setManagerID(201);
    dummyEmployee.setBonus(50000);

    dummyEmployee.setTestingTool("Chai");

    QAController::createQA(dummyEmployee);
    
    db.executeSelectQuery("Select Employee.*,QA.testingTool from Employee inner join QA On Employee.employeeID = QA.employeeID");
    std::cout << db.getResultString() << '\n';

	return 0;
}