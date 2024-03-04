#ifndef __QA_H__
#define __QA_H__

#include "Config.h";
#include "Employee.h"

namespace EmployeeDB::Model {
	class QA : public Employee {
	public:
		void setTestingTool(const std::string& testingTool) {
			m_TestingTool = testingTool;
		}

		const std::string& getTestingTool() const {
			return m_TestingTool;
		}

		double computeSalary() override;
	private:
		std::string m_TestingTool;
	};
}

#endif