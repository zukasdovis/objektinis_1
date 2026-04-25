#include "studentai.h"
#include <iomanip>
#include <sstream>

using std::istream;
using std::ostream;
using std::string;
using std::vector;

// --- Rule of Five realizacija ---

// 2. Copy konstruktorius
Studentas::Studentas(const Studentas &kitas)
    : vardas_(kitas.vardas_),
      pavarde_(kitas.pavarde_),
      egzaminas_(kitas.egzaminas_),
      nd_(kitas.nd_),
      galutinis_med_(kitas.galutinis_med_),
      galutinis_vid_(kitas.galutinis_vid_) {}

// 3. Move konstruktorius
Studentas::Studentas(Studentas &&kitas) noexcept
    : vardas_(std::move(kitas.vardas_)),
      pavarde_(std::move(kitas.pavarde_)),
      egzaminas_(kitas.egzaminas_),
      nd_(std::move(kitas.nd_)),
      galutinis_med_(kitas.galutinis_med_),
      galutinis_vid_(kitas.galutinis_vid_)
{
    kitas.egzaminas_ = 0;
    kitas.galutinis_med_ = 0;
    kitas.galutinis_vid_ = 0;
}

// 4. Copy assignment
Studentas &Studentas::operator=(const Studentas &kitas)
{
    if (this == &kitas)
        return *this; // apsauga nuo self-assignment
    vardas_ = kitas.vardas_;
    pavarde_ = kitas.pavarde_;
    egzaminas_ = kitas.egzaminas_;
    nd_ = kitas.nd_;
    galutinis_med_ = kitas.galutinis_med_;
    galutinis_vid_ = kitas.galutinis_vid_;
    return *this;
}

// 5. Move assignment
Studentas &Studentas::operator=(Studentas &&kitas) noexcept
{
    if (this == &kitas)
        return *this;
    vardas_ = std::move(kitas.vardas_);
    pavarde_ = std::move(kitas.pavarde_);
    egzaminas_ = kitas.egzaminas_;
    nd_ = std::move(kitas.nd_);
    galutinis_med_ = kitas.galutinis_med_;
    galutinis_vid_ = kitas.galutinis_vid_;
    kitas.egzaminas_ = 0;
    kitas.galutinis_med_ = 0;
    kitas.galutinis_vid_ = 0;
    return *this;
}

// 6. Destruktorius
Studentas::~Studentas() {}

// --- Papildomi konstruktoriai ---

Studentas::Studentas(istream &is)
{
    readStudent(is);
}

Studentas::Studentas(istream &is, int n)
{
    readStudent(is, n);
}

// --- galBalas ---

double Studentas::galBalas(double (*f)(std::vector<int>)) const
{
    if (f == mediana)
        return galutinis_med_;
    return galutinis_vid_;
}

// --- readStudent be n (ranka) ---

istream &Studentas::readStudent(istream &is)
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

// --- readStudent su n (failas) ---

istream &Studentas::readStudent(istream &is, int n)
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
    galutinis_vid_ = (n != 0) ? 0.4 * ((double)sum / n) + 0.6 * egzaminas_
                              : 0.6 * egzaminas_;
    return is;
}

// --- >> operatorius ---

istream &operator>>(istream &is, Studentas &s)
{
    return s.readStudent(is);
}

// --- << operatorius ---

ostream &operator<<(ostream &os, const Studentas &s)
{
    os << std::fixed << std::setprecision(2);
    os << std::left << std::setw(16) << s.vardas_
       << std::setw(16) << s.pavarde_
       << std::setw(16) << s.galutinis_med_
       << std::setw(16) << s.galutinis_vid_;
    return os;
}

// --- Compare funkcijos ---

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