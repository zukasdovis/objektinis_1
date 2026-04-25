#ifndef RUSIAVIMAS_H
#define RUSIAVIMAS_H

#include "studentai.h"
#include "failai.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

template <typename Container>
void splitContainer(Container &grupe, Container &silpniakai);

void failoRusiavimas1(int kiekis);
void failoRusiavimas2(int kiekis);
void failoRusiavimas3(int kiekis);

#endif