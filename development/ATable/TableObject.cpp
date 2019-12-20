#include "TableObject.h"

namespace ATable {
	TableObject::TableObject() {
	}


	TableObject::~TableObject() {
	}


	TableObject* TableObject::clone() {
		TableObject* clone = new TableObject();
		*clone = *this;
		return clone;
	}
}
