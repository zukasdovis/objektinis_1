#ifndef STUDENTAS_H
#define STUDENTAS_H

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
    std::vector<int> nd_;
    double galutinis_med_;
    double galutinis_vid_;

public:
    Studentas() : egzaminas_(0), galutinis_med_(0), galutinis_vid_(0) {}
    Studentas(std::istream &is);        // ranka, pazymiu_gen, visk_gen
    Studentas(std::istream &is, int n); // failo skaitymas

    // destruktorius
    ~Studentas() {}

    // getteriai
    inline std::string vardas() const { return vardas_; }
    inline std::string pavarde() const { return pavarde_; }
    inline double galutinis_med() const { return galutinis_med_; }
    inline double galutinis_vid() const { return galutinis_vid_; }
    double galBalas(double (*f)(std::vector<int>) = mediana) const;

    std::istream &readStudent(std::istream &is);
    std::istream &readStudent(std::istream &is, int n);
};

bool compare(const Studentas &, const Studentas &);
bool comparePagalPavarde(const Studentas &, const Studentas &);
bool comparePagalEgza(const Studentas &, const Studentas &);

#endif