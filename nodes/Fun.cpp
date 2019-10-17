#include "Fun.hpp"
#include "utils.hpp"

using namespace cimporter;

Fun::Fun(CXCursor cursor)
    : CXBase(cursor)
{
    // Empty
}

const std::vector<std::shared_ptr<FunParam>> Fun::getParamList() const {
    return _paramList;
}

const std::shared_ptr<Type> Fun::getRetType() const {
    return _retType;
}

void Fun::addToList(std::shared_ptr<FunParam> node)
{
    _paramList.push_back(node);
}

void Fun::SetType(std::shared_ptr<Type> retType)
{
    _retType = retType;
}
