#include <stdio.h>
#include "dummy.h"
#include "nd_dummy.h"
 
#include <stdlib.h>
#include <time.h>
 
void fun();
 
struct book {
    char title[30];
    char author[30];
    int publish_date;
};
 
void fn1(struct book* b) {
    // działamy na oryginale, ponieważ przy wywołaniu tworzona jest tylko zmienna
    // wskaźnikowa, która przyjmuje jako wartość adres do struktury
 
    // w tej funkcji możemy zmodyfikować pola struktury TRWALE
}
 
void fn2(struct book b) {
    // działamy na kopii, ponieważ przy wywołaniu tworzona jest zmienna typu struct book,
    // wszystkie pola struktury są do tej zmiennej kopiowane
 
    // wszelkie modyfikacje widoczne tylko na lokalnej kopii w funkcji
    // po zakończeniu działania funkcji, zmienna przestaje istnieć
}
 
// funkcja fn1 stworzy zmienną wskaźnikową, która będzie miała (prawdopodobnie) 4 bajty
// funkcja fn2 stworzy zmienną, która będzie miała (więcej niż) 64 bajty
 
// wniosek? nawet jeśli tworzymy zmienną tylko do odczytu, warto jest korzystać ze wskaźników
// przy większych zmiennych (np. struktury, floaty, double etc.) ze względu na mniejsze zużycie pamięci
 
void fun1() {
    printf("Hello from fn 1\n");
}
 
void fun2() {
    printf("Hello from fn 2\n");
}
 
void fun3() {
    printf("Hello from fn 3\n");
}
 
// typedef <typ_zwracany przez funkcje> (*<nazwa typu>)(<lista_typów_parametrów>)
 
typedef void (*pf)();
 
int main(void) {
    pf my_functions[3] = {
        fun1,
        fun2,
        fun3
    };
 
    srand(time(NULL)); // init generatora liczb pseudolosowych na podstawie czasu NOW
 
    for (int i = 0; i < 10; ++i) {
        int random = (rand() % 3); // rand generuje liczbę pseudolosową
                                   // % - operator zwraca nam resztę z dzielenia całkowitoliczbowego
                                   // 0 % 3 == 0
                                   // 2 % 3 == 2
                                   // 3 % 3 == 0
 
        my_functions[random]();    // wywołanie jednej z 3 funkcji w tablicy wskaźników 
                                   // wybór pseudolosowy
    }
 
    //fun();
 
    //for (;;) { // 3 wyrażenia, 1 - inicjalizacyjne wykonywane tylko raz przed pierwszym przebiegiem
               //pętli, 2 - warunek (wyrażenie) od którego zależy, czy kolejna (pierwsza) iteracja
               // zostanie wykonana, 3 - dowolne wyrażenie, wykonywane jest po wszystkich instrukcjach
               // w pętli
    //  printf("Hello");
    //}
 
    //for (1; 0; 3) { // pętla nieskończona
    //  printf("Hello");
    //}
 
    //for (int i = 0; i < 3; ++i) {
    //  printf("%d\n", i);
    //}
 
    // while(wyrazenie){} //instrukcje będą wykonywane dopóki wyrażenie jest prawdziwe
 
    // do{} while(wyrażenie); //wykona się conajmniej raz
 
    // uint8_t - u == unsigned, int == integer
}
 
void fun() {
    printf("Hello");
}