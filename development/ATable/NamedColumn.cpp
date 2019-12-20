#include "NamedColumn.h"

namespace ATable {
	NamedColumn::NamedColumn(unsigned int width, string name, string key) : Column(width, key), Namable(name) {}


	NamedColumn::~NamedColumn() {}
}


