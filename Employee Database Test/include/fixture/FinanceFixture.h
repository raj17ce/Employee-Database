#include "../../pch.h";
#include "./model/Finance.h"

using EmployeeDB::Model::Finance;
using EmployeeDB::Model::Gender;

class FinanceFixture : public testing::Test {
public:
    void SetUp() {
        finance = new Finance{};
        emptyFinance = new Finance{};

        finance->setFirstName("Jane");
        finance->setMiddleName("Doe");
        finance->setLastName("Smith");
        finance->setDateOfBirth("20-08-1992");
        finance->setMobileNumber(9876543211);
        finance->setEmail("jane.smith@example.com");
        finance->setAddress("456 Elm St, City, Country");
        finance->setGender(Gender::Female);
        finance->setDateOfJoining("20-05-2018");
        finance->setDepartmentID(2);
        finance->setMentorID(0);
        finance->setPerformanceMetric(0.75);
        finance->setBonus(400);

        finance->setAccountingTool("QuickBooks");
    }

    void TearDown() {
        delete finance;
        delete emptyFinance;
    }
private:
    Finance* finance;
    Finance* emptyFinance;
};