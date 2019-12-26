#include "Typedef.hpp"

using namespace cimporter;

Typedef::Typedef(CXCursor cursor)
    : CXBase (cursor)
{
    _name = getCursorName(cursor);
}

void Typedef::parseTypedef()
{
    CXType type = clang_getCursorType(_cursor);
    _type = std::make_shared<Type>(type);
    _type->parseType();
}
