#include "ConstColumn.h"


namespace ATable {
	ConstColumn::ConstColumn(string value, string key) : Column(value.length(), key){
		this->cell = new StringCell(value);
		this->cell->setWidth(this->getWidth());
	}


	ConstColumn::~ConstColumn() {
		delete cell;
	}


	Cell* ConstColumn::getCell(int id) {
		return this->cell;
	}


	Cell * ConstColumn::getCellClone(int id) {
		return dynamic_cast<Cell*>(this->cell->clone());
	}
}

