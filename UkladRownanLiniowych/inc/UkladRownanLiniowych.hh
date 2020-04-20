#ifndef UKLADROWNANLINIOWYCH_HH
#define UKLADROWNANLINIOWYCH_HH

#include <iostream>

class UkladRownanLiniowych {

    Macierz A; // Ax = b
    Wektor b;

  public:

    Wektor & rozwiaz() const;
    UkladRownanL() const;
    UkladRownanL(const Macierz & M, const Wektor & W);
    const Wektor & Zwroc_wektor_wolny();
    void Zmien_wektor_wolny(const Wektor & W);
    const Macierz & Zwroc_macierz();
    void Zmien_macierz(const Macierz & M);
};


std::istream& operator >> (std::istream &Strm, UkladRownanLiniowych &UklRown);

std::ostream& operator << ( std::ostream                  &Strm,
                            const UkladRownanLiniowych    &UklRown
                          );


#endif
