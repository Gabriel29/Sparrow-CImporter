#include "EnumDecl.hpp"
#include <iostream>

using namespace cimporter;

EnumDecl::EnumDecl(CXCursor cursor)
    : CXBase(cursor)
{
    _name = getCursorName(_cursor);
    _value = clang_getEnumConstantDeclValue(_cursor);
}

const long EnumDecl::getValue() const
{
    return _value;
}

