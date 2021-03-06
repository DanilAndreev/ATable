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
#include <cmath>

namespace ATable {
	class StringCell : public Cell {
	public:
		string value;
	public:
		StringCell(string value) {
			this->value = value;
		}
		StringCell(StringCell* input) {
			this->value = input->value;
		}
		string output() {
			return this->value;
		}
		virtual TableObject* clone() {
			Cell* clone = new StringCell(this->value);
			clone->setWidth(this->getWidth());
			return clone;
		}
	};

	class IntegerCell : public Cell {
	public:
		int value;
	public:
		IntegerCell(int value) {
			this->value = value;
		}
		IntegerCell(IntegerCell* input) {
			this->value = input->value;
		}
		string output() {
			return to_string(this->value);
		}
		virtual TableObject* clone() {
			Cell* clone = new IntegerCell(this->value);
			clone->setWidth(this->getWidth());
			return clone;
		}
	};

	class LongCell : public Cell {
	public:
		int value;
	public:
		LongCell(int value) {
			this->value = value;
		}
		LongCell(LongCell* input) {
			this->value = input->value;
		}
		string output() {
			return to_string(this->value);
		}
		virtual TableObject* clone() {
			Cell* clone = new LongCell(this->value);
			clone->setWidth(this->getWidth());
			return clone;
		}
	};

	class FloatCell : public Cell {
	public:
		float value;
		int percision;
	public:
		FloatCell(float value, int percision) {
			this->value = value;
			this->percision = percision;
		}
		FloatCell(float value) : FloatCell(value, 3) {}
		FloatCell(FloatCell* input) {
			this->value = input->value;
			this->percision = input->percision;
		}
		string output() {
			string integer = to_string((int)value);
			string fractional = to_string((int)(abs(value - (int)value) * pow(10, percision)));
			string result;
			result += integer + "." + fractional;
			return result;
		}
		virtual TableObject* clone() {
			Cell* clone = new FloatCell(this->value, this->percision);
			clone->setWidth(this->getWidth());
			return clone;
		}
	};

	class DoubleCell : public Cell {
	public:
		float value;
		int percision;
	public:
		DoubleCell(double value, int percision) {
			this->value = value;
			this->percision = percision;
		}
		DoubleCell(double value) : DoubleCell(value, 3) {}
		DoubleCell(DoubleCell* input) {
			this->value = input->value;
			this->percision = input->percision;
		}
		string output() {
			string integer = to_string((int)value);
			string fractional = to_string((int)(abs(value - (int)value) * pow(10, percision)));
			string result;
			result += integer + "." + fractional;
			return result;
		}
		virtual TableObject* clone() {
			Cell* clone = new DoubleCell(this->value, this->percision);
			clone->setWidth(this->getWidth());
			return clone;
		}
	};

}
