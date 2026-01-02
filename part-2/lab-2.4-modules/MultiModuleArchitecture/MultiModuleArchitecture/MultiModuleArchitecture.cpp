#include <iostream>
#include "Common.h"
#include "M1.h"

int main()
{
    common_init();
    if (logFile.is_open()) {
        logFile << "--- [MAIN STARTED] ---\n";
    }
    else {
        std::cerr << "Error: log file could not be opened!" << std::endl;
    }

    S1();
    S2(Vg2);
    S3();
    S4();

    if (logFile.is_open()) {
        logFile << "--- [MAIN FINISHED] ---\n";
        logFile.close();
    }

    return 0;
}
