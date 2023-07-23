#include "Windows.h"
#include <iostream>
#include <cstdlib>
#include <cctype>
#include <chrono>

bool isInt(char *str)
{
    while (*str) {
        if (!isdigit(*str++)) {
            return false;
        }
    }
    return true;
}

int main(int argc, char** argv)
{
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <iteration_count>" << std::endl;
        return 1;
    }

    if (!isInt(argv[1])) {
        std::cerr << "<iteration_count> must be number" << std::endl;
        return 1;
    }

    int iterationCount = std::atoi(argv[1]);

    auto startTime = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < iterationCount; i++) {
        mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
        mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);

        std::cout << "\rClicks: " << (i + 1) << "/" << iterationCount << std::flush;

        Sleep(1);
    }

    std::cout << std::endl;

    auto endTime = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> duration = endTime - startTime;
    double elapsedTime = duration.count();
    double cps = static_cast<double>(iterationCount) / elapsedTime;

    std::cout << "Elapsed time: " << elapsedTime << " seconds" << std::endl;
    std::cout << "Clicks per second: " << cps << std::endl;

    return 0;
}
