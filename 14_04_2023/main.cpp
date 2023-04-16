#include <iostream>
#include "simple_vector.h"

using namespace std;

class complex {
private:
	// umieszczamy elementy, które nie powinny byæ dostêpne bezpoœrednio
	// dla programisty
	double real, imag;
public:
	// umieszczamy elementy interfejsu, z których programista mo¿e korzystaæ
	// metody (funkcje klasy) przeprowadzaj¹ce operacje na obiekcie (ustaw nasz¹
	// zmienn¹ rzeczywist¹ na x, ustaw zmienn¹ urojon¹ na y, podaj wartoœæ
	// zmiennej rzeczywistej, dodaj, odejmij, podziel, pomnó¿ etc.)

	// 3 przeci¹¿enia konstruktora (polimorfizm, przeci¹¿anie funkcji i metod)
	complex(){ // specjalna metoda zwana konstruktorem
			   // programista nie mo¿e jej wywo³aæ na obiekcie,
			   // s³u¿y ona do inicjalizacji obiektu
		       // konstruktor bez parametrów to "konstruktor domyœlny"
		real = 0;
		imag = 0;
	}

	complex(double r, double i) { // na podstawie parametrów dostarczonych 
							// konstruktorowi tworzymy obiekt
		real = r; imag = i; 
	}

	complex(const complex& c) { // konstruktor kopiuj¹cy nasz obiekt
		real = c.real; // w tym wypadku nie jest to a¿ tak wa¿ne,
		imag = c.imag; // ale warto pamiêtaæ o takiej mo¿liwoœci przy
					   // dynamicznej alokacji pamiêci
	}

	~complex() { // jest to metoda, która jest wywo³ywana, gdy obiekt znajdzie siê
			     // poza scopem (zasiêgiem)
		// implementacja destruktora
		// sekcja, w której mo¿emy np. zwolniæ pamiêæ
		cout << "Goodbye\n";
	}

	double get_real() { return real; }
	double get_imag() { return imag; }

	void set_real(double i) { real = i; }
	void set_imag(double i) { imag = i; }

	complex& operator+=(const complex& c) {
		real += c.real;
		imag += c.imag;
		
		// this - adres aktualnego obiektu
		// *this - obiekt

		return *this;
	}

	complex& operator-=(const complex& c) {
		real -= c.real;
		imag -= c.imag;

		// this - adres aktualnego obiektu
		// *this - obiekt

		return *this;
	}
};

complex operator+(complex& c1, complex& c2) {
	complex result;

	result.set_real(c1.get_real() + c2.get_real());
	result.set_imag(c1.get_imag() + c2.get_imag());

	return result;
}

complex operator-(complex& c1, complex& c2) {
	complex result;

	result.set_real(c1.get_real() - c2.get_real());
	result.set_imag(c1.get_imag() - c2.get_imag());

	return result;
}

// przeci¹¿ony operator przesuniêcia bitowego (w C++ stosowany do wypisywania, zapisu do plików)
ostream& operator<<(ostream& os, complex& c) {
	os << c.get_real();
	
	double imag = c.get_imag();

	if (imag >= 0.0) {
		os << " + ";
	}
	else {
		os << " - ";
	}

	os << "j" << imag;

	return os;
}

ostream& operator<<(ostream& os, complex&& c) {
	os << c.get_real();

	double imag = c.get_imag();

	if (imag >= 0.0) {
		os << " + ";
	}
	else {
		os << " - ";
	}

	os << "j" << imag;

	return os;
}

// polimorfizm
// pojêcie pod którym kryje siê przeci¹¿anie nazw i operatorów
// funkcje musz¹ mieæ inne nag³ówki, aby kompilator wiedzia³,
// która funkcja ma byæ wywo³ana

void fun1(int& i) {
	i += 10;
	cout << "Zmodyfikowalem zmienna\n";
}

//void fun1(int& j) {
// nag³ówek taki sam jak w definicji powy¿ej
//}

//void fun1(int i) {
// nag³ówek nie jest co prawda dok³adnie taki sam, ale kompilator nie bêdzie
// w stanie wybraæ odpowiedniej funkcji bo obydwie funkcje da siê wywo³aæ 
// ze zmienn¹ typu int
//}

void fun1() {
	cout << "Druga wersja funkcji\n";
}

int main() {
	complex a; // konstruktor domyœlny
	complex b(5, 5); // konstruktor z parametrami

	if (true) {
		complex c(1, 2);
		// jakiœ kod 
	} // koniec ¿ycia zmiennej c

	int i = 5;
	int* pt_i = nullptr; // wskaŸnik typu int
	int& ref = i; // wymaga inicjalizatora

	pt_i = &i; // wskaŸnik przechowuje adres zmiennej i

	// sposób stosowania

	//operator<<(cout, a); 

	cout << a << endl; // cout << a; zwraca -> cout 
			           // cout << endl;

	cout << "Zmienna o adresie " << &i << " przechowuje wartosc " << i << endl;
	cout << "Zmienna wskaznikowa o adresie " << &pt_i << " przechowuje wartosc " << pt_i << endl;
	cout << "Zmienna referencyjna o adresie " << &ref << " przechowuje wartosc " << ref << endl;

	// adres zmiennej referencyjnej i orygina³u jest dok³adnie taki sam
	// oznacza to, ¿e jest to jedna i ta sama zmienna pod dwiema ró¿nymi nazwami

	fun1(i);

	cout << "Wartosc zmiennej po wywolaniu funkcji: " << i << endl;

	fun1();

	int x = 1, y = 2;

	cout << x + y << endl; // z "x + y" pozostaje wyra¿enie typu int, które ma wartoœæ x + y

	cout << "Liczba a: " << a << endl;

	cout << "Liczba b: " << b << endl;

	cout << "a + b: " << a + b << endl;

	cout << "a - b: " << a - b << endl;

	a += b;

	cout << "zmienna a po operacji += : " << a << endl;

	cout << "a + b: " << a + b << endl;

	simple_vector array(10); // tworzymy "wektor" 10 liczb typu double

	for (int i = 0; i < 11; ++i) {
		try {
			// operator[](int i) 
			array[i] = i * 2 + 1; // 2x + 1, zapis do elementów tablicy
			cout << "2 * " << i << " + 1 = " << array[i] << endl; // odczyt z tablicy
		}
		catch (const char* msg) {
			cout << msg << endl;
		}
	}
}