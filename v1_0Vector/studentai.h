#ifndef STUDENTAI_H
#define STUDENTAI_H

#include <iostream>
#include <vector>
#include <string>
#include "mediana.h"

class Studentas
{
private:
    std::string vardas_;
    std::string pavarde_;
    double egzaminas_;
    std::vector<double> nd_;

public:
    Studentas() : egzaminas_(0) {}
    Studentas(std::istream &is);

    inline std::string vardas() const { return vardas_; }
    inline std::string pavarde() const { return pavarde_; }
    double galBalas(double (*f)(std::vector<double>) = mediana) const;

    std::istream &readStudent(std::istream &);
};

bool compare(const Studentas &, const Studentas &);
bool comparePagalPavarde(const Studentas &, const Studentas &);
bool comparePagalEgza(const Studentas &, const Studentas &);

#endif