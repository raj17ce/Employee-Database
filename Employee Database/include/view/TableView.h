#ifndef __TableView_H__
#define __TableView_H__

namespace EmployeeDB::View {

	class TableView {
	public:
		static bool createTable();
	private:
		static void getAttributesInput(Table& obj);
		static void getForeignKeysInput(Table& obj);
	};
}

#endif