#ifndef MACIERZ_HH
#define MACIERZ_HH

#include "rozmiar.h"
#include <iostream>

class Macierz {

   Wektor tabM[ROZMIAR];

  public:

    Macierz(Wektor A, Wektor B, Wektor C);

    const Wektor & operator *(const Wektor & B);
    double wyznacznik(); //Sarrus
    Macierz transponuj() const;

    Wektor & operator [](int index); // W[2][0] - zerowy element drugiego wektora
    double & operator () (int ind1, int ind2); // M(2,0)

    Macierz & operator + (const MacierzKw & B);
    Macierz & operator - (const MacierzKw & B);
    Macierz & operator * (const MacierzKw & B);
    Macierz & operator * (double B);

    bool operator == (const MacierzKw & W2) const;
    bool operator != (const MacierzKw & W2) const;


 //   Macierz odwroc() const;


};

std::istream& operator >> (std::istream &Strm, Macierz &Mac);

std::ostream& operator << (std::ostream &Strm, const Macierz &Mac);


#endif
