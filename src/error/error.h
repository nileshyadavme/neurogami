// ------------------------------------------
// 🧑‍💻 Author      : Nilesh Kumar Yadav
// 🕒 Created At  : 2025-04-18 03:36
// 📄 File        : error.h
// 📝 Description : error handling 
// ------------------------------------------

#ifndef ERROR_H
#define ERROR_H

#include <stdexcept>
#include <string>

namespace nurogami {

class LexerError : public std::runtime_error {
public:
    LexerError(const std::string& message) : std::runtime_error("Lexer Error: " + message) {}
};

}

#endif ERROR_H
