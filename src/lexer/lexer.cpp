/// ------------------------------------------
// 🧑‍💻 Author      : Nilesh Kumar Yadav
// 🕒 Created At  : 2025-04-13 00:45
// 📄 File        : lexer.cpp
// 📝 Description : lexer implementation
// ------------------------------------------

#include "lexer.h"

/*
  === Core Lexer Functions ===
*/
char nurogami::Lexer::peek()
{
  if (pointer < size)
  {
    return content[pointer];
  }
}

char nurogami::Lexer::peekNext()
{
  if (pointer < size)
  {
    return content[pointer + 1];
  }
}

char nurogami::Lexer::advance()
{
  if (pointer < size)
  {
    char temp = content[pointer];
    pointer++;
    current = (pointer < size) ? content[pointer] : '\0';
    return current;
  }
  else
  {
    return '\0';
  }
}

void nurogami::Lexer::skipWS()
{
  while (isspace(current))
  {
    advance();
  }
}

std::vector<Token *> nurogami::Lexer::Tokenize()
{
  std::vector<Token *> tokens;
  bool notEOF = true;
  while (pointer < size)
  {
    skipWS();
    if (isalpha(current) || current == '_')
    {
      tokens.push_back(tokenizeID_KEYWORD());
      continue;
    }
    else if (isdigit(current))
    {
      tokens.push_back(tokenizeINT());
      continue;
    }
    switch (current)
    {
    case ';':
      tokens.push_back(tokenizeSpecial(TokenType::SEMICOLON));
      break;

    case '=':
      tokens.push_back(tokenizeSpecial(TokenType::EUQALS));
      break;

    case '(':
      tokens.push_back(tokenizeSpecial(TokenType::LEFTPAREN));
      break;

    case ')':
      tokens.push_back(tokenizeSpecial(TokenType::RIGHTPAREN));
      break;
    default:
      std::stringstream err;
      err << "Unexpected character '" << current << "' at position " << pointer;
      throw LexerError(err.str());
    }
  }
  Token *eof = new Token();
  eof->type = TokenType::ENDOFFILE;
  eof->value = "EOF";
  tokens.push_back(eof);
  return tokens;
}

/*
  differnt tokenizers
*/

Token *nurogami::Lexer::tokenizeID_KEYWORD()
{
  std::stringstream buffer;
  buffer << current;
  advance();

  while (isalnum(current) || current == '_')
  {
    buffer << current;
    advance();
  }
  Token *newToken = new Token();
  newToken->type = ((nurogami::Lexer::KEYWORDS.find(buffer.str()) == nurogami::Lexer::KEYWORDS.end()) ? ID : KEYWORD);
  newToken->value = buffer.str();
  return newToken;
}

Token *nurogami::Lexer::tokenizeINT()
{
  std::stringstream buffer;
  buffer << current;
  advance();

  while (isdigit(current))
  {
    buffer << current;
    advance();
  }
  Token *newToken = new Token();
  newToken->type = INT;
  newToken->value = buffer.str();
  return newToken;
}

Token *nurogami::Lexer::tokenizeSpecial(enum TokenType type)
{
  Token *newToken = new Token();
  newToken->type = type;
  char ch = current;
  advance();
  newToken->value = std::string(1, ch);
  return newToken;
}

std::string nurogami::Lexer::typeToString(enum TokenType type)
{
  {
    switch (type)
    {
    case TokenType::ID:
      return "ID";
    case TokenType::INT:
      return "INT";
    case TokenType::EUQALS:
      return "EQUALS";
    case TokenType::LEFTPAREN:
      return "LEFTPAREN";
    case TokenType::RIGHTPAREN:
      return "RIGHTPAREN";
    case TokenType::SEMICOLON:
      return "SEMICOLON";
    case TokenType::ENDOFFILE:
      return "ENDOFFILE";
    case TokenType::RETURN:
      return "RETURN";
    case TokenType::KEYWORD:
      return "KEYWORD";
    default:
      return "UNKNOWN";
    }
  }
}
