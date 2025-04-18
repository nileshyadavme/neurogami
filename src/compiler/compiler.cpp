// ------------------------------------------
// 🧑‍💻 Author      : Nilesh Kumar Yadav
// 🕒 Created At  : 2025-04-13 00:25
// 📄 File        : compiler.cpp
// 📝 Description : compiler.h implementation
// ------------------------------------------

#include "compiler.h"
#include "../lexer/lexer.h"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>

// Check if thee file exists
bool Nurogami::core::fileExists(const std::string &filename)
{
  std::ifstream file(filename);
  return file.good(); // File exists if it opens successfully
}

// print banner
void Nurogami::core::printBanner()
{
  const std::string BLUE = "\033[1;34m";
  const std::string NC = "\033[0m";
  const std::string PROJECT_NAME = "Nurogami";
  std::cout << BLUE << "🚀 Running " << PROJECT_NAME << "..." << NC
            << std::endl;
  std::cout << R"(
          ,    ,
         /(    )\           A W A K E N I N G
        (  \/\/  )          T H E    F L A M E
        (        )          N U R O G A M I
         \      /           
          `.__.'
    )" << "\n";
}

// Read a .gami file and print its content to the console - (for debug only)
std::string Nurogami::core::readGamiFile(const std::string &filename)
{
  std::ifstream file(filename);
  std::string sourceCode;
  if (file)
  {
    std::stringstream buffer;
    buffer << file.rdbuf();
    sourceCode = buffer.str();

    // DEBUG
    std::cout << sourceCode << std::endl;
  }
  else
  {
    std::cout << "\033[1;31mError: Unable to open file '" << filename
              << "'.\033[0m\n";
  }
  return sourceCode;
}

// Main loop for the compiler's functionality
void Nurogami::core::startCompiler()
{
  std::string input;

  while (true)
  {
    std::cout << "\033[0;32mNurogami » \033[0m";
    std::getline(std::cin, input);

    if (input.empty())
      continue;

    else if (input == "help")
    {
      std::cout << "Welcome to Nurogami Compiler!\n";
      std::cout << "\n";
      std::cout << "Here are some commands you can use:\n";
      std::cout << "\n";
      std::cout << ":exit - Exit the compiler.\n";
      std::cout << "\n";
      std::cout << ":run <filename> - Run a previously compiled program.\n";
      std::cout << "\n";
      std::cout << "<filename>.gami - Read and display the contents of a .gami file.\n";
      std::cout << "\n";
      std::cout << "Type the name of a file (with .gami extension) to read its content.\n";
    }

    else if (input == "clear")
    {
      system("clear");
    }
    else if (input == "exit")
    {
      std::cout << "Goodbye, compiler wizard. 🧙‍♂️\n";
      return;
    }
    else if (!input.empty())
    {

      if (fileExists(input) &&
          input.substr(input.find_last_of(".") + 1) == "gami")
      {
        std::cout << "Reading .gami file: " << input << std::endl;
        std::string sourceCode = readGamiFile(input); // debugging

        try
        {
          nurogami::Lexer lexer(sourceCode);
          std::vector<Token *> tokens = lexer.Tokenize();

          for (Token *token : tokens)
          {
            std::cout << "TokenType->" << nurogami::Lexer::typeToString(token->type)
                      << " TokenValue->" << token->value << "\n";
          }
        }
        catch (const nurogami::LexerError &e)
        {
          std::cerr << "\033[1;31m" << e.what() << "\033[0m" << std::endl;
        }
        continue;
      }
      else
      {
        std::cout << "\033[1;31mError: File '" << input
                  << "' not found or not a .gami file.\033[0m\n";
      }
    }
  }
}
