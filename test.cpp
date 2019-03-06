#include "complex.h"

using namespace std;

int main()
{
    cout<<"Program zawierajacy klase Zespolona i testujacy ja"<<endl;
    cout<<"Autor: Pawel Lech"<<endl<<endl;

    //wczytanie danych dla dwoch liczb zespolonych od uzytkownika:
    cout<<"Podaj czesc rzeczywista i czesc urojona pierwszej liczby"<<endl;
    double a,b,c,d;
    cin>>a>>b;
    cout<<"Podaj czesc rzeczywista i czesc urojona drugiej liczby"<<endl;
    cin>>c>>d;
    cout<<"Za chwile zostana utworzone dwie zespolone liczby: "<<endl<<endl;
    Complex *z1;
    Complex *z2;
    z1 = new Complex(a,b);
    z2 = new Complex(c,d);

    /*z1 = new Complex(2,4.5, "z1");
    z2 = new Complex(1,-3.7, "z2");*/

    /*sprawdzenia przeciazenia operatora <<:*/
    cout<<endl<<"z1: "<<*z1<<endl;
    cout<<"z2: "<<*z2<<endl;

    cout<<endl<<"Utworzona zostaje kolejna liczba zespolona, sluzaca do przechowywania"<<endl<<"wynikow dzialan:"<<endl;
    Complex *result;
    result = new Complex(0,0, "wynik");

    /*sprawdzenie przeciazen operatorów +,-,*,/:*/
    cout<<endl<<"***   DODAWANIE   ***"<<endl;
    *result = *z1+z2;
    cout<<"Wynik dodawania: "<<*result<<" ";
    /*sprawdzenie polega na porównaniu wartosci Re i Im w liczbie wynik z wartosciami obliczonymi "recznie" w programie, analogicznie dla innych operatorów*/
    if(( check(result->getRe(), z1->getRe()+z2->getRe()) ) && (check(result->getIm(), z1->getIm()+z2->getIm())))
        cout<<"\t\t[OK]"<<endl<<endl;
    else
        cout<<endl<<"\t\t[FAIL]"<<endl<<endl;

    cout<<"***   ODEJMOWANIE   ***"<<endl;
    *result = *z1-z2;
    cout<<"Wynik odejmowania: "<<*result<<" ";
    if(( check(result->getRe(), z1->getRe()-z2->getRe())) && (check(result->getIm(), z1->getIm()-z2->getIm())))
        cout<<"\t\t[OK]"<<endl<<endl;
    else
    {cout<<endl<<endl<<*result<<endl<<endl;
        cout<<endl<<"\t\t[FAIL]"<<endl<<endl;}

    cout<<"***   MNOZENIE   ***"<<endl;
    *result = *z1*z2;
    cout<<"Wynik mnozenia: "<<*result<<" ";
    if(( check(result->getRe(), z1->getRe()*z2->getRe()-z1->getIm()*z2->getIm())) && (check(result->getIm(), z1->getIm()*z2->getRe()+z2->getIm()*z1->getRe())))
        cout<<"\t\t[OK]"<<endl<<endl;
    else
        cout<<"\t\t[FAIL]"<<endl<<endl;

    cout<<"***   DZIELENIE   ***"<<endl;
    try{
    *result = *z1/z2;
    cout<<"Wynik dzielenia: "<<*result<<" ";
    if((check(result->getRe(), (z1->getRe()*z2->getRe()+z1->getIm()*z2->getIm())/(z2->getRe()*z2->getRe()+z2->getIm()*z2->getIm()))) && check(result->getIm(),((z1->getIm()*z2->getRe()-z1->getRe()*z2->getIm())/(z2->getRe()*z2->getRe()+z2->getIm()*z2->getIm()))))
        cout<<"\t[OK]"<<endl<<endl;
    else
        cout<<"\t[FAIL]"<<endl<<endl;}
    catch(string oops)
    {
        cout<<endl<<"blad: "<<oops<<endl<<endl;
    }

    /*sprawdzenie przeciazen operatorow +=,-=,*=,/=:*/

    cout<<"***   DODAWANIE W MIEJSCU   ***"<<endl;
    /*oldRe i oldIm powstaja tylko w celu przeprowadzenia dzialania "recznie", inaczej nie mozna byloby tego zrobic, poniewaz wartosci Re i Im liczby z1 zostaja zmienione*/
    double oldRe = z1->getRe();
    double oldIm = z1->getIm();
    *z1+=z2;
    cout<<"Nowe z1: "<<*z1;
    if(check(z1->getRe(),oldRe+z2->getRe()) && check(z1->getIm(),oldIm+z2->getIm()))
        cout<<"\t\t\t[OK]"<<endl<<endl;
    else
        cout<<"\t\t\t[FAIL]"<<endl<<endl;

    cout<<"***   ODEJMOWANIE W MIEJSCU   ***"<<endl;
    oldRe = z1->getRe();
    oldIm = z1->getIm();
    *z1-=z2;
    cout<<"Nowe z1: "<<*z1;
    if(check(z1->getRe(),oldRe-z2->getRe()) && check(z1->getIm(),oldIm-z2->getIm()))
        cout<<"\t\t\t\t[OK]"<<endl<<endl;
    else
        cout<<"\t\t\t[FAIL]"<<endl<<endl;

    cout<<"***   MNOZENIE W MIEJSCU   ***"<<endl;
    oldRe = z1->getRe();
    oldIm = z1->getIm();
    *z1*=z2;
    cout<<"Nowe z1: "<<*z1;
    if(check(z1->getRe(),oldRe*z2->getRe()-oldIm*z2->getIm()) && check(z1->getIm(),oldIm*z2->getRe()+oldRe*z2->getIm()))
        cout<<"\t\t\t[OK]"<<endl<<endl;
    else
        cout<<"\t\t\t[FAIL]"<<endl<<endl;

    cout<<"***   DZIELENIE W MIEJSCU   ***"<<endl;
    try{
    oldRe = z1->getRe();
    oldIm = z1->getIm();
    *z1/=z2;
    cout<<"Nowe z1: "<<*z1;
    if((check(z1->getRe(), (oldRe*z2->getRe()+oldIm*z2->getIm())/(z2->getRe()*z2->getRe()+z2->getIm()*z2->getIm()))) && check(z1->getIm(),((oldIm*z2->getRe()-oldRe*z2->getIm())/(z2->getRe()*z2->getRe()+z2->getIm()*z2->getIm()))))
        cout<<"\t\t\t\t[OK]"<<endl<<endl;
    else
        cout<<"\t\t\t[FAIL]"<<endl<<endl;}
    catch(string oops)
    {
        cout<<endl<<"blad: "<<oops<<endl<<endl;
    }

    //sprawdzenie przeciazen operatorów == i !=:

    cout<<"***   POROWNANIA   ***"<<endl;
    Complex *z3;
    z3 = new Complex(z1->getRe(),z1->getIm(),"jak_z1"); //zostaje utworzona liczba zespolona identyczna do z1 w celu sprawdzenia operatora ==
    cout<<*z1<<" == "<<*z3;
    if(*z1==z3)
        cout<<"\t\t\t[OK]"<<endl;
    else
        cout<<"\t\t\t[FAIL]"<<endl;

    if(*z1==z2) //jezeli z1 == z2, powstaje nowa zmienna z4 != z1, w celu przetestowania tego operatora
    {
        cout<<endl<<"uwaga: z1==z2, wiec na potrzeby testu != powstaje kolejna liczba zespolona: "<<endl;
        Complex *z4;
        z4 = new Complex(z1->getRe()+1,z1->getIm()+1,"z4");
        cout<<endl<<*z1<<" != "<<*z4;
        if(*z1!=z4)
            cout<<"\t\t\t[OK]"<<endl;
        else
            cout<<"\t\t\t[FAIL]"<<endl;
        delete z4;
    }
    else //jezeli z1 != z2, testujemy operator != przy uzyciu z2
    {
        cout<<*z1<<" != "<<*z2;
        if(*z1!=z2)
            cout<<"\t\t\t\t[OK]"<<endl;
        else
            cout<<"\t\t\t[FAIL]"<<endl;
    }
    cout<<endl<<endl<<endl;
    delete z1;
    delete z2;
    delete z3;

    return 0;
}
