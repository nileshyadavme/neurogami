#include "compiler.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

#ifdef _WIN32
#include <windows.h>
#endif

// Check if thee file exists
bool fileExists(const std::string& filename) {
    std::ifstream file(filename);
    return file.good();  // File exists if it opens successfully
}

// Enable color support on Windows -- deal with this later ----
#ifdef _WIN32
void enableColor() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleMode(hConsole, ENABLE_VIRTUAL_TERMINAL_PROCESSING);
}
#endif

// print banner
void printBanner() {
    const std::string BLUE = "\033[1;34m";
    const std::string NC = "\033[0m";
    const std::string PROJECT_NAME = "Nurogami";

#ifdef _WIN32
    std::cout << "🚀 Running " << PROJECT_NAME << "..." << std::endl;
#else
    std::cout << BLUE << "🚀 Running " << PROJECT_NAME << "..." << NC << std::endl;
    std::cout << R"(
          ,    ,
         /(    )\           A W A K E N I N G
        (  \/\/  )          T H E    F L A M E
        (        )          N U R O G A M I
         \      /           
          `.__.'
    )" << "\n";
#endif
}

// Read a .gami file and print its content to the console - (for debug only) 
void readGamiFile(const std::string& filename) {
    std::ifstream file(filename);
    if (file) {
        std::string line;
        while (std::getline(file, line)) {
            std::cout << line << std::endl;
        }
    } else {
        std::cout << "\033[1;31mError: Unable to open file '" << filename << "'.\033[0m\n";
    }
}

// Main loop for the compiler's functionality
void startCompiler() {
    std::string input;

    while (true) {
        std::cout << "Nurogami » ";
        std::getline(std::cin, input);

        if (input.empty()) continue;
        
        else if (input == "help") {
            std::cout << "Welcome to Nurogami Compiler!\n";
            std::cout << "Here are some commands you can use:\n";
            std::cout << ":exit - Exit the compiler.\n";
            std::cout << ":run <filename> - Run a previously compiled program.\n";
            std::cout << "<filename>.gami - Read and display the contents of a .gami file.\n";
            std::cout << "Type the name of a file (with .gami extension) to read its content.\n";
        }
        
        
        else if (input == "exit") {
            std::cout << "Goodbye, compiler wizard. 🧙‍♂️\n";
            break;
        } else if (!input.empty()) {
            
            if (fileExists(input) && input.substr(input.find_last_of(".") + 1) == "gami") {
                std::cout << "Reading .gami file: " << input << std::endl;
                readGamiFile(input);
            } else {
                std::cout << "\033[1;31mError: File '" << input << "' not found or not a .gami file.\033[0m\n";
            }
        }
    }
}
