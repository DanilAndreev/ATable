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

namespace ATable {
	Cell::Cell() {
		this->width = 0;
	}


	Cell::~Cell() {
	}


	Cell::Cell(Cell * input) {
		this->width = input->width;
	}


	void Cell::print(ostream& stream) {
		stream << this->boundary(this->output());
	}


	void Cell::setWidth(unsigned int width) {
		this->width = width;
	}


	unsigned int Cell::getWidth() {
		return this->width;
	}


	string Cell::boundary(string value) {
		if (value.length() < this->width) {
			return value + string(this->width - value.length(), ' ');
		}
		if (value.length() > this->width) {
			string temp = value;
			temp.resize(this->width);
			return temp;
		}
		return value;
	}
}