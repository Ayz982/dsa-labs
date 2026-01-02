#include "Common.h"
#include "MErr.h"

void Err() {
	if (logFile.is_open())
		logFile << "[INFO] Err started and finished.\n";
}