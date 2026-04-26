#ifndef ZMOGUS_H
#define ZMOGUS_H

#include <string>
#include <iostream>

class Zmogus
{
protected:
    std::string vardas_;
    std::string pavarde_;

public:
    // default konstruktorius
    Zmogus() : vardas_(""), pavarde_("") {}

    // konstruktorius su parametrais
    Zmogus(const std::string &vardas, const std::string &pavarde)
        : vardas_(vardas), pavarde_(pavarde) {}

    // copy konstruktorius
    Zmogus(const Zmogus &kitas)
        : vardas_(kitas.vardas_), pavarde_(kitas.pavarde_) {}

    // move konstruktorius
    Zmogus(Zmogus &&kitas) noexcept
        : vardas_(std::move(kitas.vardas_)),
          pavarde_(std::move(kitas.pavarde_)) {}

    // copy assignment
    Zmogus &operator=(const Zmogus &kitas)
    {
        if (this == &kitas)
            return *this;
        vardas_ = kitas.vardas_;
        pavarde_ = kitas.pavarde_;
        return *this;
    }

    // move assignment
    Zmogus &operator=(Zmogus &&kitas) noexcept
    {
        if (this == &kitas)
            return *this;
        vardas_ = std::move(kitas.vardas_);
        pavarde_ = std::move(kitas.pavarde_);
        return *this;
    }

    // virtualus destruktorius
    virtual ~Zmogus() {}

    // getteriai
    inline std::string vardas() const { return vardas_; }
    inline std::string pavarde() const { return pavarde_; }

    // grynosios virtualios funkcijos
    virtual std::istream &readStudent(std::istream &) = 0;
    virtual void print(std::ostream &) const = 0;
};

#endif