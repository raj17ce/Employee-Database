#include "../../pch.h";
#include "./model/HR.h"

using EmployeeDB::Model::HR;
using EmployeeDB::Model::Gender;

class HRFixture : public testing::Test {
public:
    void SetUp() {
        hr = new HR{};
        emptyHr = new HR{};

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

    void TearDown() {
        delete hr;
        delete emptyHr;
    }
private:
    HR* hr;
    HR* emptyHr;
};