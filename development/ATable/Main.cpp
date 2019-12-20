#include <iostream>
#include "ATable.h"

using namespace std;

int main() {
	ATable::Table* table = new ATable::Table(ATable::DefaultAppearance(), "Test table"); // creating a new table with default borders

	table->addColumn(new ATable::IdColumn("id")); // creating column with id
	table->addColumn(new ATable::SimpleColumn("Type", 20, "type")); // creating column with different cells adding ability with name "type" ans width: 20
	table->addColumn(new ATable::ConstColumn("-->", "arrow")); // creating column with NO ability of field difference
	table->addColumn(new ATable::SimpleColumn("Fields", 30, "fields")); // creating column with different cells adding ability with name "fields" ans width: 30
	table->addColumn(new ATable::SimpleColumn("Empty", 5, "empty")); // creating column with different cells adding ability with name "fields" ans width: 30

	table->addCell("type", new ATable::StringCell("String cell example")); // adding to column with key: "type" a new string cell with text: "String cell example"
	table->addCell("fields", new ATable::StringCell("Hello darkness my old friend")); // adding to column with key: "fields" a new string cell with text: "Hello darkness my old friend"

	table->addCell(1, new ATable::StringCell("Integer cell example")); // adding to column with id: 0 a new string cell with text: "Integer cell example"
	table->addCell(3, new ATable::IntegerCell(228)); // adding to column with id: 2 a new integer cell with value: 228

	table->addCell(1, new ATable::StringCell("Float cell example")); // adding to column with id: 0 a new string cell with text: "Float cell example"
	table->addCell(3, new ATable::FloatCell(1488.228)); // adding to column with id: 2 a new float cell with value: 1488.228
	table->addCell(3, new ATable::StringCell("Hello")); // adding to column with id: 2 a new float cell with value: 1488.228
	table->addCell(1, new ATable::IntegerCell(10));
	table->addCell(1, new ATable::IntegerCell(10));
	table->addCell(1, new ATable::IntegerCell(10));
	table->addCell(1, new ATable::IntegerCell(10));
	table->addCell(1, new ATable::IntegerCell(10));


	table->print(cout); //printing the table to cout stream
	cout << endl << (*table) << endl;

	delete table; // deleting table
}

