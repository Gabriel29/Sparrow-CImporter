#include "Typedef.hpp"

using namespace cimporter;

Typedef::Typedef(CXCursor cursor)
    : CXBase (cursor), _isFunctionPointer(false)
{
    _name = getCursorName(cursor);
}

void Typedef::setFunPtrTrue()
{
    _isFunctionPointer = true;
}

bool Typedef::isFunPtr()
{
    return _isFunctionPointer;
}

void Typedef::addToList(const std::shared_ptr<FunParam> decl)
{
    _paramList.push_back(decl);
}

const std::vector<std::shared_ptr<FunParam>>& Typedef::getParamList() const
{
    return _paramList;
}