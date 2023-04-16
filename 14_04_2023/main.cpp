#include <iostream>
#include "simple_vector.h"

using namespace std;

class complex {
private:
	// umieszczamy elementy, kt�re nie powinny by� dost�pne bezpo�rednio
	// dla programisty
	double real, imag;
public:
	// umieszczamy elementy interfejsu, z kt�rych programista mo�e korzysta�
	// metody (funkcje klasy) przeprowadzaj�ce operacje na obiekcie (ustaw nasz�
	// zmienn� rzeczywist� na x, ustaw zmienn� urojon� na y, podaj warto��
	// zmiennej rzeczywistej, dodaj, odejmij, podziel, pomn� etc.)

	// 3 przeci��enia konstruktora (polimorfizm, przeci��anie funkcji i metod)
	complex(){ // specjalna metoda zwana konstruktorem
			   // programista nie mo�e jej wywo�a� na obiekcie,
			   // s�u�y ona do inicjalizacji obiektu
		       // konstruktor bez parametr�w to "konstruktor domy�lny"
		real = 0;
		imag = 0;
	}

	complex(double r, double i) { // na podstawie parametr�w dostarczonych 
							// konstruktorowi tworzymy obiekt
		real = r; imag = i; 
	}

	complex(const complex& c) { // konstruktor kopiuj�cy nasz obiekt
		real = c.real; // w tym wypadku nie jest to a� tak wa�ne,
		imag = c.imag; // ale warto pami�ta� o takiej mo�liwo�ci przy
					   // dynamicznej alokacji pami�ci
	}

	~complex() { // jest to metoda, kt�ra jest wywo�ywana, gdy obiekt znajdzie si�
			     // poza scopem (zasi�giem)
		// implementacja destruktora
		// sekcja, w kt�rej mo�emy np. zwolni� pami��
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

// przeci��ony operator przesuni�cia bitowego (w C++ stosowany do wypisywania, zapisu do plik�w)
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
// poj�cie pod kt�rym kryje si� przeci��anie nazw i operator�w
// funkcje musz� mie� inne nag��wki, aby kompilator wiedzia�,
// kt�ra funkcja ma by� wywo�ana

void fun1(int& i) {
	i += 10;
	cout << "Zmodyfikowalem zmienna\n";
}

//void fun1(int& j) {
// nag��wek taki sam jak w definicji powy�ej
//}

//void fun1(int i) {
// nag��wek nie jest co prawda dok�adnie taki sam, ale kompilator nie b�dzie
// w stanie wybra� odpowiedniej funkcji bo obydwie funkcje da si� wywo�a� 
// ze zmienn� typu int
//}

void fun1() {
	cout << "Druga wersja funkcji\n";
}

int main() {
	complex a; // konstruktor domy�lny
	complex b(5, 5); // konstruktor z parametrami

	if (true) {
		complex c(1, 2);
		// jaki� kod 
	} // koniec �ycia zmiennej c

	int i = 5;
	int* pt_i = nullptr; // wska�nik typu int
	int& ref = i; // wymaga inicjalizatora

	pt_i = &i; // wska�nik przechowuje adres zmiennej i

	// spos�b stosowania

	//operator<<(cout, a); 

	cout << a << endl; // cout << a; zwraca -> cout 
			           // cout << endl;

	cout << "Zmienna o adresie " << &i << " przechowuje wartosc " << i << endl;
	cout << "Zmienna wskaznikowa o adresie " << &pt_i << " przechowuje wartosc " << pt_i << endl;
	cout << "Zmienna referencyjna o adresie " << &ref << " przechowuje wartosc " << ref << endl;

	// adres zmiennej referencyjnej i orygina�u jest dok�adnie taki sam
	// oznacza to, �e jest to jedna i ta sama zmienna pod dwiema r�nymi nazwami

	fun1(i);

	cout << "Wartosc zmiennej po wywolaniu funkcji: " << i << endl;

	fun1();

	int x = 1, y = 2;

	cout << x + y << endl; // z "x + y" pozostaje wyra�enie typu int, kt�re ma warto�� x + y

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
			array[i] = i * 2 + 1; // 2x + 1, zapis do element�w tablicy
			cout << "2 * " << i << " + 1 = " << array[i] << endl; // odczyt z tablicy
		}
		catch (const char* msg) {
			cout << msg << endl;
		}
	}
}