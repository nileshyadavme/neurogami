#ifndef COMPILER_H
#define COMPILER_H

#include <string>

// Function to print the banner on startup
void printBanner();

// Function to enable color output on Windows
void enableColor();

// Function to check if a file exists
bool fileExists(const std::string& filename);

// Function to read a .gami file and print its content
void readGamiFile(const std::string& filename);

// Main function to handle the compiler's core loop
void startCompiler();

#endif
