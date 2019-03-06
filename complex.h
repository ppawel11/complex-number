#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>
#include <string>

class Complex
{

    /*klasa reprezentujaca liczbe zespolona:
    Re - wartosc rzeczywista
    Im - wartosc urojona
    name - nazwa nadana liczbie przez uzytkownika, lub domyslnie (z1, z2 itd)
    how_many - zmienna identyczna dla wszystkich obiektow, mowi o tym ile obiektow jest w tej chwili utworzonych
    which - mowi o tym, ktorym z kolei utworzonym obiektem jest dany obiekt*/
private:
    double Re;
    double Im;
    std::string name;
    int static how_many; //licznik utworzonych obiektow
    int which;      //numer obiektu
public:
    Complex(double x=0, double y=0, std::string new_name="z");
    ~Complex();

    bool operator==(Complex*);
    bool operator!=(Complex*);
    Complex operator+(Complex*);
    void operator+=(Complex*);
    Complex operator-(Complex*);
    void operator-=(Complex*);
    Complex operator*(Complex*);
    void operator*=(Complex*);
    Complex operator/(Complex*);
    void operator/=(Complex*);
    friend std::ostream& operator<<(std::ostream&, const Complex&);
    double getRe();
    double getIm();
};

/*funkcja check porownuje dwie liczby typu double, przy pomocy bardzo malej liczby epsilon, zeby
    uniknac bledow zaokraglen*/

bool check(double, double);
#endif // COMPLEX_H_INCLUDED

