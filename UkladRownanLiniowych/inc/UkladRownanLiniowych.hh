#ifndef UKLADROWNANLINIOWYCH_HH
#define UKLADROWNANLINIOWYCH_HH

#include <iostream>

class UkladRownanLiniowych {

    Macierz A; // Ax = b
    Wektor b;

  public:

    const Wektor & rozwiaz();
    UkladRownanL();
    UkladRownanL(const Macierz & M, const Wektor & W);
    const Wektor & Zwroc_wektor_wolny();
    void Zmien_wektor_wolny(const Wektor & W);
    //analogicznie dla macierzy
};


std::istream& operator >> (std::istream &Strm, UkladRownanLiniowych &UklRown);

std::ostream& operator << ( std::ostream                  &Strm,
                            const UkladRownanLiniowych    &UklRown
                          );


#endif
