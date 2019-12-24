#include "Appearance.h"
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

namespace ATable {
	Appearance::Appearance() {
		this->left_top_corner = ' ';
		this->right_top_corner = ' ';
		this->left_bottom_corner = ' ';
		this->right_bottom_corner = ' ';
		this->vertical_line = ' ';
		this->horizontal_line = ' ';
		this->left_separator = ' ';
		this->right_separator = ' ';
		this->top_separator = ' ';
		this->bottom_separator = ' ';
		this->center_separator = ' ';
	}


	Appearance::~Appearance() {
	}


	void Appearance::print(ostream& stream) {
		stream << "left_top_corner: " << left_top_corner << endl;
		stream << "right_top_corner: " << right_top_corner << endl;
		stream << "left_bottom_corner: " << left_bottom_corner << endl;
		stream << "right_bottom_corner: " << right_bottom_corner << endl;
		stream << "vertical_line: " << vertical_line << endl;
		stream << "horizontal_line: " << horizontal_line << endl;
		stream << "left_separator: " << left_separator << endl;
		stream << "right_separator: " << right_separator << endl;
		stream << "top_separator: " << top_separator << endl;
		stream << "bottom_separator: " << bottom_separator << endl;
		stream << "center_separator: " << center_separator << endl;

	}


	ostream& operator<<(ostream& stream, Appearance obj) {
		obj.print(stream);
		return stream;
	}


	ostream& operator<<(ostream& stream, Appearance* obj) {
		return operator<<(stream, *obj);
	}

}
