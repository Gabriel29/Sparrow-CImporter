CC = clang++
CFLAGS = -I /usr/lib/llvm-6.0/include/ -ggdb3 -O0
CLIBS = -lclang

dumpSparrow: nodes
	$(CC) $(CFLAGS) $(CLIBS) cimporter.cpp File.o Enum.o utils.o EnumDecl.o Type.o Struct.o StructField.o Decl.o Union.o FunParam.o Typedef.o Fun.o FunPtr.o DumpSparrow.cpp -o dumpSparrow.out

nodes:
	$(CC) -c $(CFLAGS) ./nodes/File.cpp ./nodes/Enum.cpp ./nodes/utils.cpp ./nodes/EnumDecl.cpp ./nodes/Type.cpp ./nodes/Struct.cpp ./nodes/StructField.cpp ./nodes/Decl.cpp ./nodes/Union.cpp ./nodes/FunParam.cpp ./nodes/Typedef.cpp ./nodes/Fun.cpp ./nodes/FunPtr.cpp

test: dumpSparrow
	python run_tests.py

clean:
	rm -f *.o dumpSparrow.out testFile.tmp

.PHONY: nodes
