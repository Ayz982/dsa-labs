#include "Common.h"
#include "MErr.h"
#include "M1.h"
#include "M2.h"
#include "M3.h"
#include <iostream>

void S1() {
	if(logFile.is_open())
		logFile << "[INFO] S1 started.\n";
	S5();
	S6();
	Err();
	if (logFile.is_open())
		logFile << "[INFO] S1 finished.\n";
}

void S2(int n) {
	if (logFile.is_open())
		logFile << "[INFO] S2 started.\n";
	S6();
	if (Vg1 != Vg2){
		S7(Vg1);
	}
	Err();
	if (logFile.is_open())
		logFile << "[INFO] S2 finished.\n";
}

void S3() {
	if (logFile.is_open())
		logFile << "[INFO] S3 started.\n";
	Vg4 = '3';
	if (logFile.is_open())
		logFile << "Vg4 = " << Vg4 << "\n";
	S8();
	S9();
	S10();
	Err();
	if (logFile.is_open())
		logFile << "[INFO] S3 finished.\n";
}

void S4() {
	if (logFile.is_open())
		logFile << "[INFO] S4 started.\n";
	Vg4 = '4';
	if (logFile.is_open())
		logFile << "Vg4 = " << Vg4 << "\n";
	S9();
	S10();
	Err();
	if (logFile.is_open())
		logFile << "[INFO] S4 finished.\n";
}