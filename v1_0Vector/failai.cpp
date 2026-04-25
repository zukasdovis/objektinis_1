#include "failai.h"
#include <fstream>
#include <sstream>
#include <stdexcept>

using std::ifstream;
using std::runtime_error;
using std::string;
using std::stringstream;
using std::vector;

void failu_nusk(vector<Studentas> &grupe, string failas)
{
    ifstream fd(failas);
    if (!fd)
        throw runtime_error("Failas neegzistuoja arba negali buti atidarytas.");

    string line;
    getline(fd, line); // skip header

    while (getline(fd, line))
    {
        if (line.empty())
            continue;
        stringstream ss(line);
        Studentas A(ss);
        grupe.push_back(A);
    }
}