#include <iostream>
#include "DBManager.h"
#include "Model.h"
#include "EmployeeController.h"

using EmployeeDB::DBManager, EmployeeDB::Model::Employee, EmployeeDB::Controller::EmployeeController;

int main() {
	DBManager& db = DBManager::instance();

    //Employee dummyEmployee;

    //// Set dummy values for all attributes
    //dummyEmployee.setFirstName("John");
    //dummyEmployee.setMiddleName("Robert");
    //dummyEmployee.setLastName("Doe");
    //dummyEmployee.setEmail("john.Doe@example.com");
    //dummyEmployee.setAddress("123 Main St, Cityville");
    //dummyEmployee.setDateOfBirth("1990-01-01");
    //dummyEmployee.setDateOfJoining("2020-05-15");
    //dummyEmployee.setPerformanceMetric(4.5);
    //dummyEmployee.setMobileNumber(1234567890);
    //dummyEmployee.setGender(EmployeeDB::Model::Gender::Male);
    //dummyEmployee.setEmployeeId(1001);
    //dummyEmployee.setDepartmentId(101);
    //dummyEmployee.setManagerId(201);
    //dummyEmployee.setBonus(5000);

    //EmployeeController::createEmployee(dummyEmployee);

    std::cout<<EmployeeController::selectEmployeeId("john.Doe@example.com")<<'\n';

	return 0;
}