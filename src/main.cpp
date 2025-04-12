#include <iostream>
#include <string>
#include <cstdlib>  // system()
#include <fstream>
#include <unistd.h>
#include <limits.h>

// Function to get current directory
void printCurrentDirectory() {
    char buf[PATH_MAX];
    if (getcwd(buf, sizeof(buf)) != NULL) {
        std::cout << "Current directory: " << buf << std::endl;
    } else {
        perror("getcwd() error");
    }
}

// Function to check if a file exists
bool fileExists(const std::string& filename) {
    std::ifstream file(filename);
    return file.good();
}

// Function to print the banner
void printBanner()
{
    const std::string BLUE = "\033[1;34m";
    const std::string NC = "\033[0m"; // Reset
    const std::string PROJECT_NAME = "Nurogami";

    std::cout << BLUE << "🚀 Running " << PROJECT_NAME << "..." << NC << std::endl;
    std::cout << R"(
          ,    ,
         /(    )\           A W A K E N I N G
        (  \/\/  )          T H E    F L A M E
        (        )          N U R O G A M I
         \      /           
          `.__.'

    )" << "\n";
}

// Function to check if a string starts with a given prefix
bool startsWith(const std::string& str, const std::string& prefix) {
    return str.find(prefix) == 0;
}

// Function to read the content of a .gami file and print it
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

int main(int argc, char *argv[])
{
    printCurrentDirectory();  // Print current directory for debugging
    std::cout << "\033[1;31m"; // Bright Red
    printBanner();
    std::cout << "\033[0m"; // Reset

    std::string input;

    while (true) {
        std::cout << "\033[1;32mNurogami » \033[0m";
        std::getline(std::cin, input);

        if (input.empty()) {
            continue;
        }
        else if (input == "clear")
        {
            std::string command = "clear";  // Compile and run
            int result = system(command.c_str());
        }
        else if (input == "exit") {
            std::cout << "Goodbye, compiler wizard. 🧙‍♂️\n";
            break;
        } else if (!input.empty()) {
            // Check if the file exists and has a .gami extension
            if (fileExists(input) && input.substr(input.find_last_of(".") + 1) == "gami") {
                std::cout << "Reading .gami file: " << input << std::endl;
                readGamiFile(input);  // Read and print the content of the .gami file
            } else {
                std::cout << "\033[1;31mError: File '" << input << "' not found or not a .gami file.\033[0m\n";
            }
        }
    }
    return 0;
}
