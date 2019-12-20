#include "IdColumn.h"


namespace ATable{
	IdColumn::IdColumn(unsigned int width, string name, string key) : NamedColumn(width, name, key) {}


	IdColumn::~IdColumn() {}


	Cell * IdColumn::getCell(int id) {
		return nullptr;
	}


	Cell * IdColumn::getCellClone(int id) {
		Cell* temp = new IntegerCell(id);
		temp->setWidth(this->getWidth());
		return temp;
	}
}
