#ifndef UKLADROWNANLINIOWYCH_HH
#define UKLADROWNANLINIOWYCH_HH

#include <iostream>

class UkladRownanLiniowych {

    Macierz A; // Ax = b
    Wektor b;

  public:

    Wektor & rozwiaz() const;
    UkladRownanL(){};
    UkladRownanL(const Macierz & M, const Wektor & W);
    UkladRownanL(Macierz _A, Wektor _b): A(_A), b(_b);
    Wektor & Zwroc_wektor_wolny() const;
    void Zmien_wektor_wolny(const Wektor & W);
    Macierz & Zwroc_macierz() const;
    void Zmien_macierz(const Macierz & M);
};


std::istream& operator >> (std::istream &Strm, UkladRownanLiniowych &UklRown);

std::ostream& operator << ( std::ostream                  &Strm,
                            const UkladRownanLiniowych    &UklRown
                          );


#endif
