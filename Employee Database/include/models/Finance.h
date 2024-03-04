#ifndef __Finance_H__
#define __Finance_H__

#include "Config.h";
#include "Employee.h"

namespace EmployeeDB::Model {
	class Finance : public Employee {
	public:
		void setAccountingTool(const std::string& accountingTool) {
			m_AccountingTool = accountingTool;
		}

		const std::string& getAccountingTool() const {
			return m_AccountingTool;
		}

		double computeSalary() override;
	private:
		std::string m_AccountingTool;
	};
}

#endif