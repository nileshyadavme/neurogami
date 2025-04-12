/// ------------------------------------------
// 🧑‍💻 Author      : Nilesh Kumar Yadav
// 🕒 Created At  : 2025-04-13 00:45
// 📄 File        : lexer.cpp
// 📝 Description : lexer implementation
// ------------------------------------------


#include "lexer.h"

void Nurogami::Lexer::advance()
{
    if(pointer < size)
    {
        pointer++;
    }
}