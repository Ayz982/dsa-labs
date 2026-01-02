#include "Common.h"
#include "MErr.h"
#include "M3.h"
#include <iostream>

void S8() {
	if (logFile.is_open())
		logFile << "[INFO] S8 started.\n";
	Vg3 = 8.0;
	if (logFile.is_open())
		logFile << "Vg3 = " << Vg3 << "\n";
	Err();
	if (logFile.is_open())
		logFile << "[INFO] S8 finished.\n";
}

void S9() {
	if (logFile.is_open())
		logFile << "[INFO] S9 started.\n";
	Vg3 = 9.0;
	if (logFile.is_open())
		logFile << "Vg3 = " << Vg3 << "\n";
	Err();
	if (logFile.is_open())
		logFile << "[INFO] S9 finished.\n";
}

void S10() {
	if (logFile.is_open())
		logFile << "[INFO] S10 started.\n";
	Vg3 = 10.0;
	if (logFile.is_open())
		logFile << "Vg3 = " << Vg3 << "\n";
	Err();
	if (logFile.is_open())
		logFile << "[INFO] S10 finished.\n";
}