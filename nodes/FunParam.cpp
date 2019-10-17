#include "FunParam.hpp"
#include "utils.hpp"

using namespace cimporter;

FunParam::FunParam(CXCursor cursor)
    : CXBase(cursor)
{
    // Empty
}

void FunParam::SetType(std::shared_ptr<Type> type)
{
    _type = type;
}