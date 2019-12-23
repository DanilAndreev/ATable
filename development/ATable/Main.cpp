/*
   Appearance.cpp, Cell.cpp Column.cpp, ConstColumn.cpp IdColumn.cpp Keyable.cpp
   Nameable.cpp NamedColumn.cpp SimpleColumn.cpp Table.cpp TableObject.cpp
   Appearance.h ATble.h Cell.h Column.h ConstColumn.h DefaultAppearance.h DefaultCells.h
   IdColumn.h Keyable.h Nameable.h NamedColumn.h SimpleColumn.h Table.h TableExceptions.h TableObject.h
   Copyright (C) 2019 Andrieiev Danil
   This source code is provided 'as-is', without any express or implied
   warranty. In no event will the author be held liable for any damages
   arising from the use of this software.
   Permission is granted to anyone to use this software for any purpose,
   including commercial applications, and to alter it and redistribute it
   freely, subject to the following restrictions:
   1. The origin of this source code must not be misrepresented; you must not
	  claim that you wrote the original source code. If you use this source code
	  in a product, an acknowledgment in the product documentation would be
	  appreciated but is not required.
   2. Altered source versions must be plainly marked as such, and must not be
	  misrepresented as being the original source code.
   3. This notice may not be removed or altered from any source distribution.
   Andrieiev Danil danssg08@gmail.com
   version 1.0.1
*/
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

