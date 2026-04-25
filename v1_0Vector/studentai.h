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
    // --- Rule of Five ---

    // 1. Default konstruktorius
    Studentas() : egzaminas_(0), galutinis_med_(0), galutinis_vid_(0) {}

    // 2. Copy konstruktorius
    Studentas(const Studentas &kitas);

    // 3. Move konstruktorius
    Studentas(Studentas &&kitas) noexcept;

    // 4. Copy assignment operatorius
    Studentas &operator=(const Studentas &kitas);

    // 5. Move assignment operatorius
    Studentas &operator=(Studentas &&kitas) noexcept;

    // 6. Destruktorius
    ~Studentas();

    // --- Papildomi konstruktoriai ---
    Studentas(std::istream &is);
    Studentas(std::istream &is, int n);

    // --- Getteriai ---
    inline std::string vardas() const { return vardas_; }
    inline std::string pavarde() const { return pavarde_; }
    inline double galutinis_med() const { return galutinis_med_; }
    inline double galutinis_vid() const { return galutinis_vid_; }
    double galBalas(double (*f)(std::vector<int>) = mediana) const;

    // --- Setteriai ---
    std::istream &readStudent(std::istream &is);
    std::istream &readStudent(std::istream &is, int n);

    // --- Įvesties/išvesties operatoriai ---
    friend std::istream &operator>>(std::istream &is, Studentas &s);
    friend std::ostream &operator<<(std::ostream &os, const Studentas &s);
};

bool compare(const Studentas &, const Studentas &);
bool comparePagalPavarde(const Studentas &, const Studentas &);
bool comparePagalEgza(const Studentas &, const Studentas &);

#endif