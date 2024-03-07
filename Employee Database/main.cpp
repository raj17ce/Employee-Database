#include <iostream>
#include "DBManager.h"
#include "Model.h"
#include "EngineerController.h"
#include "EmployeeController.h"
#include "FinanceController.h"

using EmployeeDB::DBManager;
using EmployeeDB::Model::Engineer, EmployeeDB::Controller::EngineerController;
using EmployeeDB::Model::Employee, EmployeeDB::Controller::EmployeeController;
using EmployeeDB::Model::Finance, EmployeeDB::Controller::FinanceController;

int main() {
	DBManager& db = DBManager::instance();

    Finance dummyEmployee;

    // Set dummy values for all attributes
    dummyEmployee.setFirstName("Deep");
    dummyEmployee.setMiddleName("B.");
    dummyEmployee.setLastName("Patel");
    dummyEmployee.setEmail("deep@gmail.com");
    dummyEmployee.setAddress("valsad, Gujarat");
    dummyEmployee.setDateOfBirth("17-04-2003");
    dummyEmployee.setDateOfJoining("01-01-2025");
    dummyEmployee.setPerformanceMetric(10);
    dummyEmployee.setMobileNumber(9888665552);
    dummyEmployee.setGender(EmployeeDB::Model::Gender::Male);
    dummyEmployee.setDepartmentID(101);
    dummyEmployee.setManagerID(201);
    dummyEmployee.setBonus(50000);

    dummyEmployee.setAccountingTool("Excel");

    //EngineerController::createEngineer(dummyEmployee);
    FinanceController::createFinance(dummyEmployee);
    
    //db.executeSelectQuery("Select Employee.*,Engineer.technology from Employee inner join Engineer On Employee.employeeID = Engineer.employeeID");
    //std::cout << db.getResultString() << '\n';

    db.executeSelectQuery("Select Employee.*,Finance.accountingTool from Employee inner join Finance On Employee.employeeID = Finance.employeeID");
    std::cout << db.getResultString() << '\n';

	return 0;
}