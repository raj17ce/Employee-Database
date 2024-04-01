#ifndef __HRFixture_H__
#define __HRFixture_H__

#include "../../pch.h";
#include "./model/HR.h"

using EmployeeDB::Model::HR;
using EmployeeDB::Model::Gender;

class HRFixture : public testing::Test {
public:
    void SetUp() {
        hr = std::make_unique<HR>();
        updateHr = std::make_unique<HR>(true);

        hr->setFirstName("Michael");
        hr->setMiddleName("James");
        hr->setLastName("Johnson");
        hr->setDateOfBirth("12-12-1985");
        hr->setMobileNumber(4567890128);
        hr->setEmail("michael.johnson@example.com");
        hr->setAddress("789 Oak St, City, Country");
        hr->setGender(Gender::Male);
        hr->setDateOfJoining("05-03-2019");
        hr->setDepartmentID(3);
        hr->setMentorID(0);
        hr->setPerformanceMetric(0.9);
        hr->setBonus(600);

        hr->setHRSpecialization("Recruitment");
    }

    std::unique_ptr<HR> hr;
    std::unique_ptr<HR> updateHr;
};

#endif