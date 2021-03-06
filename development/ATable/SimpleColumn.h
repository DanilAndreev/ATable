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
#include "Cell.h"
#include "NamedColumn.h"
#include <vector>

namespace ATable {
	class SimpleColumn : public NamedColumn{
	public:
		string name;
	protected:
		vector<Cell*>* cells;
	public:
		SimpleColumn(string name, unsigned int width, string key);
		~SimpleColumn();
		void addCell(Cell* cell); // adds cell cell to column
		void editCell(size_t row_id, Cell* cell); // edits cell cell to column
		Cell* getCell(int id); // returns cell on position id
		Cell* getCellClone(int id); // returns new instance of cell on position id
		unsigned int getHeight(); // returns height of column (number of cells inside)
	};
}

