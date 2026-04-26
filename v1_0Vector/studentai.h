#ifndef STUDENTAS_H
#define STUDENTAS_H

#include "Zmogus.h"
#include "mediana.h"
#include <vector>

class Studentas : public Zmogus
{
private:
    double egzaminas_;
    std::vector<int> nd_;
    double galutinis_med_;
    double galutinis_vid_;

public:
    // --- Rule of Five ---

    // 1. default konstruktorius
    Studentas() : Zmogus(), egzaminas_(0), galutinis_med_(0), galutinis_vid_(0) {}

    // 2. copy konstruktorius
    Studentas(const Studentas &kitas);

    // 3. move konstruktorius
    Studentas(Studentas &&kitas) noexcept;

    // 4. copy assignment
    Studentas &operator=(const Studentas &kitas);

    // 5. move assignment
    Studentas &operator=(Studentas &&kitas) noexcept;

    // 6. destruktorius
    ~Studentas() override {}

    // --- papildomi konstruktoriai ---
    Studentas(std::istream &is);
    Studentas(std::istream &is, int n);

    // --- getteriai ---
    inline double galutinis_med() const { return galutinis_med_; }
    inline double galutinis_vid() const { return galutinis_vid_; }
    double galBalas(double (*f)(std::vector<int>) = mediana) const;

    // --- virtualios funkcijos iš Zmogus ---
    std::istream &readStudent(std::istream &is) override;
    std::istream &readStudent(std::istream &is, int n);
    void print(std::ostream &os) const override;

    // --- i/o operatoriai ---
    friend std::istream &operator>>(std::istream &is, Studentas &s);
    friend std::ostream &operator<<(std::ostream &os, const Studentas &s);
};

bool compare(const Studentas &, const Studentas &);
bool comparePagalPavarde(const Studentas &, const Studentas &);
bool comparePagalEgza(const Studentas &, const Studentas &);

#endif