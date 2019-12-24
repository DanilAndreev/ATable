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
#include "Table.h"

namespace ATable {
	Table::Table(Appearance preset, string name) {
		this->preset = preset;
		this->name = name;
		this->columns = new vector<Column*>();
	}


	Table::~Table() {
		for (unsigned int col = 0; col < this->columns->size(); col++) {
			Column* temp = this->getColumn(col);
			delete temp;
		}
		delete this->columns;
	}


	void Table::addColumn(Column* column) {
		this->columns->push_back(column);
	}


	void Table::addCell(int column, Cell* cell) {
		try {
			SimpleColumn* scolumn = dynamic_cast<SimpleColumn*>(this->getColumn(column));
			if (scolumn) {
				scolumn->addCell(cell);
			}
		}
		catch (WrongIDException e){
		}
	}


	void Table::addCell(string column_key, Cell* cell) {
		int id = this->getColumnId(column_key);
		if (id == -1) {
			throw KeyNotExistException();
		}
		this->addCell(id, cell);
	}

	void Table::editCell(string column_key, size_t cell_id, Cell* cell) {
		int id = this->getColumnId(column_key);
		if (id == -1) {
			throw KeyNotExistException();
		}
		this->editCell(id, cell_id, cell);
	}

	void Table::editCell(size_t column_id, size_t cell_id, Cell* cell) {
		try {
			SimpleColumn* scolumn = dynamic_cast<SimpleColumn*>(this->getColumn(column_id));
			if (scolumn) {
				scolumn->editCell(cell_id, cell);
			}
		}
		catch (WrongIDException e) {
		}
	}


	void Table::print(ostream & stream) {
		try {
			//Top line
			this->drawLine(stream, this->preset.left_top_corner, this->preset.horizontal_line, this->preset.top_separator, this->preset.right_top_corner);

			//Output headers			
			this->drawColumnsHeaders(stream, this->preset.vertical_line);
			this->drawLine(stream, this->preset.left_separator, this->preset.horizontal_line, this->preset.center_separator, this->preset.right_separator);
			
			//Rows
			unsigned int maxRowHeight = this->getMaxRowHeight();
			for (size_t row = 0; row < maxRowHeight; row++) {
				this->drawRow(stream, row, this->preset.vertical_line);
				if (row < maxRowHeight - 1) {
					this->drawLine(stream, this->preset.left_separator, this->preset.horizontal_line, this->preset.center_separator, this->preset.right_separator);
				}
			}
			//Bottom line
			this->drawLine(stream, this->preset.left_bottom_corner, this->preset.horizontal_line, this->preset.bottom_separator, this->preset.right_bottom_corner);

		}
		catch (exception e) {
			stream << "Unable to print table [" << this->name << "]" << endl;
		}
	}


	Column* Table::getColumn(int id) {
		if (!(id < this->columns->size())) {
			throw WrongIDException();
		}
		return (*(this->columns))[id];
	}


	Column* Table::getColumn(string key) {
		int id = this->getColumnId(key);
		if (id == -1) {
			return nullptr;
		}
		return this->getColumn(id);
	}


	int Table::getColumnId(string key) {
		for (size_t i = 0; i < this->columns->size(); i++) {
			if (this->getColumn(i)->getKey() == key) {
				return i;
			}
		}
		return -1;
	}


	void Table::drawLine(ostream& stream, char left_corner, char horizontal_line, char center_separator, char right_corner) {
		stream << left_corner;
		for (unsigned int col = 0; col < this->columns->size(); col++) {
			stream << string(this->getColumn(col)->getWidth(), horizontal_line);
			if (col < this->columns->size() - 1) {
				stream << center_separator;
			}
		}
		stream << right_corner << endl;
	}


	void Table::drawRow(ostream& stream, unsigned int row, char vertical_line) {
		stream << vertical_line;
		for (unsigned int col = 0; col < this->columns->size(); col++) {
			try {
				Cell* cell = this->getColumn(col)->getCellClone(row);
				cell->print(stream);
				delete cell;
			}
			catch (WrongIDException e) {
				stream << string(this->getColumn(col)->getWidth(), ' ');
			}
					
			
			stream << vertical_line;
		}
		stream << endl;
	}


	void Table::drawColumnsHeaders(ostream& stream, char vertical_line) {
		stream << vertical_line;
		for (unsigned int col = 0; col < this->columns->size(); col++) {
			Column* column = this->getColumn(col);
			NamedColumn* scolumn = dynamic_cast<NamedColumn*>(column);
			if (scolumn) {
				stream << boundary(scolumn->getName(), scolumn->getWidth());
			}
			else {
				stream << string(column->getWidth(),' ');
			}
			stream << vertical_line;
		}
		stream << endl;
	}


	unsigned int Table::getMaxRowHeight() {
		unsigned int maxHeight = 0;
		for (size_t i = 0; i < this->columns->size(); i++) {
			SimpleColumn* scolumn =	dynamic_cast<SimpleColumn*>(this->getColumn(i));
			if (scolumn) {
				unsigned int temp = scolumn->getHeight();
				if (maxHeight < temp) {
					maxHeight = temp;
				}
			}
		}
		return maxHeight;
	}


	string Table::boundary(string value, int width) {
		if (value.length() < width) {
			return value + string(width - value.length(), ' ');
		}
		if (value.length() > width) {
			string temp = value;
			temp.resize(width);
			return temp;
		}
		return value;
	}


	ostream& operator<<(ostream& stream, Table& table) {
		table.print(stream);
		return stream;
	}
}
