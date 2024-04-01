#ifndef __QAFixture_H__
#define __QAFixture_H__

#include "../../pch.h";
#include "./model/QA.h"

using EmployeeDB::Model::QA;
using EmployeeDB::Model::Gender;

class QAFixture : public testing::Test {
public:
    void SetUp() {
        qa = std::make_unique<QA>();
        updateQa = std::make_unique<QA>(true);

        qa->setFirstName("Emily");
        qa->setMiddleName("Anne");
        qa->setLastName("Williams");
        qa->setDateOfBirth("25-10-1988");
        qa->setMobileNumber(9870723456);
        qa->setEmail("emily.williams@example.com");
        qa->setAddress("101 Pine St, City, Country");
        qa->setGender(Gender::Female);
        qa->setDateOfJoining("15-02-2021");
        qa->setDepartmentID(4);
        qa->setMentorID(0);
        qa->setPerformanceMetric(0.82);
        qa->setBonus(550);

        qa->setTestingTool("Selenium");
    }

    std::unique_ptr<QA> qa;
    std::unique_ptr<QA> updateQa;
};

#endif