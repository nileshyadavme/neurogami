#ifndef COMPILER_H
#define COMPILER_H

#include <string>
// print the banner on startup
void printBanner();

// enable color output on Windows
void enableColor();

// check if a file exists
bool fileExists(const std::string &filename);

// read a .gami file and return its content
std::string readGamiFile(const std::string &filename);

// Main function to handle the compiler's core loop
void startCompiler();

#endif
