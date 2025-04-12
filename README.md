# C++ Compiler Project

A custom C++ compiler built with modern C++26 standards. This project aims to implement a full-featured compiler with a focus on performance and correctness, leveraging the latest C++ language features.

## Project Description

This compiler project is designed to translate C++ source code into executable machine code, following the standard compilation pipeline. It is being developed with C++26 standard features and uses CMake 3.28.3 as its build system. The goal is to create a modular, extensible compiler that can be used as a foundation for language experimentation and optimization research.

## Project Status

### Compiler Stages
- [x] Lexical Analysis (Tokenization)
- [ ] Syntax Analysis (Parsing)
- [ ] Semantic Analysis
- [ ] Intermediate Code Generation
- [ ] Code Optimization
- [ ] Code Generation
- [ ] Symbol Table Management
- [ ] Error Handling

### Current Features
- Basic tokenization of C++ syntax
- Simple parsing of expressions
- Symbol table for variable tracking
- Error reporting with line and column information

## Getting Started

### Prerequisites
- CMake (version 3.28.3)
- C++26 compatible compiler
- Git

### Building the Project
```bash
git clone https://github.com/yourusername/compiler-project.git
cd compiler-project
mkdir build && cd build
cmake ..
make
```

### Running the Compiler
```bash
./compiler path/to/source/file.cpp
```

## Project Structure
```
├── CMakeLists.txt
├── src/
│   ├── lexer/
│   ├── parser/
│   ├── semantic/
│   ├── codegen/
│   ├── optimizer/
│   └── main.cpp
├── include/
│   ├── lexer/
│   ├── parser/
│   ├── semantic/
│   ├── codegen/
│   └── optimizer/
└── tests/
```

## Roadmap
- Implement complete lexical analyzer
- Develop recursive descent parser
- Build abstract syntax tree (AST)
- Implement type checking
- Generate intermediate representation
- Add basic optimizations
- Implement code generation for x86_64

## Contributing
Contributions are welcome! Please feel free to submit a Pull Request.

## License
This project is licensed under the MIT License - see the LICENSE file for details.