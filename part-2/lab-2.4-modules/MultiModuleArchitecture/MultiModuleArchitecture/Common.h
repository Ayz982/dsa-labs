#ifndef COMMON_H
#define COMMON_H

#include <fstream>

struct Tg1 {
    int id;
    double value;
};

struct Tg2 {
    int id;
    double value;
};

const int Cg1 = 9;
const double Cg2 = 3.14;
const short Cg3 = 12;
const long Cg4 = 123456;
const char Cg5 = 'a';

extern int Vg1, Vg2;
extern double Vg3;
extern char Vg4;
extern std::ofstream logFile;

void common_init();

#endif