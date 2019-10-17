#include <iostream>

//#include "cimpAST.hpp"
//#include "dumpSparrow.hpp"
#include "nodes/File.hpp"
#include "DumpSparrow.hpp"

int main(int argc, char** argv)
{
    if (argc < 2 )
    {
        std::cout << "file argument missing!" << std::endl;
        return -1;
    }

    std::string fileName(argv[1]);
    cimporter::File* file = new cimporter::File(fileName);
    file->openFile();
    file->parseDeclarations();

    cimporter::DumpSparrow dumpVisitor;
    file->visit(dumpVisitor);

    // /* dump Sparrow code to screen */
    // cimp::dumpFile(file);

    return 0;
}