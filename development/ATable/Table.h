#pragma once
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
   version 1.0.2
*/
#include "TableObject.h"
#include "SimpleColumn.h"
#include "TableExceptions.h"
#include "Appearance.h"
#include <vector>
#include <iostream>
#include <cmath>

namespace ATable {
	class Table : public TableObject {
	public:
		vector<Column*>* columns;
		Appearance preset;
		string name;
	public:
		Table(Appearance preset, string name);
		~Table();
		void addColumn(Column* column); // adds column column to table
		void addCell(int column_id, Cell* cell); // adds cell cell to column with id column
		void addCell(string column_key, Cell* cell); // adds cell cell to column with key column_key
		void editCell(string column_key, size_t cell_id, Cell* cell); // edit cell cell in column with key column_key and row position cell_id
		void editCell(size_t column_id, size_t cell_id, Cell* cell); // edit cell cell in column with key column_key and row position cell_id
		virtual void print(ostream& stream); // prints table to stream stream
	private:
		Column* getColumn(int id); // returns column on position id
		Column* getColumn(string key); // returns column with key key
		int getColumnId(string key); // returns id of column with key key
		void drawLine(ostream & stream, char left_corner, char horizontal_line, char center_separator, char right_corner); // draws line to stream
		void drawRow(ostream & stream, unsigned int row, char vertical_line); // draws row of values to stream
		void drawColumnsHeaders(ostream& stream, char vertical_line); // draws columns headers to stream
		unsigned int getMaxRowHeight(); // returns height of the highest column in table
	public:
		static string boundary(string value, int width); // crops value by width width and returns cropped string
	public:
		friend ostream& operator<<(ostream& stream, Table& table);
	};
}

