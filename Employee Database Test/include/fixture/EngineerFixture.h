#ifndef __EngineerFixture_H__
#define __EngineerFixture_H__

#include "../../pch.h";
#include "./model/Engineer.h"

using EmployeeDB::Model::Engineer;
using EmployeeDB::Model::Gender;

class EngineerFixture : public testing::Test {
public:
    void SetUp() {
        engineer = std::make_unique<Engineer>();
        updateEngineer = std::make_unique<Engineer>(true);

        engineer->setFirstName("John");
        engineer->setMiddleName("Doe");
        engineer->setLastName("Smith");
        engineer->setDateOfBirth("15-05-1990");
        engineer->setMobileNumber(1234567891);
        engineer->setEmail("john.smith@example.com");
        engineer->setAddress("123 Main St, City, Country");
        engineer->setGender(Gender::Male);
        engineer->setDateOfJoining("10-01-2020");
        engineer->setDepartmentID(1);
        engineer->setMentorID(0);
        engineer->setPerformanceMetric(0.85);
        engineer->setBonus(500);
        engineer->setTechnology("Java");
    }

    std::unique_ptr<Engineer> engineer;
    std::unique_ptr<Engineer> updateEngineer;
};

#endif