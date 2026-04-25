#include "studentai.h"
#include <sstream>
#include <algorithm>

using std::istream;
using std::string;
using std::vector;

double Studentas::galBalas(double (*f)(std::vector<int>)) const
{
    if (f == mediana)
        return galutinis_med_;
    return galutinis_vid_;
}

Studentas::Studentas(std::istream &is)
{
    readStudent(is);
}

std::istream &Studentas::readStudent(std::istream &is)
{
    is >> vardas_ >> pavarde_;
    nd_.clear();
    int x;
    while (is.peek() != '\n' && is >> x)
        nd_.push_back(x);
    if (!nd_.empty())
    {
        egzaminas_ = nd_.back();
        nd_.pop_back();
    }
    galutinis_med_ = 0.4 * mediana(nd_) + 0.6 * egzaminas_;
    galutinis_vid_ = 0.4 * vidurkis(nd_) + 0.6 * egzaminas_;
    return is;
}

// failo skaitymas su n
Studentas::Studentas(std::istream &is, int n)
{
    readStudent(is, n);
}

std::istream &Studentas::readStudent(std::istream &is, int n)
{
    is >> vardas_ >> pavarde_;
    nd_.clear();
    nd_.reserve(n);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        is >> x;
        nd_.push_back(x);
        sum += x;
    }
    is >> egzaminas_;
    galutinis_med_ = 0.4 * mediana(nd_) + 0.6 * egzaminas_;
    galutinis_vid_ = (n != 0) ? 0.4 * ((double)sum / n) + 0.6 * egzaminas_ : 0.6 * egzaminas_;
    return is;
}

bool compare(const Studentas &A, const Studentas &B)
{
    return A.vardas() < B.vardas();
}

bool comparePagalPavarde(const Studentas &A, const Studentas &B)
{
    return A.pavarde() < B.pavarde();
}

bool comparePagalEgza(const Studentas &A, const Studentas &B)
{
    return A.galBalas() < B.galBalas();
}