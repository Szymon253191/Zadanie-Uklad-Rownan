#include "Wektor.hh"

Wektor::Wektor(double xx, double yy, double zz)
{
    tab[0] = xx;
    tab[1] = yy;
    tab[2] = zz;
}

Wektor::Wektor()
{
    for(int i=0; i<ROZMIAR; i++)
    {
        tab[i]=0;
    }
}

double & Wektor::operator [](int index)
{
    if(index < 0 || index > 3)
    {
        std::cerr<<"Poza zakresem"<<endl;
        exit (1);
    }
    else return tab[index];
}

double & Wektor::operator [](int index)
{
    if(index < 0 || index > 3)
    {
        std::cerr<<"Poza zakresem"<<endl;
        exit (1);
    }
    else return tab[index];
}

Wektor Wektor::operator + (const Wektor & W2) const
{
    Wektor Wynik;
    for (int i=0; i<ROZMIAR; i++)
    {
        Wynik[i] = W2[i] + tab[i];
    }
    return Wynik;
}

Wektor Wektor::operator - (const Wektor & W2) const
{
    Wektor Wynik;
    for (int i=0; i<ROZMIAR; i++)
    {
        Wynik[i] = tab[i] - W2[i];
    }
    return Wynik;
}

double Wektor::operator * (const Wektor & W2) const
{
    double Wynik = 0;
    for (int i=0; i<ROZMIAR; i++)
    {
        Wynik += tab[i] * W2[i];
    }
    return Wynik;
}

Wektor Wektor::operator * (double L2)  const// W1 * L2
{
    Wektor Wynik;
    for (int i=0; i<ROZMIAR; i++)
    {
        Wynik[i] = tab[i] * L2;
    }
    return Wynik;
}

/*Wektor Wektor::operator * (double L1, Wektor W2)  const// L1 * W2
{
    Wektor Wynik;
    for (int i=0; i<ROZMIAR; i++)
    {
        Wynik[i] = L1 * W2[i];
    }
    return Wynik;
}
*/
Wektor Wektor::operator / (double L2) const
{
    if (L2 == 0)
    {
        std::cerr<<"Blad, dzielenie przez zero";
        exit(1);
    }
    else
    {
        Wektor Wynik;
        for (int i=0; i<ROZMIAR; i++)
        {
            Wynik[i] = tab[i] / L2;
        }
        return Wynik;
    }
}

double Wektor::dlugosc()
{
    double Wynik;
    Wynik = sqrt((tab[0]*tab[0]) + (tab[1]*tab[1]) + (tab[2]*tab[2]));
    return Wynik;
}

bool Wektor::operator == (const Wektor & W2) const
{
    double epsilon=0.000001;
    for (int i=0; i<ROZMIAR; i++)
    {
        if (abs(tab[i]-W2[i] > epsilon))
        {
            return false;
        }
        else return true;
    }
}

bool Wektor::operator != (const Wektor & W2) const
{
    double epsilon=0.000001;
    for (int i=0; i<ROZMIAR; i++)
    {
        if (abs(tab[i]-W2[i] < epsilon))
        {
            return false;
        }
        else return true;
    }
}

std::istream & operator >> (std::istream & strm, Wektor & Wek)
{
    char znak;
    strm >> znak;
    if (znak != '(') strm.setstate(std::ios::failbit);
    strm >> Wek[0] >> znak;
    if (znak != ',') strm.setstate(std::ios::failbit);
    strm >> Wek[1] >> znak;
    if (znak != ',') strm.setstate(std::ios::failbit);
    strm >> Wek[2] >> znak;
    if (znak != ')') strm.setstate(std::ios::failbit);
    return strm;
}

std::ostream & operator << (std::ostream & strm, const Wektor & Wek)
{
    strm << "(" << Wek[0] << "," << Wek[1] << "," << Wek[2] << ")";
    return strm;
}
