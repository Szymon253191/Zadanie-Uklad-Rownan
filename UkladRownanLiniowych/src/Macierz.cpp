#include "Macierz.hh"

Macierz::Macierz(Wektor A, Wektor B, Wektor C)
{
    tabM[0] = A;
    tabM[1] = B;
    tabM[2] = C;
}

Macierz::Macierz()
{
    Wektor W; // (0,0,0)
    for(int i=0; i<ROZMIAR; i++)
    {
        tabM[i]=W;
    }
}

Wektor & Macierz::operator *(const Wektor & B) const
 {
    Wektor W;
    for (int i=0; i<ROZMIAR; i++)
    {
        for (int j=0; j<ROZMIAR; j++)
        {
            W[i] += tabM[i][j] * B[j];
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

Macierz Macierz::transponuj() const
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

Wektor & Macierz::operator [](int index)
{
    if(index < 0 || index > 3)
    {
        std::cerr<<"Poza zakresem"<<endl;
        exit (1);
    }
    else return tabM[index];
}

/*double & Macierz::operator () (int ind1, int ind2) //w sumie nie uzywana
{
    if(ind1 < 0 || ind1 > ROZMIAR || ind2 < 0 || ind2 > ROZMIAR)
    {
        std::cerr<<"Poza zakresem"<<endl;
        exit (1);
    }
    else return tabM[ind1][ind2];
}
*/
Macierz & Macierz::operator + (const Macierz & B) const
{
    Macierz M;
    for (int i=0; i<ROZMIAR; i++)
    {
        M[i] = tabM[i] + B[i];
    }
    return M;
}

Macierz & Macierz::operator - (const Macierz & B) const
{
    Macierz M;
    for (int i=0; i<ROZMIAR; i++)
    {
        M[i] = tabM[i] - B[i];
    }
    return M;
}

Macierz & Macierz::operator * (const Macierz & B) const
{
    Macierz M;
    Macierz B = M.transponuj();
    for (int i=0; i<ROZMIAR; i++)
    {
        for (int j=0; j<ROZMIAR; j++)
        {
            M[i][j] = tab[i] * B[j];
        }
    }
    return M;
}

Macierz & Macierz::operator * (double B) const
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

bool Macierz::operator == (const Macierz & W2) const
{
    double epsilon = 0.000001;
    for (int i=0; i<ROZMIAR; i++)
    {
        if (abs(tabM[i]-W2[i] < epsilon))
        {
            return true;
        }
        else return false;
}

bool Macierz::operator != (const Macierz & W2) const
{
    double epsilon = 0.000001;
    for (int i=0; i<ROZMIAR; i++)
    {
        if (abs(tabM[i]-W2[i] > epsilon))
        {
            return true;
        }
        else return false;
}

std::istream& operator >> (std::istream &strm, Macierz &Mac)
{
    for (int i=0; i<ROZMIAR; i++)
    {
       std::cin >> Mac[i];
    }
    return strm;
}

std::ostream& operator << (std::ostream &strm, const Macierz &Mac)
{
    for (int i=0; i<ROZMIAR; i++)
    {
        strm << Mac[i] <<" ";
    }
    return strm;
}
