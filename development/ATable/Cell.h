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
   version 1.0.1
*/
#include "TableObject.h"
#include <string>
#include <iostream>

namespace ATable {
	class Cell : public TableObject {
	private:
		unsigned int width;
	public:
		Cell();
		~Cell();
		Cell(Cell* input);
		virtual string output() = 0; // virtual function, which should return string, which well display in table cell
		void print(ostream& stream); // prints sata to stream (for debug)
		void setWidth(unsigned int width); // sets the width of cell
		unsigned int getWidth(); // returns the width of cell
	private:
		string boundary(string value); // crops the text by cell width
	};
}
