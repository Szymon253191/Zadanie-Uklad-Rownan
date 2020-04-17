#include "Macierz.hh"

Macierz(Wektor A, Wektor B, Wektor C)
{
    tabM[0] = A;
    tabM[1] = B;
    tabM[2] = C;
}

 const Wektor & operator *(const Wektor & B)
 {
    Wektor W;
    for (int i=0; i<ROZMIAR; i++)
    {
        for (int j=0; j<ROZMIAR; j++)
        {
            W[i] = W[i] + tabM[i][j] * B[j];
        }
    }
    return W;
 }

double wyznacznik() //Sarrus
{
    double wyz;
    wyz = (tabM[0][0]*tabM[1][1]*tabM[2][2]) + (tabM[0][1]*tabM[1][2]*tabM[2][0]) + (tabM[0][2]*tabM[1][0]*tabM[2][1]) - (tabM[0][2]*tabM[1][1]*tabM[2][0]) - (tabM[0][1]*tabM[1][0]*tabM[2][2]) - (tabM[0][0]*tabM[1][2]*tabM[2][1])
    return wyz;
}

Macierz transponuj() const
{
    Macierz M;
    for (int i=0; i<ROZMIAR; i++)
    {
        for (int j=0; i<ROZMIAR; j++)
        {
            M[i][j] = tabM[j][i];
        }
    }
    return M;
}

Wektor & operator [](int index)
{
    if(index < 0 || index > 3)
    {
        std::cerr<<"Poza zakresem"<<endl;
        exit (1);
    }
    else return tab[index];
}

double & operator () (int ind1, int ind2)
{
    if(ind1 < 0 || ind1 > ROZMIAR || ind2 < 0 || ind2 > ROZMIAR)
    {
        std::cerr<<"Poza zakresem"<<endl;
        exit (1);
    }
    else return tabM[ind1][ind2];
}

Macierz & operator + (const MacierzKw & B)
{
    Macierz M;
    for (int i=0; i<ROZMIAR; i++)
    {
        for (int j=0; j<ROZMIAR; j++)
        {
            M[i][j] = tabM[i][j] + B[i][j];
        }
    }
    return M;
}

Macierz & operator - (const MacierzKw & B)
{
    Macierz M;
    for (int i=0; i<ROZMIAR; i++)
    {
        for (int j=0; j<ROZMIAR; j++)
        {
            M[i][j] = tabM[i][j] - B[i][j];
        }
    }
    return M;
}

Macierz & operator * (const MacierzKw & B)
{
    Macierz M;
    Macierz B.tra
    for (int i=0; i<ROZMIAR; i++)
    {
        for (int j=0; j<ROZMIAR; j++)
    }
}

Macierz & operator * (double B)
{
    Macierz M;
    for (int i=0; i<ROZMIAR; i++)
    {
        for (int j=0; j<ROZMIAR; j++)
        {
            M[i][j] = tabM[i][j] * B;
        }
    }
    return M;
}

bool operator == (const MacierzKw & W2) const
{

}

bool operator != (const MacierzKw & W2) const
{

}

std::istream& operator >> (std::istream &Strm, Macierz &Mac)
{
    for (int i=0; i<ROZMIAR; i++)
    {
       std::cout << Mac[i] << " ";
    }
}

std::ostream& operator << (std::ostream &Strm, const Macierz &Mac)
{
    for (int i=0; i<ROZMIAR; i++)
    {
        Strm << Mac[i];
    }
    return Strm;
}
