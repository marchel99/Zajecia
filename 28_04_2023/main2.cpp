#include <iostream>
#include <string>
 
using namespace std;
 
class animal {
private:
	int _count_legs;
	unsigned _size;
	string _sound;
 
protected:
	const string& get_sound() const {
		return _sound;
	}
 
public:
	animal(int count_legs, unsigned size, string sound):
		_count_legs(count_legs), _size(size), _sound(sound) { }
 
	virtual void give_sound() = 0;
};
 
// dziedziczenie publiczne: dziedzicząc publicznie, klasa otrzymuje wszystkie właściwości i metody
// klasy bazowej, pola private są niedostępne, dlatego warto pomyśleć o metodach set/get jeśli jest to
// potrzebne
 
// dziedziczenie prywatne: dziedzicząc prywatnie klasa otrzymuje JEDEN OBIEKT klasy bazowej
// 
 
class tiger : public animal {
private:
	int _tail_len;
 
public:
	tiger(int count_legs, unsigned size, string sound, int tail_len):
		animal(count_legs, size, sound), _tail_len(tail_len) { }
	// najpierw inicjalizujemy klasy bazowe, później pola klasy pochodnej (obecnej)
 
	virtual void give_sound() {
		cout << "Tiger says: " << get_sound() << endl;
	}
};
 
/* class point {
private:
	float _x, _y;
 
public:
	point(float x, float y) {
		_x = x; _y = y;
	}
 
	virtual ~point() = 0;
}; */
 
void print_sound_of_animal(animal& a) {
	a.give_sound();
}
 
int main(void) {
	tiger t(4, 40, "Roar", 50);
 
	// a.give_sound();
 
	// dynamic_cast<animal*>(&t)->give_sound();
	// pobieramy adres obiektu typu tiger,
	// rzutujemy 
 
	print_sound_of_animal(t);
}