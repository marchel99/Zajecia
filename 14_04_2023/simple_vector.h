#ifndef simple_vector_h
#define simple_vector_h

class simple_vector {
private:
	double* pointer_to_values;
	const unsigned array_size;

public:
	//simple_vector(unsigned size) {
	//	pointer_to_values = new double[size]; // w ten sposób alokujemy "tablicê" o wielkoœci size
		// int* variable = new int; // w ten sposób alokujemy pamiêæ na zwyk³¹ zmienn¹
	//}

	simple_vector(unsigned size) // drugi sposób na inicjalizacjê zmiennych obiektu
		: pointer_to_values(new double[size]), array_size(size) { /*dalsze czynnoœci*/ }

	~simple_vector();

	/*double operator[](int i) { // w ten sposób zwracamy wartoœæ do odczytu
							   // tablica
		                       // cout << tablica[i]
							   // tablica[i] = 5.0 - niemo¿liwe
		if (i >= array_size || i < 0) {
			throw "Wrong index";
		}

		else {
			return pointer_to_values[i];
		}
	}*/

	double& operator[](int i);
};

#endif