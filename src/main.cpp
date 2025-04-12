// ------------------------------------------
// 🧑‍💻 Author      : Nilesh Kumar Yadav
// 🕒 Created At  : 2025-04-12 23:45
// 📄 File        : main.cpp
// 📝 Description : entry point for compiler
// ------------------------------------------


#include "compiler/compiler.h"

int main(int argc, char *argv[]) {
    // Enable color support on Windows
#ifdef _WIN32
    enableColor();
#endif

    // Print the banner and start the compiler
    printBanner();
    startCompiler();

    return 0;
}
