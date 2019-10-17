#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <memory>

#include "CXBase.hpp"
#include "Enum.hpp"
#include "Struct.hpp"
#include "Union.hpp"

#include "../ICimpVisitor.hpp"
#include "utils.hpp"

namespace cimporter
{

class File : public std::enable_shared_from_this<File>
{	
public:
    File() = delete;
	File(std::string filePath);

	void openFile();
    void parseDeclarations();
    void parseMacros();
	std::shared_ptr<File> getptr();

    const std::string& getFilePath();
	const CXTranslationUnit& getTranslationUnit() const;
	const std::vector<std::shared_ptr<Decl>>& getDeclList() const;
	
    //const std::vector<std::shared_ptr<Macro>>& getMacroList();
	void addDecl(std::shared_ptr<Decl> decl);
    void addCliArg(std::string arg);
	//void addToMacroList(std::shared_ptr<Macro> node);

    void visit(ICimpVisitor& visitor);

private:
    // libclang values
    CXIndex             _index;
    CXTranslationUnit   _tu;
    CXCursor            _cursor;
    
    std::string                         _filePath;
    std::vector<std::string>            _cliArgs;

    std::vector<std::shared_ptr<Decl>>  _declList;
    //std::vector<std::shared_ptr<Macro>> macroList;
};

}