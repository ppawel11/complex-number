#include "zespolona.h"
#include <cmath>

using namespace std;

int Zespolona::ile = 0;

bool check(double x, double y)
{
    double eps = 0.000001;
    if(abs(x-y)<eps)
        return true;
    return false;
}

Zespolona::Zespolona(double x, double y, string name)
{
    ile++; /*konstruktor dodaje 1 do zmiennej liczacej stworzone liczby*/
    ktory = ile;
    nazwa=name;
    Re = x;
    Im = y;
    if(nazwa=="z") /*jezeli zostala nadana domyslna nazwa program bedzie wypisywal z1,z2 itd, dla nadanej unikalnej nazwy wypisze te nazwe*/
        cout<<"Uruchomiony konstruktor liczby zespolonej z"<<ktory<<endl;
    else
        cout<<"Uruchomiony konstruktor liczby zespolonej "<<nazwa<<endl;
}
Zespolona::~Zespolona()
{
    ile--; /*destruktor odejmuje 1 od zmiennej liczacej stworzone liczby*/
    if(nazwa=="z")
        cout<<"Uruchomiony destruktor liczby zespolonej z"<<ktory<<endl;
    else
        cout<<"Uruchomiony destruktor liczby zespolonej "<<nazwa<<endl;
}
Zespolona Zespolona::operator+(Zespolona *y)
{
    /*zostaje utworzona liczba zespolona suma, ktorej wartosc rzeczywista i urojona zostaja utworzone, przez dodanie odpowiednich wartosci dwoch dodawanych liczb,
    analogicznie dziala to dla pozostalych dzialan*/
    Zespolona *wynik;
    wynik = new Zespolona(0,0,"suma");
    wynik->Re = Re + y->Re;
    wynik->Im = Im + y->Im;
    return *wynik;
}
void Zespolona::operator+=(Zespolona *y)
{
    /*w przypadku dzialan w miejscu, nie zostaje utworzony nowy obiekt, zmieniane sa parametry obiektu znajdujacego sie po lewej stronie operatora*/
    Re += y->Re;
    Im += y->Im;
    return;
}
Zespolona Zespolona::operator-(Zespolona *y)
{
    Zespolona *wynik;
    wynik = new Zespolona(0,0,"roznica");
    wynik->Re = Re - y->Re;
    wynik->Im = Im - y->Im;
    return *wynik;
}
void Zespolona::operator-=(Zespolona *y)
{
    Re -= y->Re;
    Im -= y->Im;
    return;
}
Zespolona Zespolona::operator*(Zespolona *y)
{
    Zespolona *wynik;
    wynik = new Zespolona(0,0,"iloczyn");
    wynik->Re = Re*y->Re-Im*y->Im;
    wynik->Im = Im*y->Re+Re*y->Im;
    return *wynik;
}
void Zespolona::operator*=(Zespolona *y)
{
    double r = Re;
    double i = Im;
    Re = r*y->Re-i*y->Im;
    Im = i*y->Re+r*y->Im;
    return;
}
Zespolona Zespolona::operator/(Zespolona *y)
{
    if((y->Re == 0)&&(y->Im==0))
    {
        //jezeli liczba przekazana do argumentu jest rowna 0+0i operator wyrzuca wyjatek
        string uwaga = "dzielenie przez zero";
        throw uwaga;
    }
    Zespolona *wynik;
    wynik = new Zespolona(0,0,"iloraz");
    wynik->Re = (Re*y->Re+Im*y->Im)/(y->Re*y->Re+y->Im*y->Im);
    wynik->Im = (Im*y->Re-Re*y->Im)/(y->Re*y->Re+y->Im*y->Im);
    return *wynik;

}
void Zespolona::operator/=(Zespolona *y)
{
    if((y->Re == 0)&&(y->Im==0))
    {
        //jezeli liczba przekazana do argumentu jest rowna 0+0i operator wyrzuca wyjatek
        string uwaga = "dzielenie przez zero";
        throw uwaga;
    }
    double r = Re;
    double i = Im;
    Re = (r*y->Re+i*y->Im)/(y->Re*y->Re+y->Im*y->Im);
    Im = (i*y->Re-r*y->Im)/(y->Re*y->Re+y->Im*y->Im);
    return;
}
bool Zespolona::operator==(Zespolona *y)
{
    if ((check(Re,y->Re))&&(check(Im,y->Im)))
        return true;
    return false;
}
bool Zespolona::operator!=(Zespolona *y)
{
    if ((check(Re,y->Re))&&(check(Im,y->Im)))
        return false;
    return true;
}
ostream& operator<<(ostream& output, const Zespolona& z)
{
    if (z.Im>=0)
        output << z.Re << '+' << z.Im <<'i';
    else
        output << z.Re << z.Im <<'i';
    return output;
}
double Zespolona::getRe()
{
    return Re;
}
double Zespolona::getIm()
{
    return Im;
}

