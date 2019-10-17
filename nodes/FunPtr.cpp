#include "FunPtr.hpp"

using namespace cimporter;

FunPtr::FunPtr(CXCursor cursor)
    : CXBase (cursor)
{
    // Empty
}

const std::vector<std::shared_ptr<FunParam>> FunPtr::getParamList() const {
    return _paramList;
}

const std::shared_ptr<Type> FunPtr::getRetType() const {
    return _retType;
}

void FunPtr::addParameter(std::shared_ptr<FunParam> param)
{
    _paramList.push_back(param);
}
