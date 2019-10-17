#include "Decl.hpp"

using namespace cimporter;

Decl::Decl(CXCursor cursor) 
    : CXBase(cursor)
{
    CXCursorKind cursorKind = clang_getCursorKind(cursor);
    switch(cursorKind)
    {
    case CXCursor_TypedefDecl:
        _declType = cimp_TypeDefDecl;
        break;

    case CXCursor_EnumDecl: 
        _declType = cimp_EnumDecl;
        break;

    case CXCursor_StructDecl:
        _declType = cimp_StructDecl;
        break;

    case CXCursor_UnionDecl:
        _declType = cimp_UnionDecl;
        break;

    case CXCursor_FunctionDecl:
        _declType = cimp_FunctionDecl;
        break;
    
    default:
        break;
    }
}

declType Decl::getNodeType() const
{
    return _declType;
}

void Decl::parseDecl()
{
    // if(_declType == cimp_EnumDecl)
    // {
    //     auto decl = std::make_shared<Enum>(_cursor);
    //     decl->parseEnum();
    //     _decl = decl;
    // }
    // else if(_declType == cimp_StructDecl)
    // {
    //     auto decl = std::make_shared<Struct>(_cursor);
    //     decl->parseStruct();
    //     _decl = decl;
    // }
    // else if(_declType == cimp_UnionDecl)
    // {

    // }
    // else if(_declType == cimp_TypeDefDecl)
    // {

    // }
    // else if(_declType == cimp_FunctionDecl)
    // {

    // }
//  auto e = std::make_shared<Enum>(cursor);
//                 e->parseEnum();
//                 auto s = std::make_shared<Struct>(cursor);
//                 s->parseStruct();
//                 File* f = reinterpret_cast<File*>(clientData);
//                 f->addDecl(s);
//                 break;
}

// void* getNode() const
// {
//     return _node;
// }