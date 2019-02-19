#ifndef ZESPOLONA_H
#define ZESPOLONA_H
#include <iostream>
#include <string>

class Zespolona
{

    /*klasa reprezentujaca liczbe zespolona:
    Re - wartosc rzeczywista
    Im - wartosc urojona
    nazwa - nazwa nadana liczbie przez uzytkownika, lub domyslnie (z1, z2 itd)
    ile - zmienna identyczna dla wszystkich obiektow, mowi o tym ile obiektow jest w tej chwili utworzonych
    ktory - mowi o tym, ktorym z kolei utworzonym obiektem jest dany obiekt*/
private:
    double Re;
    double Im;
    std::string nazwa;
    int static ile; //licznik utworzonych obiektow
    int ktory;      //numer obiektu
public:
    Zespolona(double x=0, double y=0, std::string name="z");
    ~Zespolona();

    bool operator==(Zespolona*);
    bool operator!=(Zespolona*);
    Zespolona operator+(Zespolona*);
    void operator+=(Zespolona*);
    Zespolona operator-(Zespolona*);
    void operator-=(Zespolona*);
    Zespolona operator*(Zespolona*);
    void operator*=(Zespolona*);
    Zespolona operator/(Zespolona*);
    void operator/=(Zespolona*);
    friend std::ostream& operator<<(std::ostream&, const Zespolona&);
    double getRe();
    double getIm();
};

/*funkcja check porownuje dwie liczby typu double, przy pomocy bardzo malej liczby epsilon, zeby
    uniknac bledow zaokraglen*/

bool check(double, double);
#endif // HEDD_H_INCLUDED

