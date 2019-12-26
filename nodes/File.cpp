#include <vector>
#include <clang-c/Index.h>

#include "File.hpp"
#include "utils.hpp"

using namespace cimporter;

File::File(std::string filePath)
    : _filePath(filePath)
{ }

std::shared_ptr<File> File::getptr() {
    return shared_from_this();
}

void File::openFile()
{
    _index = clang_createIndex(1, 1);

    char **cli_args = new char*[_cliArgs.size()];
    for(int i = 0 ; i < _cliArgs.size(); i++)
        cli_args[i] = (char*) _cliArgs[i].c_str();

    _tu = clang_parseTranslationUnit(
                _index, 
                _filePath.c_str(), 
                cli_args,
                _cliArgs.size(), 
                NULL,
                0, 
                CXTranslationUnit_DetailedPreprocessingRecord
                );

    // currentFile = removeFileExtension(file);
    // currentVal = 0;

    if (_tu == NULL) {
        std::cout << "parseTranslationUnit failed to initiliaze\n";
        throw;
    }

    // Get file cursor
    _cursor = clang_getTranslationUnitCursor(_tu);

    delete[] cli_args;
}

const CXTranslationUnit& File::getTranslationUnit() const
{
    return _tu;
}

const std::vector<std::shared_ptr<Decl>>& File::getDeclList() const
{
    return _declList;
}


void File::addDecl(std::shared_ptr<Decl> decl) {
    _declList.push_back(decl);
}

void File::addCliArg(std::string arg)
{
    _cliArgs.push_back(arg);
}

// const std::vector<std::shared_ptr<Macro>>& File::getMacroList() const
// {
//     return macroList;
// }


// void File::addToMacroList(std::shared_ptr<Macro> node) {
//     macroList.push_back(node);
// }

const std::string& File::getFilePath()
{
    return _filePath;
}

void File::parseMacros()
{

}

void File::visit(ICimpVisitor& visitor)
{
    visitor.visit(*this);
}

void File::parseDeclarations()
{
    /* Parse prep */
    //clang_visitChildren(_cursor, cursorVisitorPrep, this);

    /* Parse decl */
    clang_visitChildren(
        _cursor, 
        [] (CXCursor cursor, CXCursor parent, CXClientData clientData) -> CXChildVisitResult
        {
            CXSourceLocation location = clang_getCursorLocation(cursor);
            
            //auto filePtr = ((File*) clientData)->getptr();

            if( clang_Location_isFromMainFile( location ) == 0 )
            {
                return CXChildVisit_Continue;
            }

            CXCursorKind cursorKind = clang_getCursorKind(cursor);
            File* f = reinterpret_cast<File*>(clientData);

            switch(cursorKind)
            {
            case CXCursor_TypedefDecl:
            {
                auto typedefDecl = std::make_shared<Typedef>(cursor);
                typedefDecl->parseDecl();
                f->addDecl(std::static_pointer_cast<Decl>(typedefDecl));
                break;
            }

            case CXCursor_EnumDecl:
            {
                auto decl = std::make_shared<Enum>(cursor);
                decl->parseDecl();
                f->addDecl(std::static_pointer_cast<Decl>(decl));
                break;
            }

            case CXCursor_StructDecl:
            {
                auto decl = std::make_shared<Struct>(cursor);
                decl->parseDecl();
                f->addDecl(std::static_pointer_cast<Decl>(decl));
                break;
            }

            case CXCursor_UnionDecl:
            {
                auto decl = std::make_shared<Union>(cursor);
                decl->parseDecl();
                f->addDecl(std::static_pointer_cast<Decl>(decl));
                break;
            }

            case CXCursor_FunctionDecl:
            {
                auto fun = std::make_shared<Fun>(cursor);
                fun->parseDecl();
                f->addDecl(std::static_pointer_cast<Decl>(fun));
                break;
            }

            default:
                break;
            // case CXCursor_FieldDecl:
            // {
            //  Struct* s = reinterpret_cast<Struct*>(clientData);
            //  s->addToList(parseStructField(cursor));
            //      break;
            // }


                // File* f = reinterpret_cast<File*>(clientData);
                // f->addToList(new Decl(parseUnion(cursor)));
 
                // obj->addObject(parseFunctionDecl(cursor));
                // File* f = reinterpret_cast<File*>(clientData);
                // f->addToList(new Decl(parseFun(cursor)));


            //case CXCursor_VarDecl:
            //  break;

            // case CXCursor_ParmDecl:
            //  // obj->addObject(parseParmDecl(cursor));
            //  break;

            // case CXCursor_MacroDefinition:
            //  break;

            // case CXCursor_MacroExpansion:
            //  break;

            // /* Parse included files */
            // case CXCursor_InclusionDirective:
            //  break;

 
            }

            return CXChildVisit_Continue;
        }, 
        this
    );
}