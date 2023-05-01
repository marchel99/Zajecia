#include <iostream>
#include <string>
 
using namespace std;
 
class Book{
private:
	string title;
	string publisher;
	string author;
	int year;
	int pages;
 
public:
	// 1. funkcja swoją nazwą powinna sugerować działanie (czasownik)
	// count_elements - sugeruje, że będzie zliczać elementy
	// get_mean - sugeruje, że zwróci średnią arytmetyczną
	// get_title - sugeruje, że zwróci tytuł
	// 2. jedna funkcja == jedna odpowiedzialność
	// get_title powinno wyłącznie zwrócić autora a nie poprosić użytkownika 
	// o podanie autora, nadpisanie zmiennej obiektu i zwrotu tej wartości
	// funkcja obliczająca średnią arytmetyczną powinna TYLKO obliczać średnią 
	// arytmetyczną z podanych elementów a nie dodatkowo 
	// uzupełniać bufor wartościami i dopiero wtedy liczyć
	// get_mean(const int* data, unsigned count);
	// get_data(int* data, unsigned max_elements);
	// 2. zmienne warto nazywać tak, aby sugerowały co przechowują (rzeczownik)
	// apple_quantity
 
	/*string get_title() {
		return title;
	}*/ // tworzony jest oddzielny obiekt, który zajmuje dodatkową pamięć (zwracamy kopię)
 
	const string& get_title() const { 
		return title; // zwracamy stałą referencję do pola title, przez co
		// odczytujemy oryginał i nie zajmujemy niepotrzebnie dodatkowej pamięci
	}
 
	const string& get_publisher() const {
		return publisher;
	}
 
	const string& get_author() const {
		return author;
	}
 
	int get_year() {
		return year;
	}
 
	int get_pages() {
		return pages;
	}
 
 
	void set_title(string t) {
		title = t;
	}
 
	void set_publisher(string p) {
		publisher = p;
	}
 
	void set_author(string a) {
		author = a;
	}
 
	void set_year(int y) {
		year = y;
	}
 
	void set_pages(int p) {
		pages = p;
	}
 
	friend ostream& operator<<(ostream& os, const Book& book) {
		os << "Author: " << book.author << ", Title: " << book.title
			<< ", Publisher: " << book.publisher << ", Year: "
			<< book.year << ", Pages: " << book.pages;
 
		return os;
	}
};
 
class simple_vector {
private:
	Book* array_of_books;
	const unsigned array_size;
 
public:
	simple_vector(unsigned size) // drugi spos�b na inicjalizacj� zmiennych obiektu
		: array_of_books(new Book[size]), array_size(size) { /*dalsze czynno�ci*/
	}
 
	~simple_vector() {
		delete[] array_of_books;
	}
 
	Book& operator[](int i) {
		if (i >= 0 && i < array_size) {
			return array_of_books[i];
		}
		else {
			throw("Wrong index\n");
		}
	}
};
 
int main(void) {
	simple_vector shelf(10);
 
}