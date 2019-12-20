#include "Keyable.h"

namespace ATable {
	Keyable::Keyable(string key) {
		this->key = key;
	}


	Keyable::~Keyable() {}


	string Keyable::getKey() {
		return this->key;
	}
}
