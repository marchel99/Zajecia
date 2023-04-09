# Zajecia

Stworzyć program, który poprosi użytkownika o liczbę (wybór działania) i poprosi o dwa argumenty
stworzyć 4 funkcje (dodawanie, odejmowanie, dzielenie, mnożenie) i stworzyć tablicę wskaźników przechowujących te 4 funkcje 
funkcja, która ma być wywołana z podanymi przez użytkownika argumentami ma indeks taki, jak liczba, którą użytkownik podał jako wybór
float dodaj(float a, float b);
float odejmij(float a, float b);
float mnoz(float a, float b);
float dziel(float a, float b);
int x; // pobieramy wybór
float a, b; // pobieramy argumenty
pf dzialania[4]{
dodaj, odejmij, mnoz, dziel
};
printf("Wynik działania to: %f\n" dzialania[x](a, b));
