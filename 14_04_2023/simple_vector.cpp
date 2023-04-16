#include "simple_vector.h"


// <typ_zwracany> nazwa_klasy::nazwa_metody(parametry) { definicja }

double& simple_vector::operator[](int i) { // w ten sposób zwracamy wartoœæ do odczytu i zapisu
	// tablica
	// cout << tablica[i]
	// tablica[i] = 5.0 - mo¿liwe
	if (i >= array_size || i < 0) {
		throw "Wrong index";
	}

	else {
		return pointer_to_values[i];
	}
}

// konstruktor/destruktor
// konstruktor: nazwa_klasy::konstruktor(parametry) { definicja }
// destruktor: nazwa_klasy::~destruktor() { definicja }

// destruktor

simple_vector::~simple_vector() {
	delete[] pointer_to_values;
}