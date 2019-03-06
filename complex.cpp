#include "complex.h"
#include <cmath>

using namespace std;

int Complex::how_many = 0;

bool check(double x, double y)
{
    double eps = 0.000001;
    if(abs(x-y)<eps)
        return true;
    return false;
}

Complex::Complex(double x, double y, string new_name)
{
    how_many++; /*konstruktor dodaje 1 do zmiennej liczacej stworzone liczby*/
    which = how_many;
    name = new_name;
    Re = x;
    Im = y;
    if(name=="z") /*jezeli zostala nadana domyslna nazwa program bedzie wypisywal z1,z2 itd, dla nadanej unikalnej nazwy wypisze te nazwe*/
        cout<<"Uruchomiony konstruktor liczby zespolonej z"<<which<<endl;
    else
        cout<<"Uruchomiony konstruktor liczby zespolonej "<<name<<endl;
}
Complex::~Complex()
{
    how_many--; /*destruktor odejmuje 1 od zmiennej liczacej stworzone liczby*/
    if(name=="z")
        cout<<"Uruchomiony destruktor liczby zespolonej z"<<which<<endl;
    else
        cout<<"Uruchomiony destruktor liczby zespolonej "<<name<<endl;
}
Complex Complex::operator+(Complex *y)
{
    /*zostaje utworzona liczba zespolona suma, ktorej wartosc rzeczywista i urojona zostaja utworzone, przez dodanie odpowiednich wartosci dwoch dodawanych liczb,
    analogicznie dziala to dla pozostalych dzialan*/
    Complex *result;
    result = new Complex(0,0,"suma");
    result->Re = Re + y->Re;
    result->Im = Im + y->Im;
    return *result;
}
void Complex::operator+=(Complex *y)
{
    /*w przypadku dzialan w miejscu, nie zostaje utworzony nowy obiekt, zmieniane sa parametry obiektu znajdujacego sie po lewej stronie operatora*/
    Re += y->Re;
    Im += y->Im;
    return;
}
Complex Complex::operator-(Complex *y)
{
    Complex *result;
    result = new Complex(0,0,"roznica");
    result->Re = Re - y->Re;
    result->Im = Im - y->Im;
    return *result;
}
void Complex::operator-=(Complex *y)
{
    Re -= y->Re;
    Im -= y->Im;
    return;
}
Complex Complex::operator*(Complex *y)
{
    Complex *result;
    result = new Complex(0,0,"iloczyn");
    result->Re = Re*y->Re-Im*y->Im;
    result->Im = Im*y->Re+Re*y->Im;
    return *result;
}
void Complex::operator*=(Complex *y)
{
    double r = Re;
    double i = Im;
    Re = r*y->Re-i*y->Im;
    Im = i*y->Re+r*y->Im;
    return;
}
Complex Complex::operator/(Complex *y)
{
    if((y->Re == 0)&&(y->Im==0))
    {
        //jezeli liczba przekazana do argumentu jest rowna 0+0i operator wyrzuca wyjatek
        string err = "dzielenie przez zero";
        throw err;
    }
   	Complex *result;
    result = new Complex(0,0,"iloraz");
    result->Re = (Re*y->Re+Im*y->Im)/(y->Re*y->Re+y->Im*y->Im);
    result->Im = (Im*y->Re-Re*y->Im)/(y->Re*y->Re+y->Im*y->Im);
    return *result;

}
void Complex::operator/=(Complex *y)
{
    if((y->Re == 0)&&(y->Im==0))
    {
        //jezeli liczba przekazana do argumentu jest rowna 0+0i operator wyrzuca wyjatek
        string err = "dzielenie przez zero";
        throw err;
    }
    double r = Re;
    double i = Im;
    Re = (r*y->Re+i*y->Im)/(y->Re*y->Re+y->Im*y->Im);
    Im = (i*y->Re-r*y->Im)/(y->Re*y->Re+y->Im*y->Im);
    return;
}
bool Complex::operator==(Complex *y)
{
    if ((check(Re,y->Re))&&(check(Im,y->Im)))
        return true;
    return false;
}
bool Complex::operator!=(Complex *y)
{
    if ((check(Re,y->Re))&&(check(Im,y->Im)))
        return false;
    return true;
}
ostream& operator<<(ostream& output, const Complex& z)
{
    if (z.Im>=0)
        output << z.Re << '+' << z.Im <<'i';
    else
        output << z.Re << z.Im <<'i';
    return output;
}
double Complex::getRe()
{
    return Re;
}
double Complex::getIm()
{
    return Im;
}

