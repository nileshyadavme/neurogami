// ------------------------------------------
// 🧑‍💻 Author      : Nilesh Kumar Yadav
// 🕒 Created At  : 2025-04-13
// 📄 File        : compiler.h
// 📝 Description : Declarations for the core compiler interface
// ------------------------------------------

#ifndef COMPILER_H
#define COMPILER_H

#include <string>

namespace Nurogami::core
{

    // 🌟 Prints the beautiful compiler banner on startup
    void printBanner();

    // 🖥️ Enables ANSI color codes on Windows terminals
    void enableColor();

    // 📁 Checks whether the given file exists
    bool fileExists(const std::string &filename);

    // 📜 Reads content from a .gami file
    std::string readGamiFile(const std::string &filename);

    // 🧠 Starts the interactive compiler loop (REPL style)
    void startCompiler();

} // namespace Nurogami

#endif // COMPILER_H
