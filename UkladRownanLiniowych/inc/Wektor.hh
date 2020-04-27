#ifndef WEKTOR_HH
#define WEKTOR_HH

#include "rozmiar.h"
#include <iostream>
#include <math.h>
using namespace std;

/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
class Wektor {

    double tabW[ROZMIAR];

  public:

    Wektor (double xx, double yy, double zz);
    Wektor ();
    const double & operator [](int index) const;
    double & operator [](int index);

    Wektor operator + (Wektor const & W2) const;
    Wektor operator - (Wektor const & W2) const;
    double operator * (Wektor const & W2) const;
    Wektor operator * (double L2) const; // W1 * 3
    Wektor operator / (double L2) const;

    double dlugosc();

    bool operator == (const Wektor W2);
    bool operator != (const Wektor W2);
};

Wektor operator * (double L1, Wektor W2); // 3 * W2


std::istream& operator >> (std::istream & strm, Wektor &Wek);

std::ostream& operator << (std::ostream & strm, const Wektor &Wek);

#endif
