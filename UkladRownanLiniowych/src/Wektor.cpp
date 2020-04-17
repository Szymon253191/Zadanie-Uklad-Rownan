#include "Wektor.hh

Wektor(double xx, double yy, double zz)
{
    tabW[0] = xx;
    tabW[1] = yy;
    tabW[2] = zz;
}

const double & operator [](int index) const
{
    if(index < 0 || index > 3)
    {
        std::cerr<<"Poza zakresem"<<endl;
        exit (1);
    }
    else return tabW[index];
}

double & operator [](int index)
{
    if(index < 0 || index > 3)
    {
        std::cerr<<"Poza zakresem"<<endl;
        exit (1);
    }
    else return tabW[index];
}

Wektor operator + (const & Wektor W2) const
{
    Wektor Wynik;
    for (int i=0; i<ROZMIAR; i++)
    {
        Wynik[i] = W2[i] + tabW[i];
    }
    return Wynik;
}

Wektor operator - (const & Wektor W2) const
{
    Wektor Wynik;
    for (int i=0; i<ROZMIAR; i++)
    {
        Wynik[i] = tabW[i] - W2[i];
    }
    return Wynik;
}

double operator * (const Wektor & W2) const
{
    return tab[0] * W2[0] + tabW[1] * W2[1] + tabW[2] * W2[2];
}

Wektor operator * (double L2)  const// W1 * L2
{
    Wektor Wynik;
    for (int i=0; i<ROZMIAR; i++)
    {
        Wynik[i] = tabW[i] * L2;
    }
    return Wynik;
}

Wektor operator * (double L1, Wektor W2)  const// L1 * W2
{
    Wektor Wynik;
    for (int i=0; i<ROZMIAR; i++)
    {
        Wynik[i] = L1 * W2[i];
    }
    return Wynik;
}

Wektor operator / (double L2) const
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
            Wynik[i] = tabW[i] / L2;
        }
        return Wynik;
    }
}

double dlugosc()
{
    double Wynik;
    Wynik = sqrt((tabW[0]*tabW[0]) + (tabW[1]*tabW[1]) + (tabW[2]*tabW[2]);
    return Wynik;
}

bool operator == (const Wektor W2)
{
    if (tabW[0] == W2[0] && tabW[1] == W2[1] && tabW[2] == W2[2])
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool operator != (const Wektor W2)
{
    if !(tabW[0] == W2[0] && tabW[1] == W2[1] && tabW[2] == W2[2])
    {
        return true;
    }
    else
    {
        return false;
    }
}

std::istream& operator >> (std::istream &Strm, Wektor &Wek)
{
    char znak;
    Strm >> znak;
    if (znak != '(') strm.setstate(std::ios::failbit);
    Strm >> Wek[0] >> znak;
    if (znak != ',') strm.setstate(std::ios::failbit);
    Strm >> Wek[1] >> znak;
    if (znak != ',') strm.setstate(std::ios::failbit);
    Strm >> Wek[2] >> znak;
    if (znak != ')') strm.setstate(std::ios::failbit);
    return Strm;
}

std::ostream& operator << (std::ostream &Strm, const Wektor &Wek)
{
    Strm << "(" << Wek[0] << "," << Wek[1] << "," << Wek[2] << ")";
    return Strm;
}
