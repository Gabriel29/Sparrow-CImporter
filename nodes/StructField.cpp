#include "StructField.hpp"
#include <vector>

using namespace cimporter;

StructField::StructField(CXCursor cursor)
    : CXBase(cursor)
{
    _name = getCursorName(_cursor);
}

void StructField::SetType(std::shared_ptr<Type> type)
{
    _type = type;
}

void StructField::parseStructField()
{
    CXType fieldType = clang_getCursorType(_cursor);
    _type = std::make_shared<Type>(fieldType);
    _type->parseType();
}
