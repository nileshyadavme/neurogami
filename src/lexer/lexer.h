// ------------------------------------------
// 🧑‍💻 Author      : Nilesh Kumar Yadav
// 🕒 Created At  : 2025-04-13 00:34
// 📄 File        : lexer.h
// 📝 Description : lexer header file with namespace
// ------------------------------------------

#ifndef LEXER_H
#define LEXER_H

#include <string>
#include <iostream>

namespace Nurogami {

class Lexer 
{
public:
    Lexer(std::string& sCode)
    {
        this->content = sCode;
        this->pointer = 0;
        this->size = sCode.length();
        this->current = content.at(0);
        // std::cout << "Lexer initialized\n";
    }

private:
    // === Data Members ===
    std::string content;
    char current;
    int size;
    int pointer;

    // === Core Lexer Functions ===
    char peek();
    char peekNext();
    void advance();
    void skipWS();

    // === Lexing Helpers ===
    bool isAlpha(char);
    bool isAlphaNumeric(char);
    bool isDigit(char);
    bool string();       // string literals
    bool number();       // numeric literals
    bool identifier();   // identifiers and keywords
};

} // namespace Nurogami

#endif // LEXER_H
