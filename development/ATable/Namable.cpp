#include "Namable.h"


namespace ATable {
	Namable::Namable(string name) {
		this->name = name;
	}


	Namable::~Namable() {}


	string Namable::getName() {
		return this->name;
	}


	void Namable::setName(string name) {
		this->name = name;
	}
}
