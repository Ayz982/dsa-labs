#include "Common.h"

int Vg1 = 0;
int Vg2 = 0;
double Vg3 = 0.0;
char Vg4 = ' ';
std::ofstream logFile;

void common_init() {
    Vg1 = 20;
    Vg2 = 15;
    Vg3 = 12.34;
    Vg4 = '1';

    logFile.open("log.txt", std::ios::out);
    if (logFile.is_open()) {
        logFile << "common_init: Global variables and log file initialized.\n";
    }
}