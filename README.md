Custom Compiler – Mini Language
---
This project is an original object-oriented programming language built from scratch using C++, Flex, and Bison. It performs the full "Front-End" process of a compiler—reading, validating, and understanding code—and then uses an AST (Abstract Syntax Tree) to execute the logic as an interpreter

Key Features
- Custom Syntax: Includes unique keywords like verify (if), loop (while), and counted_steps (for).
- OOP Support: Allows defining classes, creating objects with new, and accessing methods/fields.
- Persistence: Automatically exports the final state of all memory scopes to tables.txt after execution.

Compile:

		flex limbaj.l
  		bison -d limbaj.y
   		g++ -o minilang limbaj.tab.c lex.yy.c SymTable.cpp AST.cpp -std=c++11

Execute:

                ./minilang test11.txt
