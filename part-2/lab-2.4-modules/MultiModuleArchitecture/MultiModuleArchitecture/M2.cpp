#include "Common.h"
#include "MErr.h"
#include "M2.h"
#include "M1.h"
#include <iostream>

void S5() {
	if (logFile.is_open())
		logFile << "[INFO] S5 started.\n";
	Vg2 = 10;
	if (logFile.is_open())
		logFile << "Vg2 = " << Vg2 << "\n";
	Err();
	if (logFile.is_open())
		logFile << "[INFO] S5 finished.\n";
}

void S6() {
	if (logFile.is_open())
		logFile << "[INFO] S6 started.\n";
	if (Vg1 < Vg2)
		Vg1++;
	else
		Vg1--;
	if (logFile.is_open())
		logFile << "Vg1 = " << Vg1 << "\n";
	Err();
	if (logFile.is_open())
		logFile << "[INFO] S6 finished.\n";
}

void S7(int n) {
	if (logFile.is_open())
		logFile << "[INFO] S7 started.\n";
	if (Vg1 < Vg2) {
		Vg2--;
		if (logFile.is_open())
			logFile << "Vg2 = " << Vg2 << "\n";
		S2(Vg2);
	}
	else {
		Vg2++;
		if (logFile.is_open())
			logFile << "Vg2 = " << Vg2 << "\n";
		S2(Vg2);
	}
	Err();
	if (logFile.is_open())
		logFile << "[INFO] S7 finished.\n";
}
