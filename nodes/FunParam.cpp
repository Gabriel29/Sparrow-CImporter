#include "FunParam.hpp"
#include "utils.hpp"

using namespace cimporter;

FunParam::FunParam(CXCursor cursor)
    : Decl(cursor)
{
    _name = getCursorName(_cursor);
}

void FunParam::parseDecl()
{
    CXType paramType = clang_getCursorType(_cursor);
    _type = std::make_shared<Type>(paramType);
    _type->parseType();
}

void FunParam::SetType(std::shared_ptr<Type> type)
{
    _type = type;
}