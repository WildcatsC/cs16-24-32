C++ Build Process

    1. Preprocessor: Text-based program that runs before the compilation step. Looks for statements such as #include and modifies the source which is the input for compilation.

    2. Compiler: A program that translates source code into “object code,” which is a lower-level representation optimized for executing instructions on the specific platform. Lower level representations are usually stored in a .o (object) file.

    3. Linker: Resolves dependencies and maps appropriate functions located in various object files. The output of the linker is an executable file for the specific platform.

default (c++ at front): make xx = g++ xx.cpp -o xx
