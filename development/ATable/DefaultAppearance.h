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
#include "Appearance.h"

namespace ATable {
	class DefaultAppearance : public Appearance {
	public:
		DefaultAppearance() {
			this->left_top_corner = 218;
			this->right_top_corner = 191;
			this->left_bottom_corner = 192;
			this->right_bottom_corner = 217;
			this->top_separator = 194;
			this->bottom_separator = 193;
			this->left_separator = 195;
			this->right_separator = 180;
			this->center_separator = 197;
			this->vertical_line = 179;
			this->horizontal_line = 196;
		}
	};
}
