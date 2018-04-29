# cc
C compiler

The C language grammar (c.y and c.l files) have been taken from:

http://www.quut.com/c/ANSI-C-grammar-y-2011.html

Commands:
make clean
make
./cc test/test.c
lli bitcode.bc
clang++ -c cse-pass.cpp `llvm-config --libs core mcjit native --cxxflags --ldflags`
clang++ -shared -o pass.so cse-pass.o `llvm-config --ldflags`
opt -load ./pass.so -cse < bitcode.bc > code.bc
llvm-dis < code.bc | less