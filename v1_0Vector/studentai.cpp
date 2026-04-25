#include "studentai.h"
#include <sstream>
#include <algorithm>

using std::istream;
using std::string;
using std::vector;

Studentas::Studentas(istream &is)
{
    readStudent(is);
}

double Studentas::galBalas(double (*f)(vector<double>)) const
{
    return 0.4 * f(nd_) + 0.6 * egzaminas_;
}

istream &Studentas::readStudent(istream &is)
{
    is >> vardas_ >> pavarde_;
    nd_.clear();
    double x;
    while (is.peek() != '\n' && is >> x)
        nd_.push_back(x);
    if (!nd_.empty())
        egzaminas_ = nd_.back(), nd_.pop_back();
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