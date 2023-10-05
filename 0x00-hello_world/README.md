Task Descriptions

Task 0: Preprocessor
- Save the C file name in the variable `$CFILE`.
- Run the C file through the preprocessor.
- Save the result in a file named 'c'.

Task 1: Compiler
- Save the C file name in the variable `$CFILE`.
- Compile the C file without linking.
- The output file should have the same name as the C file but with the extension `.o`.

Task 2: Assembler
- Save the C file name in the variable `$CFILE`.
- Generate the assembly code from the C file.
- Save the assembly code in a file with the same name as the C file but with the extension `.s`.

Task 3: Name
- Save the C file name in the variable `$CFILE`.
- Compile the C file to create an executable named 'cisfun'.

Task 4: Hello, puts
- Write a C program that prints "Programming is like building a multilingual puzzle," using the `puts` function.
- The program should end with the value 0.

Task 5: Hello, printf
- Write a C program that prints "with proper grammar, but the outcome is a piece of art," using the `printf` function.
- The program should return 0.
- The program should compile without warnings when using the `-Wall` gcc option.

Task 6: Size is not grandeur...
- Write a C program that prints the size of various types on the computer it is compiled and run on.
- Produce the exact same output as in the example.
- Warnings are allowed.
- The program should return 0.
- You might have to install the package `libc6-dev-i386` on your Linux to test the `-m32` gcc option.

Task 7: Intel
- Save the C file name in the variable `$CFILE`.
- Generate the assembly code (Intel syntax) from the C file.
- Save the assembly code in a file with the same name as the C file but with the extension `.s`.

Task 8: UNIX is basically a simple operating system...
- Write a C program that prints "and that piece of art is useful" - Dora Korpar, 2015-10-19, to the standard error (stderr).
- You are not allowed to use any functions listed in the `NAME` section of the `man (3)` `printf` or `man (3)` `puts`.
- The program should return 1.
- The program should compile without any warnings when using the `-Wall` gcc option.
