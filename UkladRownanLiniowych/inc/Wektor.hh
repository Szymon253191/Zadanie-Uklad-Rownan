#ifndef WEKTOR_HH
#define WEKTOR_HH

#include "rozmiar.h"
#include <iostream>


/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
class Wektor {
  /*
   *  Tutaj trzeba wstawic definicje odpowiednich pol i metod prywatnych
   */
    double tabW[ROZMIAR]
  public:
  /*
   *  Tutaj trzeba wstawic definicje odpowiednich metod publicznych
   */
    Wektor (double xx, double yy, double zz);
    const double & operator [](int index) const;
    double & operator [](int index);

    Wektor operator + (const & Wektor W2) const;
    Wektor operator - (const Wektor & W2) const;
    double operator * (const Wektor & W2) const;
    Wektor operator * (double L2) const; // W1 * 3
    Wektor operator / (double L2) const;

    double dlugosc();

    bool operator == (const Wektor W2);
    bool operator != (const Wektor W2);
};

Wektor operator * (double L1, Wektor W2); // 3 * W2


std::istream& operator >> (std::istream &Strm, Wektor &Wek);

std::ostream& operator << (std::ostream &Strm, const Wektor &Wek);

#endif
