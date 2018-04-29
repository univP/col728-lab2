cc: cc.cpp c.tab.cpp c.lex.cpp
	g++ c.tab.cpp c.lex.cpp cc.cpp -std=c++11 -g -lm -ll -lfl `llvm-config --libs core mcjit native --cxxflags --ldflags` -o $@

c.tab.cpp c.tab.hpp: c.y
	bison -o c.tab.cpp -d c.y

c.lex.cpp: c.l c.tab.hpp
	flex -o c.lex.cpp -l c.l

clean::
	rm -f c.tab.cpp c.tab.hpp c.lex.cpp cc c.output output.o semant.tree semant1.tree dout a.out bitcode.bc pass.so cse-pass.o code.bc

code: pass.so bitcode.bc
	opt -load ./pass.so -cse < bitcode.bc > code.bc

pass.so: cse-pass.cpp pass.so
	clang++ -c cse-pass.cpp `llvm-config --libs core mcjit native --cxxflags --ldflags`
	clang++ -shared -o pass.so cse-pass.o `llvm-config --ldflags`