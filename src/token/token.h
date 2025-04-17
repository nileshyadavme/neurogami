// ------------------------------------------
// 🧑‍💻 Author      : Nilesh Kumar Yadav
// 🕒 Created At  : 2025-04-17 00:57
// 📄 File        : token.h
// 📝 Description : all tokens
// ------------------------------------------

#pragma once
#ifndef TOKEN_H
#define TOKEN_H

#include <string>

enum TokenType
{
    ID,
    INT,
    EUQALS,
    RETURN,
    SEMICOLON,
    LEFTPAREN,
    RIGHTPAREN,

    ENDOFFILE
};

// token structure
struct Token
{
    enum TokenType type;
    std::string value;
};

#endif TOKEN_H
