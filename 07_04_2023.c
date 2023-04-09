#include <stdio.h>

float dodaj(float a, float b);
float odejmij(float a, float b);
float mnoz(float a, float b);
float dziel(float a, float b);

typedef float (*pf)(float, float); // typedef dla wskaźnika na funkcję

int main() {
    pf dzialania[4] = {dodaj, odejmij, mnoz, dziel}; // tablica wskaźników na funkcje
    
    int x;
    float a, b;
    printf("Podaj wybor dzialania (0-dodaj, 1-odejmij, 2-mnoz, 3-dziel): ");
    scanf("%d", &x);
    printf("Podaj dwa argumenty: ");
    scanf("%f %f", &a, &b);
    
    printf("Wynik dzialania to: %f\n", dzialania[x](a, b));
    
    return 0;
}

float dodaj(float a, float b) {
    return a + b;
}

float odejmij(float a, float b) {
    return a - b;
}

float mnoz(float a, float b) {
    return a * b;
}

float dziel(float a, float b) {
    return a / b;
}