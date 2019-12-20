#include "SimpleColumn.h"


namespace ATable {
	SimpleColumn::SimpleColumn(string name, unsigned int widht, string key) : NamedColumn(width, name, key){
		this->width = widht;
		this->cells = new vector<Cell*>();
	}


	SimpleColumn::~SimpleColumn() {
		for (unsigned int i = 0; i < this->cells->size(); i++) {
			delete this->getCell(i);
		}
		delete this->cells;
	}


	void SimpleColumn::addCell(Cell* cell) {
		cell->setWidth(this->width);
		this->cells->push_back(cell);
	}


	Cell* SimpleColumn::getCell(int id) {
		if (id >= this->cells->size()) {
			throw WrongIDException();
		}
		Cell* cell = (*(this->cells))[id];
		return cell;
	}


	Cell * SimpleColumn::getCellClone(int id) {
		try {
			Cell* cell = this->getCell(id);
			Cell* temp = dynamic_cast<Cell*>(cell->clone());
			return temp;
		}
		catch (WrongIDException e) {
			throw e;
		}
	}


	unsigned int SimpleColumn::getHeight() {
		return this->cells->size();
	}
}
