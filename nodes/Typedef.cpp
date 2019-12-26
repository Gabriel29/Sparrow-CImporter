#include "Typedef.hpp"

using namespace cimporter;

Typedef::Typedef(CXCursor cursor)
    : Decl (cursor)
{
    _name = getCursorName(cursor);
}

void Typedef::parseDecl()
{
    CXType type = clang_getTypedefDeclUnderlyingType(_cursor);
    _type = std::make_shared<Type>(type);
    _type->parseType();
}
