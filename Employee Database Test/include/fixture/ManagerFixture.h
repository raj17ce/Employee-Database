#ifndef __ManagerFixture_H__
#define __ManagerFixture_H__

#include "../../pch.h";
#include "./model/Manager.h"

using EmployeeDB::Model::Manager;
using EmployeeDB::Model::Gender;

class ManagerFixture : public testing::Test {
public:
    void SetUp() {
        manager = std::make_unique<Manager>();
        updateManager = std::make_unique<Manager>(true);

        manager->setFirstName("John");
        manager->setMiddleName("Doe");
        manager->setLastName("Smith");
        manager->setDateOfBirth("15-05-1990");
        manager->setMobileNumber(1234567891);
        manager->setEmail("john.smith@example.com");
        manager->setAddress("123 Main St, City, Country");
        manager->setGender(Gender::Male);
        manager->setDateOfJoining("10-01-2020");
        manager->setDepartmentID(1);
        manager->setMentorID(0);
        manager->setPerformanceMetric(0.85);
        manager->setBonus(500);

        manager->setManagerID(1);
        manager->setTeamSize(15);
        manager->setYearsOfExperience(10.0);
        manager->setProjectTitle("Project A");
        manager->setRole("Java");
    }

    std::unique_ptr<Manager> manager;
    std::unique_ptr<Manager> updateManager;
};

#endif