// ------------------------------------------
// 🧑‍💻 Author      : Nilesh Kumar Yadav
// 🕒 Created At  : 2025-04-13 00:34
// 📄 File        : lexer.h
// 📝 Description : lexer header file with namespace
// ------------------------------------------

#ifndef LEXER_H
#define LEXER_H


#include <iostream>
#include <string>
#include <vector>
#include "../token/token.h"
#include "../error/error.h"
#include <sstream>
#include <cctype>
#include <unordered_set>

namespace nurogami
{

    class Lexer
    {
    public:
        // Tokenize()
        std::vector<Token *> Tokenize();

        // function to help me in debug
        static std::string typeToString(enum TokenType type);
        Lexer(std::string &sCode)
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
        char peek();     // done
        char peekNext(); // done
        char advance();  // will consume and move next --- done
        void skipWS();

        // === Lexing Helpers ===
        // bool isAlpha(char);
        // bool isAlphaNumeric(char);
        // bool isDigit(char);
        // bool string();     // string literals
        // bool number();     // numeric literals
        // bool identifier(); // identifiers and keywords

        // differnt tokenizers
        Token *tokenizeID_KEYWORD();
        Token *tokenizeINT();
        Token *tokenizeSpecial(enum TokenType type);

        // KEYWORD set
        std::unordered_set<std::string> KEYWORDS = {
            "return",
            "display"
        };

    };

} // namespace Nurogami

#endif
